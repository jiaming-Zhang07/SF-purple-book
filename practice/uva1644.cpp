#include<bits/stdc++.h>
using namespace std;
using ll=long long;
bool vis[2000000];
void init() {

	for(ll i=2; i<=1299709; i++)if(!vis[i])for(ll j=i*i; j<=1299709; j+=i)vis[j]=true;
};
int main( ) {
	init();
	int n;
	while(cin>>n&&n) {
		if(!vis[n])cout<<0<<"\n";
		else {
			int t=n,t1=n;
			while(vis[t])t++;
			while(vis[t1])t1--;
			cout<<t-t1<<"\n";
		}
	}
	return 0;
}
