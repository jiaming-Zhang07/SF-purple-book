#include<set>
#include<iostream>
#include<string>
#include<map>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
typedef set<int> Set;
map<Set, int>IDsorts;
vector<Set>setsorts;
#define All(x) x.begin(),x.end()
#define Ins(x) inserter(x,x.begin())
int ID(Set x) {
	if (IDsorts.count(x))return IDsorts[x];
	setsorts.push_back(x);
	return IDsorts[x] = setsorts.size() - 1;
}
int main() {
	stack<int> st;
	string s;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s[0] == 'P')st.push(ID(Set()));
		else if (s[0] == 'D') {
			st.push(st.top());
		} else {
			Set x1 = setsorts[st.top()];
			st.pop();
			Set x2 = setsorts[st.top()];
			st.pop();
			Set x;
			if(s[0]=='U')set_union(All(x1),All(x2),Ins(x));
			if(s[0]=='I')set_intersection(All(x1),All(x2),Ins(x));
			if(s[0]=='A'){x=x2;x.insert(ID(x1));}
			st.push(ID(x));
		}
		cout<<setsorts[st.top()].size()<<"\n";
	}
}

