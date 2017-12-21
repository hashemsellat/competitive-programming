#include <iostream>
#include <vector>

using namespace std;
#define ii pair<int,int>
const int MAXN = 1e5+69;

vector<int> adj[MAXN];

bool isLucky(int x){
    while(x){
        //  cout<<x%10<<endl;
        if(x%10!=4&&x%10!=7)
            return 0;
        x/=10;
    }
    return 1;
}
int dp[2][MAXN],cnt[MAXN],vis[MAXN];
int dfs(int v){
    int ret=1;
    vis[v]=1;
    for(auto nxt:adj[v]){
        if(!vis[nxt])
            ret+=dfs(nxt);
    }
    return ret;
}
const int INF=1e9;
main(){
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            int foo = dfs(i);
            cnt[foo]++;
        }
    }
    vector<ii>v;
    for(int i=1;i<MAXN;i++){
        if(cnt[i]){
            int now=1;
            while(now<=cnt[i]){
                v.push_back(ii(i,now));
                now*=2;
            }
        }
    }
    int curj=0;
    for(int j=v.size();j>=0;j--){
        int nxtj=curj;
        curj^=1;
        for(int l=0;l<=77777;l++){
            if(j==v.size()){
                if(l==0)
                    dp[curj][l]=0;
                else
                    dp[curj][l]=INF;
            }
            else{
                dp[curj][l]=dp[nxtj][l];
                if(l-v[j].second*v[j].first>=0) {
                    dp[curj][l] = min(dp[nxtj][l],v[j].second+dp[nxtj][l - v[j].second * v[j].first]);
                    int test = 1;
                }
            }
        }
    }
    int ans=INF;
    for(int i=4;i<=77777;i++){
        if(!isLucky(i))
            continue;
        if(dp[curj][i]!=INF){
            ans=min(ans,dp[curj][i]);
        }
    }

    if(ans==INF)    ans=0;
    cout<<ans-1<<endl;

    return 0;
}