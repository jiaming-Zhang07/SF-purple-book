vector初始化方式：
```cpp
vector<int> v(n); // 创建一个长度为 n 的 vector，所有元素初始化为 0
vector<int> v(n, -1); // 长度为 n，所有元素初始化为 -1
vector<int> v = {1, 2, 3, 4, 5};
// 或者
vector<int> v{1, 2, 3, 4, 5};
int a[] = {10, 20, 30};
vector<int> v(a, a + 3); // 传入 [first, last) 指针范围
vector<int> v2(v1); // v2 是 v1 的一个深拷贝
// 外部 vector 长度为 n，每个内部 vector 长度为 m
vector<vector<int>> matrix(n, vector<int>(m, 0));
vector<int> adj[maxn]; // 这种写法最常用！开一个 maxn 长度的静态数组，每个位置是动态 vector
```
vector常用操作注意事项：
```cpp
for (int i = h + 1; i < (int)pile[p].size(); i++)//size()是无符号型，会警告，先强转
```
