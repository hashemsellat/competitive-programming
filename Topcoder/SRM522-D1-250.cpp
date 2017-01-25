#include<bits/stdc++.h>
using namespace std;
string s;int n;
int dp[14][(1<<14)];
int f(int turn,int mask){
   // cout<<turn<<endl;
    if(__builtin_popcount(mask)==n-1){
            for(int i=0;i<n;i++)
                if(!(mask&(1<<i))){
                    if(s[i]!=char('A'+turn))
                        return turn;
                }
            return !turn;
    }
    if(dp[turn][mask]!=-1)
        return dp[turn][mask];
    int ret=turn;
    for(int i=0;i<n;i++){
        if(!(mask&(1<<i))){
            int nmask=mask;
            for(int j=i;j<n&&!(mask&(1<<j));j++){
                nmask|=(1<<j);
                if(__builtin_popcount(nmask)==n)
                    break;
                if(turn%2==0)
                    ret|=f(turn^1,nmask);
                else{
                    if(!f(turn^1,nmask))
                        ret=0;
                }
            }
        }
    }
    return dp[turn][mask]=ret;
}

struct RowAndCoins{
    string getWinner(string cells){
        n=cells.size();
        int cnt=0;
        int sz=cells.size();
        char p=cells[0];
        memset(dp,-1,sizeof(dp));
        s=cells;
        if(!f(0,0))
            return "Bob";
        else
            return "Alice";
    }
};

main(){
        RowAndCoins a;
        string s;
        cin>>s;
        cout<<a.getWinner(s)<<endl;
}


