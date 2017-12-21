
#include <iostream>
#include <cstring>

using namespace std;
int t,kk;
#define int long long int
const int MAXN  = 1111;
const int MOD  = 1e9+7;
int dp[MAXN][MAXN+1][2];
int f(int i,int prev,bool is){
    if(i==MAXN)
        if(is)
            return 1;
        else
            return 0;

    if(dp[i][prev][is]!=-1)
        return dp[i][prev][is];
    int ret=(2*f(i+1,1,is||prev<=kk)+8*f(i+1,min(prev+1,1111LL),is))%MOD;

    return dp[i][prev][is]=ret;
}
bool isl(string &s){
    int sz=s.size(),last=-1111;
    for(int i=0;i<sz;i++){
        if(s[i]=='4'||s[i]=='7'){
            if(i-last<=kk){
                return 1;
            }
            last=i;
        }
    }
    return 0;
}
int solve(string &s){
    bool is=false;
    int ans=0,d=1111,sz=s.size();
    for(int j=0;j<sz;j++){
    //    cout<<":D "<<j<<endl;
        int num=s[j]-'0';
        for(int k=0;k<num;k++){
            if(k==4||k==7){
                ans += f((MAXN-(sz-(j+1))),1,is||d<=kk);
          //      cout<<"FOO "<<MAXN-(sz-(j+1))<<" "<<f((MAXN-(sz-(j+1))),1,is||d<=kk)<<" "<<is<<" "<<d<<endl;
            }
            else {
                ans += f(MAXN-(sz-(j+1)), min(d+1,1111LL), is);
           //     cout<<"TOO "<<MAXN-(sz-(j+1))<<" "<<d+1<<" "<<is<<" "<<f(MAXN-(sz-(j+1)), d+1, is)<<endl;
            }
            ans%=MOD;
        }
        if(num==4||num==7)
        {
            if(d<=kk)
                is=1;
            d=0;
        }
   //     cout<<j<<" "<<ans<<" "<<is<<" "<<d<<endl;
        d++;
    }
    return  ans;
}
#define endl '\n'
main() {
    ios_base::sync_with_stdio(false);
    cin>>t>>kk;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<t;i++){
        string l,r;
        cin>>l>>r;
  //      cout<<solve(r)<<" "<<solve(l)<<endl;
        cout<<(solve(r)-solve(l)+isl(r)+2*MOD)%MOD<<endl;
    }
}