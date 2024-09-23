// 가장 기본적인 DFS를 직접 구현해보자
// 난 stack으로 구현할테다

#include <iostream>
#include <stack>
using namespace std;

int main() {
    // graph를 어떤 방식으로 저장하고 있어 V와 E를 표현해
    vector<vector<int>> graph; // graph[1] = 2 :  1 -> 2

    // create a stack
    stack<int> s;
    vector<bool> visited(graph.size(), false);


    // add initial node (starting point of graph search) to the stack
    s.push(1); // assume 1 is a starting node
    visited[1] = true;

    // find path while stack is not empty
    while(!s.empty()) {
        int cur = s.top();
        s.pop();

        visited[cur] = true; // mark current node as visited (when encounter visited node = cycle)

        for (auto& next: graph[cur]){ 
            if (!visited[next]) {
                s.push(next);
            }
        }
    }   

    
    // look up connected node from current node (check edges)
    // add them to the stack

}

