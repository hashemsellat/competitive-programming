#include<bits/stdc++.h>
using namespace std;
#define bset bitset<35>
bset adj[40];
int mn;
bset suffix[100];
int rev[100],n,m,cnter;
bool vis[100];
void getcc(int v,bset &ret)
{
    ret[v]=true;
    rev[cnter]=v;
    cnter++;
    vis[v]=true;
    for(int i=0; i<n; i++)
    {
        if(adj[v][i]&&!ret[i])
            getcc(i,ret);
    }
}
void solve(int i,int cur,bset done,bset &cc)
{
   // cout<<i<<" "<<cur<<" "<<done.to_string()<<endl;
    //cout<<cc.to_string()<<endl;
    if(done==cc)
    {
        mn=min(mn,cur);
        return;
    }
    if(cur==mn)
        return;
    //take it
   // cout<<cur<<" "<<done.to_string()<<endl;
  //  cout<<adj[rev[i]].to_string()<<endl;
  //  cout<<i<<" :D "<<rev[i]<<endl;
    if((done|adj[rev[i]])!=done)
        solve(i+1,cur+1,done|adj[rev[i]],cc);
    //dont take it

    if((done|suffix[i+1])==cc)
        solve(i+1,cur,done,cc);
}
#define endl '\n'
main()
{
    ios_base::sync_with_stdio(false);
   // freopen("out.txt","w",stdout);
    while(cin>>n>>m)
    {
        if(n==0&&m==0)  break;
        for(int i=0; i<n; i++){
            adj[i].reset();
            adj[i][i]=1;
        }
        for(int i=0; i<m; i++)
        {
            int u,v;
            cin>>u>>v;
            u--;
            v--;
            adj[u][v]=1;
            adj[v][u]=1;
        }
        memset(vis,0,sizeof(vis));
        int ans=0;
        for(int i=0; i<n; i++)
        {
            //cout<<adj[i].to_string()<<endl;
            if(!vis[i])
            {
               // cout<<i<<endl;
               // cout<<"HOO "<<i<<endl;
                cnter=0;
                bset cc;
                getcc(i,cc);
                //cout<<cc.to_string()<<endl;
                bset emp;
                suffix[cnter]=emp;
                for(int j=cnter-1; j>=0; j--)
                {
                    suffix[j]=suffix[j+1]|adj[rev[j]];
                    //cout<<j<<" "<<suffix[j]<<endl;
                }
                mn=1e9;
                bset done;
                solve(0,0,done,cc);
                ans+=mn;
            }
        }
        cout<<ans<<endl;
    }
}
