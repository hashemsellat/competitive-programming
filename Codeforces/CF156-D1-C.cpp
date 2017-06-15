#include<bits/stdc++.h>
using namespace std;
#define int long long int
int dp[111][3333];
const int MOD=1e9+7;
int f(int i,int num){
    if(i==0){
        if(num==0)
            return 1;
        else
            return 0;
    }
    if(dp[i][num]!=-1)
        return dp[i][num];
    int ret=0;
    for(int j=1;j<=26;j++){
        ret+=f(i-1,num-j);
    }
    ret%=MOD;
    return dp[i][num]=ret;
}
#define endl '\n'
main(){
    memset(dp,-1,sizeof(dp));
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;

    while(t--){
        string s;
        cin>>s;
        int sm=0;
        for(int i=0;i<s.size();i++){
            sm+=s[i]-'a'+1;
        }
        cout<<(MOD+f(s.size(),sm)-1)%MOD<<endl;
    }

}