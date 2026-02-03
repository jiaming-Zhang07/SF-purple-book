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
