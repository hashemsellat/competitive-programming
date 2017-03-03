#include<bits/stdc++.h>
using namespace std;
const int N = 1<<17;
const int MXL=18;
int n;
#define ii pair<int,int>
vector<ii> adj[N];
int par[MXL][N],dist[MXL][N],depth[N];
int p(int v,int x,int &ret)
{
    int node=v;
    for(int i=0; i<MXL; i++)
    {
        if(x&(1<<i))
        {
            ret+=dist[i][node];
            node=par[i][node];
         //   cout<<"mewo "<<node<<endl;
        }
    }
    return node;
}
void preCalc(){
    for(int i=1;i<MXL;i++){
        for(int j=0;j<=n;j++){
            par[i][j]=par[i-1][par[i-1][j]];
            dist[i][j]=dist[i-1][par[i-1][j]]+dist[i-1][j];
        }
    }
}
void dfs(int v,int p,int d,int pass)
{
    depth[v]=d;
    int sz=adj[v].size();
    par[0][v]=p;
    dist[0][v]=pass;
    for(int i=0; i<sz; i++)
    {
        int nxt=adj[v][i].first;
        if(nxt==p)
            continue;
        dfs(nxt,v,d+1,adj[v][i].second);
    }
}

int LCA(int x,int y)
{
    if(depth[x]<depth[y])
    {
        swap(x,y);
    }
    int u=x,v=y;
    int ret=0;
    u=p(u,depth[x]-depth[y],ret);
    if(u==v)    return ret;
  //  cout<<u<<" foo "<<v<<" "<<depth[x]-depth[y]<<endl;
 //   cout<<ret<<endl;
    for(int i=MXL-1; i>=0; i--)
    {
        if(par[i][u]==par[i][v])
            continue;
        ret+=dist[i][u];
        ret+=dist[i][v];
        u=par[i][u];
        v=par[i][v];
    }
    ret+=dist[0][u]+dist[0][v];
   // cout<<"test "<<par[0][u]<<endl;
   // cout<<ret<<endl;
    return ret;
}
main()
{
    int q;
    cin>>n;
    for(int i=0; i<n-1; i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        adj[x].push_back(ii(y,w));
        adj[y].push_back(ii(x,w));
    }
    dfs(1,0,0,0);
    preCalc();
    cin>>q;
    while(q--){
        int u,v,s;
        cin>>u>>v>>s;
        int ans=LCA(u,v);
        cout<<ans/s+((ans%s)!=0)<<endl;
    }
    //start building

}
