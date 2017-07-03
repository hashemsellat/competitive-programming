#include<bits/stdc++.h>
using namespace std;
#define double long double
main(){
    freopen("kids.in","r",stdin);
    freopen("kids.out","w",stdout);
    double m;
    int n;
    cin>>m>>n;
    double cur=1;
    for(int i=0;i<n;i++){
        cur*=(m-1)/m;
    }
    cout<<fixed<<setprecision(10)<<m*(1-cur)<<endl;
}