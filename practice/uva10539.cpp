#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=1e6;
const double eps=1e-9;
bool vis[maxn+1];
int main( ) {
	vector<ll>v;
	for(ll i=2; i<=maxn; i++)if(!vis[i]) {
		for(ll t=i*i;t<=(ll)1e12;t*=i)
			v.push_back(t);
			for(ll j=i*i; j<=maxn; j+=i)vis[j]=true;
		}
		sort(v.begin(),v.end());
	int T;
	cin>>T;
	while(T--) {
		ll l,u;
		cin>>l>>u;
	
		
		cout<<upper_bound(v.begin(),v.end(),u)-lower_bound(v.begin(),v.end(),l)<<"\n";
	}
	return 0;
}
