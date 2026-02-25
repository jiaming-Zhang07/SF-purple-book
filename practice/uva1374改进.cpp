#include<bits/stdc++.h>
using namespace std;
int s[13]={1};
int n;
bool dfs(int d, int maxd, int m) {
	if (m == n)
	{
		return true;
	}
	if (*max_element(s,s+d+1)<<(maxd - d) <n ||d==maxd)
		return false;
	for (int i=d;i>=0;i--) {
		
		s[d+1]=s[d]+s[i];
		if (dfs(d + 1, maxd, s[d+1] ))
			return true;
	
		if(s[d]-s[i]<=0)continue;
		s[d+1]=s[d]-s[i];
		if (dfs(d + 1, maxd, s[d+1]))
			return true;
		
	}return false;
}
int main() {
	while (cin >> n && n) {
		int maxd;
		for ( maxd = 0;maxd<13; maxd++)
		{
			if (dfs(0, maxd,1)) break;
		}printf("%d\n",maxd);
	}
}
