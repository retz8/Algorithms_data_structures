# <C++/STL> Set

Set은 언제 사용할까
"Unique"한 원소들을 정렬된 채로 저장하고 싶을때
=> distinct element들의 개수를 세고 싶을때
=> 중복된 데이터들을 처리하고 싶을때, Set에 쑤셔넣고 결과를 보면 됨
=> 자동으로 정렬되어있다는 점

### 구현 방식
BST => insert, find, delete: O(logN)
정렬: 오름차순 (less)

### 단점
데이터를 "삽입"할때 느리다.
배열이나 벡터는 걍 뒤에 쑤셔넣으니 O(1)인데, 이건 heap마냥 O(logN)으로 조져줘야한다.
또한 중복된 데이터가 사라진다는 점. 만약 사라지지 않게 하고 싶다면 #include<multiset>을 사용할 것.

### 사용법
```c++
set<int> s;
set.insert(1);

set<int> s2(s);

set<int> s = { 1, 2, 3 };

s.front();
s.back();
s.find(key); // 포인터를 반환, 만약 key가 존재하지 않는다면 s.end()를 반환

s.insert(key);
s.insert(s.find(key), key); // 근데 이래도 어차피 BST라 정렬되고 O(logN)으로 시간 복잡도는 동일
s.emplace(key);
s.erase(key);
s.erase(s.find(key));

s.empty();
s.size();

s.clear();
```