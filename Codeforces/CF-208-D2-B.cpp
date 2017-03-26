#include<bits/stdc++.h>
using namespace std;
int cnter=1;
char value[1000];
char type[1000];
int dp[52][52][52][52];
bool f(int i,int cur,int p,int pp){
    if(i==0)
        return 1;
    if(dp[i][cur][p][pp]!=-1)
        return dp[i][cur][p][pp];

    //put cur on prv
    bool ret=0;
    if(value[cur]==value[p]||type[cur]==type[p]){
        //put cur on p
        ret|=f(i-1,cur,pp,max(i-3,0));
    }
    if(i>=3){
        //put cur on i-2
        if(value[cur]==value[i-3]||type[cur]==type[i-3])
            ret|=f(i-1,p,pp,cur);
    }

    return dp[i][cur][p][pp]=ret;
}
main()
{
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(int i=0; i<n; i++)
    {
        string s;
        cin>>s;
        string l="";
        int j=0;

        value[i]=s[0];
        type[i]=s[1];
    }
    if(f(n-1,n-1,max(n-2,0),max(n-3,0)))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}
