#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll maxn=1ll<<31;
bool vis[1<<16];
int main( ) {
//	vector<int>v;
//	for(ll i=2; i*i<maxn; i++)if(!vis[i]) {
//			v.push_back(i);
//			for(ll j=i*i; j*j<maxn; j*=i)vis[j]=true;
//		}
	ll n;
	while(cin>>n&&n) {bool odd=false;if(n<0){n=-n;odd=true; 
	}bool ok=false;
		for(ll x=2;x*x<=n;x++)if(n%x==0) {
				for(ll j=x,k=1; j<=n; j*=x,k++)if(j==n) {if(odd&&k%2==0)break;
						cout<<k<<"\n";ok=true;
						break;
					}
				if(ok)break;
			}
			if(!ok)cout<<"1\n";
	}
	return 0;
}
