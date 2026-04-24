#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main( ) {
	int n;
	while(cin>>n&&n) {
		double x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		if(x2*y1>x1*y2) {
			swap(x1,x2);
			swap(y1,y2);
		}
		double ans=0,l=0;
		for(int i=0; i<n; i++) {
			double t;
			cin>>t;
			ans-=t*t;
			l+=t;
		}
		l*=sqrt(2);
		ans/=2;
		ans+=l*l*(x1+y1)*(x2+y2)/(x1*y2-x2*y1)/4;
		printf("%.3f\n",ans);

	}
	return 0;
}
