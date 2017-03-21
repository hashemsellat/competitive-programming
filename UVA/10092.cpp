#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=2000;
int adj[N][N];
bool vis[N];
int nk,np;
bool findPath(int v,int &m,vector<int> &vec){
  if(vis[v])
    return 0;
  vis[v]=1;
  vec.push_back(v);
  if(v==1){
    return 1;
  }
  for(int i=0;i<nk+np+3;i++){
    if(adj[v][i]){
    //  m=min(m,adj[v][i]);
      if(findPath(i,m,vec))
      {
        m=min(m,adj[v][i]);
        return 1;
      }
    }
  }
  vec.pop_back();
  return 0;
}
main(){
  ios_base::sync_with_stdio(false);
  while(cin>>nk>>np){
    if(nk==0&&np==0)
      break;
    vector<std::vector<int> > ans,foo;
    std::vector<int> tmp;
    ans.assign(nk,tmp);
    foo.assign(np+nk+10,tmp);
    memset(adj,0,sizeof(adj));
    for(int i=2;i<nk+2;i++){
      int x;
      cin>>x;
      adj[i][1]=x;
      //cout<<"test "<<i<<" "<<x<<endl;
    }
    for(int i=nk+2;i<nk+2+np;i++){
      //cout<<"here "<<i<<endl;
      //loop over problems
      int nc;
      cin>>nc;
      adj[0][i]=1;
      for(int j=0;j<nc;j++)
      {
        int c;
        cin>>c;
        c++;
        adj[i][c]=1;
        foo[i].push_back(c);
      }
    }
    while(1){
      int mn=1e9;
      memset(vis,0,sizeof(vis));
      vector<int> v;
      if(!findPath(0,mn,v)){
        break;
      }
      int sz=v.size();
      for(int j=0;j<sz-1;j++){
        adj[v[j]][v[j+1]]-=mn;
        adj[v[j+1]][v[j]]+=mn;
      }
    }
    bool answer=1;
    for(int i=2;i<nk+2;i++){
      if(adj[i][1]!=0)
        answer=0;
    }
    for(int i=nk+2;i<nk+np+2;i++){
      for(auto x:foo[i]){
        if(adj[i][x]==0){
          ans[x-2].push_back(i-nk-1);
        }
      }
    }
    if(!answer){
      cout<<0<<endl;
      continue;
    }
    cout<<1<<endl;
    for(int i=0;i<nk;i++){
      for(int j=0;j<int(ans[i].size());j++){
        cout<<ans[i][j];
        if(j!=ans[i].size()-1){
          cout<<" ";
        }
        else
          cout<<endl;
      }
    }
  }
}
