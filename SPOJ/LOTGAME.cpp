#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll A,B,C;
ll ab[40],bb[40],cb[40];
int cnt=1;
void to_binary(ll x,ll v[40]){
    ll id=39;
    while(x){
        v[id]=x%2;
        x/=2;
        id--;
    }
}
ll dp[40][2][2][2];
int vis[40][2][2][2];
ll f(ll i,bool isFullA,bool isFullB,bool isFullC){
    if(i==40)
        return 1;
    //الاول اقل من A
    //التاني اقل من B
    //الor اقل من k
    if(vis[i][isFullA][isFullB][isFullC]==cnt)
        return dp[i][isFullA][isFullB][isFullC];
    vis[i][isFullA][isFullB][isFullC]=cnt;
    bool FA=0,FB=0,FC=0;
    ll ret=0;
    for(ll x=0;x<2;x++){
        if(isFullA)
            if(x==1&&ab[i]==0)  continue;
        FA=(isFullA&&x==ab[i]);
        for(ll y=0;y<2;y++){
            if(isFullB)
                if(y==1&&bb[i]==0)  continue;
            FB=(isFullB&&y==bb[i]);

            if(isFullC)
                if(x&y==1&&cb[i]==0)    continue;
            FC=(isFullC&&(x&y)==cb[i]);
            ret+=f(i+1,FA,FB,FC);
        }
    }
    return dp[i][isFullA][isFullB][isFullC]=ret;
}
int main(){
    int t;
    scanf("%d",&t);
    for(cnt=1;cnt<=t;cnt++){
        scanf("%d%d%d",&A,&B,&C);
        A--;B--;C--;
        memset(ab,0,sizeof(ab));
        memset(bb,0,sizeof(bb));
        memset(cb,0,sizeof(cb));
        to_binary(A,ab);
        to_binary(B,bb);
        to_binary(C,cb);
        printf("Case #%d: %lld\n",cnt,f(0,1,1,1));
    }
}
