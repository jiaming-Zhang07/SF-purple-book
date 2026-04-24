#include<bits/stdc++.h>
using namespace std;
using ll=long long;
double p[50001];
int main( ) {
	int T;
	cin>>T;
	p[1]=1;
	for(int i=2; i<=50000; i++)p[i]=p[i-1]*(2.0*i-3)/(2.0*i-2);
	while(T--) {
		int n;
		cin>>n;
		n/=2;
		cout<<fixed<<setprecision(4)<<1-p[n]<<"\n";
	}
	return 0;
}
