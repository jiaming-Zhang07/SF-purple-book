#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main( ) {int T;ios::sync_with_stdio(0);cin.tie(0); 
	cin>>T;
	while(T--) {
		int n;
		cin>>n;
		long long res = 0;
		for( int i = 1; i <= n; i=i+1 ) {
			res = (res + n/i);
		}
		cout<<res<<"\n";
	}
	return 0;
}
