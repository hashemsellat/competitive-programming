#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
char s[1000010];
//string s;
#define ll int
ll dp[1000010][3][3][2],sz,m;
bool vis[1000010][3][3][2];
inline ll f(ll i,ll prv,ll LLPP,bool isFull){
   // cout<<i<<" "<<prv<<" "<<LLPP<<" "<<isFull<<endl;
   // cout<<i<<" "<<prv<<" "<<LLPP<<" "<<isFull<<endl;
    if(i>=sz)
        return 1;
    if(prv>2||LLPP>2||prv<0||LLPP<0)   return 0;
    if(vis[i][prv][LLPP][isFull])
        return dp[i][prv][LLPP][isFull];
    vis[i][prv][LLPP][isFull]=1;
    ll ret=0;
    //ßÇä ÞÈáæ P
    if(prv!=0){
        //1 is P , 0 is L
        //add  single L
        bool F=0;
        if(isFull)
            F=(s[i]=='L');
        ret+=f(i+1,0,LLPP,F);

        //add LL
        if(i<sz-1&&LLPP!=0){
            F=0;
            if(isFull){
                if(s[i]==s[i+1]&&s[i]=='L')
                    F=1;
                else
                    F=0;
            }
            ret+=f(i+2,0,0,F);
        }
    }
    if(prv!=1){
        //add P
        if(!isFull||(isFull&&s[i]=='P')){
            ret+=f(i+1,1,LLPP,isFull);
            if(i<sz-1&&LLPP!=1){
                    if(isFull){
                        if(s[i]=='P'&&s[i+1]=='P')
                            ret+=f(i+2,1,1,isFull);
                    }
                    else
                        ret+=f(i+2,1,1,0);
            }
        }
    }
    ret%=m;
    return dp[i][prv][LLPP][isFull]=ret;
}

int main(){
  //  ios_base::sync_with_stdio(false);
 //   freopen("in.txt","r",stdin);
    scanf("%d%d%s",&sz,&m,s);
 //   memset(dp,-1,sizeof(dp));
    ll ans=0;
    for(int i=sz-1;i>=0;i--){
        ans+=f(i,2,2,1);
        ans-=f(i+1,2,2,1);
        ans+=m;
        ans%=m;
    }
    printf("%d\n",(ans+1)%m);
   // cout<<(ans+1)%m<<endl;
    //cout<<f(0,2,2,1)<<endl;
}
