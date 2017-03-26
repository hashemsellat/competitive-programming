#include<bits/stdc++.h>
using namespace std;
bool vis[20000];
main(){
  int Z,I,M,L;
  int cnt=0;
  while(cin>>Z>>I>>M>>L){
    if(Z==0&&I==0&&M==0&&L==0)
      break;
    memset(vis,0,sizeof(vis));
    int cur=L;
    int ans=0;
    while(!vis[L]){
      vis[L]=ans;
      L=Z*L+I;
      L%=M;
      ans++;
    }
    cout<<"Case "<<++cnt<<": "<<ans-vis[L]<<endl;
  }

}
