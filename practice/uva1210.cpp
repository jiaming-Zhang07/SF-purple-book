#include<bits/stdc++.h>
using namespace std;
using ll=long long;
bool vis[10005];
int sum[10005],d[10005];
int main( ) {
	vector<int>v;
	for(int i=2; i<=10000; i++)if(!vis[i]) {
			v.push_back(i);
			sum[(int)v.size()]=sum[(int)v.size()-1]+i;
			for(int j=i*i; j<=10000; j+=i)vis[j]=true;
		}
	for(int i=0; i<=v.size(); i++)for(int j=i+1; j<=v.size(); j++)if(sum[j]-sum[i]<=10000)d[sum[j]-sum[i]]++;
	int n;while(cin>>n&&n)cout<<d[n]<<"\n";
	return 0;
}
