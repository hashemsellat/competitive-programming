#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ii pair<int,int>
#define endl '\n'
vector<ii> adj[100000];
void init(){
    for(int i=0;i<100000;i++)
        adj[i].clear();
}
ii dfs(int v,int p){
    int sz=adj[v].size();
    ii ret(0,v);
    for(int i=0;i<sz;i++){
        int nxt=adj[v][i].first;
        int w=adj[v][i].second;
        if(nxt==p)
            continue;
        ii cur=dfs(nxt,v);
        if(cur.first+w>ret.first){
            ret=cur;
            ret.first+=w;
        }
    }
    return ret;
}
main(){
    ios_base::sync_with_stdio(false);
    int x,y,w;
    stringstream ss;
    string line;
    int node;
    bool finished=0;
    while(getline(cin,line)){
        if(line.size()==0){
            ii ans=dfs(node,0);
            ii cur=dfs(ans.second,0);
            finished=1;
            cout<<cur.first<<endl;
            init();
        }
        else{
            finished=0;
            ss.clear();
            ss<<line;
            ss>>x>>y>>w;
            node=x;
            adj[x].push_back(ii(y,w));
            adj[y].push_back(ii(x,w));
        }
    }
    if(!finished){
            ii ans=dfs(node,0);
            ii cur=dfs(ans.second,0);
            finished=1;
            cout<<cur.first<<endl;
    }
}
