# Map

key - value를 필요로 할떄,
O(1) input, O(N) space

map은 정렬을 한다.
하지만 unordered_map은 정렬을 하지 않기에, O(1) look up, delete, insert가 가능하다.
머부분의 문제에서는 unordered_map을 사용하는걸 추천한다.

```cpp
#include <iostream>
#include <unordered_map>

int main() {
    map<int, string> map; // map<key, value>, descending in default
    map<int, vector<int>, greater(int)>

    map.insert(pair<int, string>(1, "map1"));
    map[1] = "map1";

    it = map.find(1);
    if ( it == map.end()) // key doesn't exist in map
    
    map.erase(1);
    map.clear();
    map.size();

    for (auto [key, value]: map) {
        // do something
    }
    
    // Multidimensional map
    unordered_map<int, unordered_map<int, string>> map2; // key: <int, int> value: string
    map2[1][2] = "hello";
    
}
```
