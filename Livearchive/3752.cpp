/*
  we greedyly start from the left of the string, if we reached an unmarked position we put it in
  a new container and iterate over all characters on its left one by one trying to put it int that container
*/
#include "bits/stdc++.h"
using namespace std;
int vis[1000];
#define endl '\n'
main() {
  string s;
  int c = 0;
  ios_base::sync_with_stdio("false");
  while (cin >> s) {
    memset(vis,0,sizeof(vis));
    if (s == "end")
      break;
    int sz = s.size();
    int ans=0;
    for(int i=0;i<sz;i++){
      if(!vis[i]){
        ans++;
        char cur =s[i];
        for(int j=i;j<sz;j++){
          if(s[j]<=cur&&!vis[j])
          {
            cur=s[j];
            vis[j]=1;
          }
        }
      }
    }
    cout << "Case " << ++c << ": " << ans << endl;
  }
}
