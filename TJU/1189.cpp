#include<bits/stdc++.h>
using namespace std;
#define int long long int
bool is[20][20];
#define ii pair<int,int>
ii dp[15][15][1<<14];
bool vis[15][15][1<<14];
int v[20],n;
ii f(int i,int j,int mask){
 //   cout<<i<<" "<<j<<endl;
    if(vis[i][j][mask]){
        return dp[i][j][mask];
    }
    if(__builtin_popcount(mask)==n){
        return ii(0,1);
    }
    ii ret(0,0);
    vis[i][j][mask]=1;
    for(int k=0;k<n;k++){
        int cur=k+1;
        if((!(mask&(1<<k))&&is[j][cur])||j==0){
            ii now=f(j,cur,mask|(1<<k));
            if(now.second==0)
                continue;
            now.first+=v[cur]*v[j];
            if(is[cur][i]){
                now.first+=v[cur]*v[i]*v[j];
            }
            if(now.first>ret.first){
                ret=now;
            }
            else{
                if(now.first==ret.first)
                    ret.second+=now.second;
            }
        }
    }
    return dp[i][j][mask]=ret;

}
#define endl '\n'
main(){
    int q;
    ios_base::sync_with_stdio(false);
    cin>>q;
    while(q--){
        memset(is,0,sizeof(is));
        memset(vis,0,sizeof(vis));
        int m;
        cin>>n>>m;
        int sm=0;
        for(int i=1;i<=n;i++){
            cin>>v[i];
            sm+=v[i];
        }
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
           // x--;y--;
            is[x][y]=is[y][x]=1;
        }
        ii ans=f(0,0,0);
        if(ans.second!=0)
            cout<<ans.first+sm<<" "<<ans.second/2+(ans.second==1)<<endl;
        else
            cout<<0<<" "<<0<<endl;
    }
}
