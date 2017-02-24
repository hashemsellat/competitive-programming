#include<bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define endl '\n'
double dp[2][6000];
struct RedIsGood
{
    double getProfit(int R,int B)
    {
        int cur=0;
        for(int i=1; i<=R; i++)
            dp[cur][i]=i;
        for(int b=1; b<=B; b++)
        {
            cur^=1;
            for(int r=1; r<=R; r++)
            {
                double RR=r;
                double BB=b;
                dp[cur][r]=max(0.0,(1.0+dp[cur][r-1])*RR/(RR+BB)+(-1.0+dp[cur^1][r])*BB/(RR+BB));

            }
        }
        return dp[cur][R];
    }
};

main()
{
    RedIsGood a;
    cout<<a.getProfit(2,2)<<endl;
}
