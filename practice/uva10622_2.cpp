#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main( ) {
	ll n;
	while(cin>>n&&n) {
		bool odd=false,ok=false ;
		if(n<0) {
			odd=true;
			n=-n;
		}
		for(int p=60; p>=2; p--) {
			if(odd&&p%2==0)continue;
			ll l=2,r=1e9;
			while(l<=r) {
				ll mid=l+(r-l)/2;
				__int128_t a=1;
				for(int i=0; i<p; i++) {
					a*=mid;
					if(a>n) {
						r=mid-1;
						break;
					}
				}
				if(a==n){cout<<p<<"\n";ok=true;break;
				}else if(a<n)l=mid+1;
			}
			if(ok)break;
		}if(!ok)
		cout<<"1\n";
	}
	return 0;
}
