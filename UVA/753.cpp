/*
    simple max flow
    lets first construct the graph:
        let 0 be the super source , we add an edge between it and the given devices with weight 1 (every device should be connected to at most one receptor).
        let 1 be the super sink, we add an edge between it and every plug, with weight 1(we can put just one device in the plug).
        finally we add an edge with infinity weight between the receptor and plug of the given adapters.
    then we find the max flow between the super source and the super sink.
    the answer is the number of edges with weight 1 between the super source and the devices(that indicates that we didn't take that device).
*/
#include<bits/stdc++.h>
#define ii pair<int,int>
#define iii pair<ii,int>
#define endl '\n'
using namespace std;
map<string,int> M;
int cnter;
int findId(string &s)
{
    if(M[s])
        return M[s];
    return M[s]=cnter++;
}
int adj[1000][1000];
bool vis[1000];
bool findPath(int v,int &mn,vector<int> &vec){
    if(vis[v])
        return 0;
    vis[v]=1;
  //  cout<<v<<endl;
   // system("pause");
    vec.push_back(v);
    if(v==1)
        return 1;
    for(int i=0;i<cnter;i++){
        if(adj[v][i]>0){
            mn=min(mn,adj[v][i]);
            if(findPath(i,mn,vec))
                return 1;
        }
    }
    vis[v]=0;
    vec.pop_back();
    return 0;
}
main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    bool is=0;
    while(t--)
    {
        memset(adj,0,sizeof(adj));
        M.clear();
        cnter=2;
        int n;
        cin>>n;
        if(is)
            cout<<endl;
        is=1;
        for(int i=0; i<n; i++)
        {
            string s;
            cin>>s;
            int id=findId(s);
            adj[id][1]=1;
        }
        int m;
        cin>>m;
        vector<int> devices;
        for(int i=0; i<m; i++)
        {
            string l,r;
            cin>>l>>r;
            l+="#";
            int ll=findId(l),
                rr=findId(r);
            adj[ll][rr]=1;
            adj[0][ll]=1;
            devices.push_back(ll);
        }
        int k;
        cin>>k;
        for(int i=0; i<k; i++)
        {
            string l,r;
            cin>>l>>r;
            int ll=findId(l);
            int rr=findId(r);
            adj[ll][rr]=1e9;
        }
        //now we have constructed the graph
        while(1){
            memset(vis,0,sizeof(vis));
            vector<int> v;
            int mn=1e9;
            if(!findPath(0,mn,v))
                break;
            int sz=v.size();
            for(int i=0;i<sz-1;i++){
                adj[v[i]][v[i+1]]-=mn;
                adj[v[i+1]][v[i]]+=mn;
            }
        }
        int ans=0;
        for(auto x:devices){
            if(adj[0][x])
                ans++;
        }
        cout<<ans<<endl;
    }
}
