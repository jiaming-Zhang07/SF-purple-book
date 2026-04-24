#include<bits/stdc++.h>
using namespace std;
using ll=long long;
bool vis[1150];
int d[1150][15];
int main( ) {
	vector<int>v;
	for(int i=2; i<= 1120 ; i++)if(!vis[i]) {
			v.push_back(i);
			for(int j=i*i; j<=1120; j+=i)vis[j]=true;
		}
	d[0][0]=1;
	for(int i=0; i<v.size(); i++) {
		int x=v[i];
		for(int j=1120-x; j>=0; j--)for(int k=1; k<=min(i+1,14); k++)d[j+x][k]+=d[j][k-1];
	}
	int n,k;
	while(cin>>n>>k&&n)cout<<d[n][k]<<"\n";
	return 0;
}
