#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=sqrt(1e9+0.5);
bool vis[maxn+1];
int main( ) {
	vector<int>v;
	for(ll i=2; i<=maxn; i++)if(!vis[i]) {
			v.push_back(i);
			for(ll j=i*i; j<=maxn; j+=i)vis[j]=true;
		}
	int T;
	cin>>T;
	while(T--) {
		int L,U;
		cin>>L>>U;
		int maxc=-1,ans;
		for(int x=L; x<=U; x++) {
			int c=1;
			int temp=x;
			for(int t:v) {
				if(t*t>temp)break;
				if(temp%t==0) {
					int cnt=0;
					while(temp%t==0) {
						temp/=t;
						cnt++;
					}
					c*=cnt+1;
				}
			
			}
			if(temp>1)c*=2;
			if(c>maxc) {
				maxc=c;
				ans=x;
			}
		}
		printf("Between %d and %d, %d has a maximum of %d divisors.\n",L,U,ans,maxc);
	}
	return 0;
}
