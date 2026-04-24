#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll d[64][40][100];
int main( ) {

	int T,kase=0;
	cin>>T;
	while(T--) {
		memset(d,0,sizeof(d));
		int n,k;
		cin>>n>>k;
		if(n&1||k==0) {
			printf("Case %d: 0\n",++kase); 
			continue;
		}
		d[0][n/2][0]=d[0][n/2-1][k-1]=1;
		for(int i=1; i<n-1; i++)for(int c1=0; c1<=min(n/2,n-i-1); c1++)for(int c=0; c<k; c++) {
					d[i][c1][c]=d[i-1][c1+1][(c+(1ull<<i))%k]+d[i-1][c1][c];
				}

		printf("Case %d: %lld\n",++kase,d[n-2][1][(1ll<<(n-1))%k]);
	}
	return 0;
}
