#include<bits/stdc++.h>
using namespace std;
//#define double long double
#define int long long int
#define ii pair<int,int>
#define iii pair<int,ii>
#define endl '\n'
#define vi vector<int>
struct DSU{
    vi p,r;
    DSU(int n){
        p.assign(n,0);
        r.assign(n,0);
        for(int i=0;i<n;i++)
            p[i]=i;
    }
    int findSet(int u){
        if(p[u]==u) return u;
        return p[u]=findSet(p[u]);
    }
    void merge_(int u,int v){
        int x=findSet(u),
            y=findSet(v);
        if(x==y)    return;
        if(r[x]==r[y])
            r[x]++;
        if(r[x]<r[y])
            p[x]=y;
        else
            p[y]=x;
    }
};
main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n,m,k;cin>>n>>m>>k;
        DSU a(n+10);
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            a.merge_(u,v);
        }
        vector<iii> edges;
        for(int i=0;i<k;i++){
            int u,v,w;
            cin>>u>>v>>w;
            edges.push_back(iii(w,ii(u,v)));
        }
        sort(edges.begin(),edges.end());
        int ans=0;
        for(int i=0;i<k;i++){
            int w=edges[i].first,
                u=edges[i].second.first,
                v=edges[i].second.second;
            if(a.findSet(u)!=a.findSet(v)){
                ans+=w;
                a.merge_(u,v);
            }
        }
        int mstra=a.findSet(1);
        bool is=1;
        for(int i=1;i<=n;i++){
            if(a.findSet(i)!=mstra){
                is=0;
            }
        }
        if(!is)
            cout<<-1<<endl;
        else
            cout<<ans<<endl;
    }
}
