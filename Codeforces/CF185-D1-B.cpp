#include<bits/stdc++.h>
using namespace std;

main(){
  double S;
  cin>>S;
  double a,b,c;
  cin>>a>>b>>c;
  if(a==0&&b==0&&c==0){
    cout<<0<<" "<<0<<" "<<0<<endl;
  }
  else{
    cout<<fixed<<setprecision(10)<<a/(a+b+c)*S<<" "<<b/(a+b+c)*S<<" "<<c/(a+b+c)*S<<endl;
  }
}
