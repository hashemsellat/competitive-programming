#include<bits/stdc++.h>
using namespace std;
#define int long long int
int fi(int n){
    int result=n;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            result-=(result/i);
            while(n%i==0)
                n/=i;
        }
    }
    if(n>1)
        result-=result/n;
    return result;
}
int sm[100000];
main(){
  int t;
  cin>>t;
  for(int j=1;j<=10000;j++){
    sm[j]=sm[j-1]+fi(j);
  }
  while(t--){
    int n;
    cin>>n;
    cout<<sm[n]*sm[n]<<endl;
  }
}
