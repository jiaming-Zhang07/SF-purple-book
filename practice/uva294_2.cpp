#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=1e6;
bool vis[maxn+1];
ll temp[100005],cnt[100005];
int main( ) {
	vector<ll>v;
	for(ll i=2; i<=maxn; i++)if(!vis[i]) {
			v.push_back(i);
			for(ll j=i*i; j<=maxn; j+=i)vis[j]=true;
		}
	int T;
	cin>>T;
	while(T--) {
		ll L,U;
		cin>>L>>U;
		for(ll i=L; i<=U; i++)temp[i-L]=i;
		fill(cnt,cnt+U-L+1,1);
		for(ll x:v) {
			if(x>U/x)break;
			for(ll k=(L-1)/x+1; k<=U/x; k++) {
				int idx=k*x-L;
				int c=0;
				ll&t=temp[idx];
				while(t%x==0) {
					c++;
					t/=x;
				}
				cnt[idx]*=c+1;
			}
		}
		ll maxc=-1,ans;
		for(int i=0; i<U-L+1; i++) {
			if(temp[i]>1)cnt[i]*=2;
			if(cnt[i]>maxc) {
				maxc=cnt[i];
				ans=i+L;
			}
		}
		printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n",L,U,ans,maxc);
	}
	return 0;
}
