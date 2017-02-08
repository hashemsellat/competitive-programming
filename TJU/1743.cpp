#include<bits/stdc++.h>
#define int long long int
#define ii pair<int,int>
#define endl '\n'

#define N 300000
using namespace std;
vector<int> ans;
int mn;
vector<int> adj[N],a[N],s[N],pr[N];
int dfs(int v,int p){
    int sz=adj[v].size();
    int ret=0;
    a[v].assign(sz+2,0);
    s[v].assign(sz+2,0);
    pr[v].assign(sz+2,0);
    for(int i=0;i<sz;i++){
        int nxt=adj[v][i];
        if(nxt==p)
            continue;
        int cur=dfs(nxt,v);
        a[v][i+1]=cur;
        ret=max(ret,cur);
    }
    for(int i=1;i<sz+1;i++)
        pr[v][i]=max(a[v][i],pr[v][i-1]);
    for(int i=sz;i>0;i--)
        s[v][i]=max(a[v][i],s[v][i+1]);
    return ret+1;
}
void solve(int v,int prv,int p){
    int sz=adj[v].size();
    int mx=max(prv,max(s[v][1],pr[v][sz+1]));
    //cout<<"Test "<<v<<" "<<mx<<endl;
    if(mx<mn){
        mn=mx;
        ans.clear();
    }
        if(mx==mn)
        ans.push_back(v);

    for(int i=0;i<sz;i++){
        int nxt=adj[v][i];
        if(nxt==p)  continue;
        int cur=i+1;
        int mx=max(prv,max(s[v][cur+1],pr[v][cur-1]));
        solve(nxt,mx+1,v);
    }
}

main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        ans.clear();
        cin>>n;
        for(int i=1;i<=n;i++){
            adj[i].clear();
            pr[i].clear();
            s[i].clear();
            a[i].clear();
        }
        mn=1e9;
        for(int i=2;i<=n;i++){
            int x;cin>>x;
            adj[x].push_back(i);
            adj[i].push_back(x);
        }
        dfs(1,0);
        solve(1,0,0);
        int sz=ans.size();
        sort(ans.begin(),ans.end());
        //cout<<"FOO"<<" "<<mn<<endl;
        for(int i=0;i<sz;i++){
            cout<<ans[i];
            if(i==sz-1) cout<<endl;
            else        cout<<" ";
        }
    }
}
