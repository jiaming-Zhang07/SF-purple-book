#include<bits/stdc++.h>
using namespace std;
using ll=long long;
struct bigint {
	vector<int>v;
	static const int base=1e9;
	bigint& operator*=(ll a) {
		ll c=0;
		for(int i=0; i<v.size()||c; i++) {
			if(i==v.size())v.push_back(0);
			ll temp=v[i]*a+c;
			c=temp/base;
			v[i]=temp%base;
		}
		return *this;
	}
	void operator-=(ll a) {
		for(int i=0; i<v.size(); i++) {
			if(v[i]<a) {
				v[i]+=base;
				v[i+1]--;
			}
			v[i]-=a;
			a=0;
		}
		while(v.size()>1&&v.back()==0)v.pop_back();
	}
	void operator+=(ll a) {
		for(int i=0; i<v.size()||a; i++) {if(i==v.size())v.push_back(0);
			ll val=v[i]+a;
			a=val/base;
			v[i]=val%base;
		}
	}
	bigint&operator/=(ll a) {
		ll c=0;
		for(int i=(int)v.size()-1; i>=0; i--) {
			ll val=c*base+v[i];
			c=val%a;
			v[i]=val/a;
		}
		while(v.size()>1&&v.back()==0)v.pop_back();
		return *this;
	}
	void print() {
		cout<<v.back();
		for(int i=(int)v.size()-2; i>=0; i--)printf("%09d",v[i]);
		printf("\n");
	}
};
int main( ) {
	int n;
	while(cin>>n) {bigint res;
		res.v.push_back(1);
		int m=n;
		while(m>=30) {
			res*=1ll<<30;
			m-=30;
		}
		res*=1ll<<m;
		if(n%2==0)res+=2;
		else res-=2;
		res/=6;
		res.print();
	}
	return 0;
}
