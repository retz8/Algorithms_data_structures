# Priority Queue

삽입과 삭제 모두 O(logN)을 보장한다, heap으로 구현했을 때

#include <queue>

pq.push()
pq.pop()
pq.top()
pq.empty()
pq.emplace() // object를 넣을때, 단순 변수 하나가 아니라

```cpp
priority_queue<pair<char, int>> pq; // default: 내림차순 정렬, max heap

pq.push(pair<char, int>('a', 2));
pq.emplace('a', 2);

priority_queue<int, vector<int>, greater<int>> pq; // 오름차순 정렬을 원할때


struct compare {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    }
};

priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
```


