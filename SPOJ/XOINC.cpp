//i hope it's clear and sorry for the poor English.
/* in this game problem we have 2 players and each of them should maximize the sum of values he takes.
they both play the same way*/
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
    for(int i=0; i<n; i++)
       scanf("%d",&c[i]);
    /*let dp[turn][prv][i] be the maximum sum of coins player #turn can obtain if he started at coin #i and the previous player took
prv coins, In this problem bottom-up dp is faster than top-down and there is no need for additional arrays*/


    for(int i=n-1; i>=0; i--)
    {
        for(int turn=0; turn<2; turn++)
        {

            // here j+1 is the number of coins player #turn will take, it ranges from 1 to 2*prv
            int sm=0,j=0;

            //the small optimization here is that we don't need to reset j each time we try a new prv, we just need to continue from the position where j has stopped in the last prv iteration.
            ii ret(0,0);
            for(int prv=0; prv<=n; prv++)
            {
                if(prv>(i+1))
                    break;
                for(j; j<max(2*prv,1)&&i+j<n; j++)
                {
                  //at each step we try to take one more coin
                    ii nxt=dp[turn^1][j+1][i+j+1];
                    sm+=c[i+j];
                    /* the first player will try to maximize the first element of the pair while the second player
                    will try to maximize the second element */
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
    printf("%d\n",dp[0][1][0].first);
}
