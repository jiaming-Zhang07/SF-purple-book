#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
unsigned long long seed;
long double gen()
{
static const long double Z = ( long double )1.0 / (1LL<<32);
seed >>= 16;
seed &= ( 1ULL << 32 ) - 1;
seed *= seed;
return seed * Z;
}
int main( )
{int T,kase=0;cin>>T;while(T--){int n;cin>>n>>seed;unsigned long long see=seed;
long double sum=0;
for(int i=0;i<n;i++)sum+=gen();
sum/=n;
seed=see;
long double sum2=0;
for(int i=0;i<n;i++){long double t=gen();
sum2+=(t-sum)*(t-sum);
}
printf("Case #%d: %.5Lf\n",++kase,sqrt(sum2/n));
}
    return 0;
}
