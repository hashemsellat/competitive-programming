#include<bits/stdc++.h>
#define ii pair<int,int>
#define endl '\n'
const int N=5010;
using namespace std;
ii dp[2][N][N];
int c[N];
int n;
#define endl '\n'
main()
{
    // ios_base::sync_with_stdio(false);
    scanf("%d",&n);
     // n=2000;
    for(int i=0; i<n; i++)
        // c[i]=1e5;
       scanf("%d",&c[i]);
    for(int i=n-1; i>=0; i--)
    {
        for(int turn=0; turn<2; turn++)
        {
            int sm=0,j=0;
            ii ret(0,0);
            for(int prv=0; prv<=n; prv++)
            {
                if(prv>(i+1))
                    break;
                for(j; j<max(2*prv,1)&&i+j<n; j++)
                {
                    ii nxt=dp[turn^1][j+1][i+j+1];
                    sm+=c[i+j];
                    if(turn==0)
                        nxt.first+=sm;
                    else
                        nxt.second+=sm;
                    if(turn==0&&nxt.first>ret.first)
                    {
                        ret=nxt;
                    }
                    if(turn==1&&nxt.second>ret.second)
                    {
                        ret=nxt;
                    }
                }
                dp[turn][prv][i]=ret;
            }
        }
    }
    // ii ans=f(0,0,0);
    printf("%d\n",dp[0][1][0].first);
}
