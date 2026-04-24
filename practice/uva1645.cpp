#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int mod=1e9+7;
ll d[1001];
int main( ) {

	d[1]=1;
	for(int k=2; k<=1000; k++)for(int i=1; i*i<=k-1; i++)
			if((k-1)%i==0) {
				d[k]=(d[k]+d[(k-1)/i])%mod;
				if(i*i!=k-1)d[k]=(d[k]+d[i])%mod;
			}
	int n,kase=0;
	while(cin>>n)printf("Case %d: %lld\n",++kase,d[n]);
	return 0;
}
