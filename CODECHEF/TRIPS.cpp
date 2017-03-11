#include<bits/stdc++.h>
#define ii pair<int,int>
#define iii pair<ii,int>
#define endl '\n'
using namespace std;
const int N = 1<<18;
const int MXL=18;
vector<ii> adj[N];
int par[MXL][N],dist[N],depth[N],n,pp[MXL][N];
void dfs(int x , int p)
{
    for(auto pp : adj[x])
    {
        int nxt = pp.first;
        if(nxt == p) continue;
        par[0][nxt] = x;
        dist[nxt] = dist[x] + pp.second;
        depth[nxt] = 1 + depth[x];
        dfs(nxt , x);
    }
}
void precalc()
{
    for(int j=1; j<MXL; j++)
        for(int i=1; i<=n; i++)
            par[j][i] = par[j-1][par[j-1][i]];
}
int Kth(int x , int K)
{
    for(int j=0; j<MXL; j++)
        if( (K&(1<<j)))
            x = par[j][x];
    return x;
}
int LCA(int a , int b)
{
    if(depth[a] > depth[b]) swap(a,b);
    b = Kth(b , depth[b] - depth[a]);
    if(a==b) return a;
    for(int j=MXL-1; j>=0; j--)
        if(par[j][a] != par[j][b])
            a = par[j][a] , b = par[j][b];
    return par[0][a];
}
int jumb(int u,int s)
{
    int cur=u;
    for(int i=MXL-1; i>=0; i--)
    {
        if(dist[u]-dist[par[i][cur]]>s)
            continue;
        cur=par[i][cur];
    }
    return cur;
}
int getMin(int u,int v,int s)
{
    int w=LCA(u,v);
    int ret=0;
    int cur=u;
    int baki=0;
    while(1)
    {
        if(dist[cur]-dist[w]<s)//still need a step
        {
            baki=dist[cur]-dist[w];
            break;
        }
        cur=jumb(cur,s);
        ret++;
    }

    cur=v;
    while(1)
    {
        if(dist[cur]-dist[w]<s)//still need a step
        {
            baki+=dist[cur]-dist[w];
            break;
        }
        cur=jumb(cur,s);
        ret++;
    }
    //cout<<"test "<<ret<<" "<<baki/s<<" "<<(baki%s)<<endl;
    return ret+(baki)/s+((baki%s)!=0);

}
ii foo(int u,int w)
{
    int cnt=0;
    for(int i=MXL-1; i>=0; i--)
    {
        int tmp=pp[i][u];
        if(depth[tmp]>depth[w])
        {
            // cout<<"test "<<tmp<<" "<<w<<endl;
            u=tmp;
            cnt+=(1<<i);
        }
    }
    return ii(cnt,dist[u]-dist[w]);
}
int ans[N];
vector<iii> vec[10000];
main()
{
    ios_base::sync_with_stdio(false);
    int q;
    cin>>n;
    for(int i=0; i<n-1; i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        adj[x].push_back(ii(y,w));
        adj[y].push_back(ii(x,w));
    }
    dfs(1,0);
    precalc();
    cin>>q;
    for(int i=0; i<q; i++)
    {
        int u,v,s;
        cin>>u>>v>>s;
        if(s>=sqrt(n))
        {
            ans[i]=getMin(u,v,s);
            //cout<<i<<" foo "<<endl;
        }
        else
        {
            vec[s].push_back(iii(ii(u,v),i));
        }
    }
    for(int l=2; l<sqrt(n); l++)
    {
        if(vec[l].size())
        {
            for(int j=1; j<=n; j++)
            {
                pp[0][j]=jumb(j,l);
                //  cout<<"dsf "<<j<<" "<<pp[0][j]<<endl;
            }
            for(int j=1; j<MXL; j++)
            {
                for(int k=1; k<=n; k++)
                {
                    pp[j][k]=pp[j-1][pp[j-1][k]];
                }
            }
            int szz=vec[l].size();
            for(int i=0; i<szz; i++)
            {
                int u=vec[l][i].first.first,
                    v=vec[l][i].first.second,
                    id=vec[l][i].second;
                int w=LCA(u,v);
                ii fst=foo(u,w);
                ii scd=foo(v,w);
                //    cout<<"........"<<endl;
                //   cout<<id<<endl;
                //  cout<<fst.first<<" "<<fst.second<<endl;
                //  cout<<scd.first<<" "<<scd.second<<endl;
                //  cout<<"........"<<endl;
                ans[id]=fst.first+scd.first+(fst.second+scd.second)/l+((((fst.second+scd.second)%l))!=0);
            }
        }
    }
    for(int i=0; i<q; i++)
    {
        cout<<ans[i]<<endl;
    }

}
