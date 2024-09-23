#include <vector>
#include <unordered_map>
#include <iostream>
#include <queue>
using namespace std;
struct Node {
    std::vector<Node*> next;
};
struct FlowEdge {
        Node* from;
        Node* to;
        int capacity;
        int flow;

        int rem_capacity() {
            return capacity - flow;
        }
    };
class Graph {
private:
    vector<Node*> get_augmenting_path(
        unordered_map<Node*, unordered_map<Node*, FlowEdge>>& flow_edges
    ) {
        // finding augmenting path from source to sink using BFS
        // should return a vector of FlowEdges that store single augmenting path

        queue<Node *> next_nodes; // next nodes for BFS 
        next_nodes.push(source); // starting node

        unordered_map<Node*, Node*> node_from; // node_from[node 1] = node 2 => node 2 -> node 1으로 왔다

        while(!next_nodes.empty()) {
            Node* cur = next_nodes.front();
            next_nodes.pop();

            for (auto& [next, flow_edge]: flow_edges[cur]) {
                // check if it is already seen = node_from에 next가 존재한다? 이미 어떤 노드에서 방문을 한 것
                if (node_from.find(next) != node_from.end()) {
                    continue;
                }
                

                // check remaining capacity (if less than or equal to zero, we pass)
                if (flow_edge.rem_capacity() <= 0) continue;

                // check connected nodes (next)
                next_nodes.push(next);
                node_from[next] = cur;

                if (next == sink) {
                    break; // found a path in next_nodes, backtrack
                }
            }
        }

        // sink never reached
        if (node_from.find(sink) == node_from.end()) {
            return {};
        }
        
        // reconstruct path
        vector<Node*> path;

        Node* cur = sink;
        // node_from[cur]로 그 전껄 추적할 수 있음
        while(cur) {
            path.push_back(cur); 
            cur = node_from[cur];
        }

        // 거꾸로 돌려야 (역순이니까)
        reverse(path.begin(), path.end());
        return path;
    }

}
