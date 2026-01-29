1.判断一个字符串中某个单词能否通过字母重排得到另外一个单词:
思路：将单词标准化，即把字母排序
代码实现：
```cpp
string repr(const string& s){string ans=s;sort(ans.begin(),ans.end());returnn ans;}//用函数可以保证不改变原单词内容，题目一般要求输出满足条件的单词
map<string,int>cnt;
while(cin>>s){string r=repr(s);if(!cnt.count(r))cnt[r]=0;cnt[r]++;}//这样就把该标准化单词的出现次数记录下来了，如果大于1，则能重排得到另外一个单词
```
例题uva10815:
```cpp
例题uva10815:
#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
map<string, int>cnt;
vector<string>words;
string repr(const string&s) {
	string t = s;
	for (int i = 0; i < (int)t.size(); i++)t[i] = tolower(t[i]);
	sort(t.begin(), t.end());
	return t;
}
int main() {
	string s;
	while (cin >> s && s[0] != '#') {
		words.push_back(s);
		cnt[repr(s)]++;
	}
	sort(words.begin(), words.end());
	for (int i = 0; i < (int)words.size(); i++)if (cnt[repr(words[i])] == 1)cout << words[i] << "\n";
	return 0;
}
```
