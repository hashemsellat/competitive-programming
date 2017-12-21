#include<bits/stdc++.h>
using namespace std;
#define  ii pair<int,int>
#define int long long int
int n,m;
const int MAXN = 1e5+100;
int dx[MAXN],dn=1;
vector<int> adj[MAXN],foo[MAXN];
ii interval[MAXN];
int num[MAXN];
void dfs(int v,int p){
    dx[v]=dn++;
    for(auto nxt:adj[v]){
        if(nxt!=p)
            dfs(nxt,v);
    }
    interval[v]=ii(dx[v],dn-1);
    return ;
}
struct  node{
    int c,m;
    node(){
        c=m=0;
    }
    node(int x,int y){
        m=x;c=y;
    }
};
node operator +(const node &a,const node&b){
    if(a.m<b.m)
        return a;
    if(b.m<a.m)
        return b;
    return node(a.m,a.c+b.c);
}
int lazy[3*MAXN];
node tree[3*MAXN];
void build(int v,int l,int r){
    if(l==r){
        tree[v]=node(0,1);
        return;
    }
    int md=(l+r)/2;
    build(2*v,l,md);
    build(2*v+1,md+1,r);

    tree[v]=node(0,r-l+1);

}
void update(int node,int l,int r,int i,int j,int x){
    if(l>r)
        return;
    if(lazy[node]){
        tree[node].m+=lazy[node];
        if(l!=r){
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(l>j||r<i)
        return;
    if(l>=i&&r<=j){
        tree[node].m+=x;
        if(l!=r){
            lazy[2*node]+=x;
            lazy[2*node+1]+=x;
        }
        return;
    }
    int md=(l+r)/2;
    update(2*node,l,md,i,j,x);
    update(2*node+1,md+1,r,i,j,x);
    tree[node]=tree[2*node]+tree[2*node+1];
}
int ans[MAXN];
void solve(int v,int p){
    if(foo[v].size()){
        update(1,1,n,interval[v].first,interval[v].second,1);
    }
    for(auto u:foo[v]){
        update(1,1,n,interval[u].first,interval[u].second,1);
    }
    node cur = tree[1];
   // cout<<v<<" "<<cur.m<<" "<<cur.c<<endl;
    if(cur.m==0)
        ans[v]=(n-cur.c);
    else
        ans[v]=n;
    if(ans[v])
        ans[v]--;
    for(auto nxt:adj[v]){
        if(nxt!=p)
            solve(nxt,v);
    }
    if(foo[v].size()){
        update(1,1,n,interval[v].first,interval[v].second,-1);
    }
    for(auto u:foo[v]){
        update(1,1,n,interval[u].first,interval[u].second,-1);
    }
}
main(){
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    build(1,1,n);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        foo[u].push_back(v);
        foo[v].push_back(u);
    }
    solve(1,0);
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}