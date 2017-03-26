#include<bits/stdc++.h>
using namespace std;
vector<int> cur(7,0);
main(){
  int n;
  while(cin>>n){
    if(n==0)  break;
    for(int i=1;i<=6;i++)
      cur[i]=i;
    for(int i=0;i<n;i++){
      string s;
      cin>>s;
      vector<int> tmp(7,0);
      if(s=="north"){

        tmp[2]=cur[1];
        tmp[6]=cur[2];
        tmp[3]=cur[3];
        tmp[4]=cur[4];
        tmp[5]=cur[6];
        tmp[1]=cur[5];
      }
      if(s=="south"){
        tmp[5]=cur[1];
        tmp[1]=cur[2];
        tmp[3]=cur[3];
        tmp[4]=cur[4];
        tmp[6]=cur[5];
        tmp[2]=cur[6];
      }
      if(s=="east"){
        tmp[4]=cur[1];
        tmp[2]=cur[2];
        tmp[1]=cur[3];
        tmp[6]=cur[4];
        tmp[5]=cur[5];
        tmp[3]=cur[6];
      }
      if(s=="west"){
        tmp[3]=cur[1];
        tmp[2]=cur[2];
        tmp[6]=cur[3];
        tmp[1]=cur[4];
        tmp[5]=cur[5];
        tmp[4]=cur[6];
      }
      cur=tmp;
    }
    cout<<cur[1]<<endl;
  }
}
