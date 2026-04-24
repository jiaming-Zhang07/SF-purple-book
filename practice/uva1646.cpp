#include<bits/stdc++.h>
using namespace std;
using ll=long long;
struct bigint {
	vector<ll>v;
	static const int base=1e9;
	bigint operator+(const bigint&b) {
		bigint res;
		res.v.resize(max(v.size(),b.v.size())+1);
		ll c=0;
		for(int i=0; i<v.size()||i<b.v.size()||c; i++) {
			ll val=(i>=v.size()?0:v[i])+(i>=b.v.size()?0:b.v[i])+c;
			res.v[i]=val%base;
			c=val/base;
		}
		while(res.v.size()>1&&res.v.back()==0)res.v.pop_back();
		return res;
	}
	void output() {
		printf("%lld",v.back());
		for(int i=(int)v.size()-2; i>=0; i--)printf("%09lld",v[i]);
		printf("\n");
	}
} g[10005];
int main( ) {
	g[3].v= {4};
	g[4].v= {7};
	for(int i=5; i<=10000; i++) {
		
		g[i]=g[i-1]+g[i-2];
	}
	int n;
	while(cin>>n)g[n].output();
	return 0;
}
