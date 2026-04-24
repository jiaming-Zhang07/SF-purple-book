#include<iostream>
using namespace std;
using ll=long long;
int main( ) {
	int T;
	cin>>T;
	int n;
	while(T--) {
		cin>>n;
		ll l=1,res=0;
		if (n <= 0) { cout << 0 << "\n"; continue; }
		while(l<=n) {
			int k=n/l;
			int r=n/k;
			if(r>n)r=n;
			res+=(r-l+1)*k;
			l=r+1;
		}
		cout<<res<<"\n";
	}
	return 0;
}
