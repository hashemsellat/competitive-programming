#include<bits/stdc++.h>
using namespace std;
const double PI=2*acos(0);

main(){
  double r,n;
  while(cin>>r>>n){
    double x=(180-360/n)/2;
  //  cout<<x<<endl;
    x*=PI/180;

    double base=2*r*cos(x);
    double h=r*sin(x);
  //  cout<<base <<" "<<h<<endl;
    cout<<fixed<<setprecision(3)<<n*(1.0/2*base*h)<<endl;
  }
}
