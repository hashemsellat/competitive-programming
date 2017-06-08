/*
it's tutorial explains it well
*/
#include <iostream>
#include <map>
#include <cstring>
#include <cstdlib>

#define int long long int
using namespace std;
const int MOD = 1e9 + 7;
int n;
int dp[63][63][63][63][2];

int f(int x1, int x2, int x3, int x4, bool is) {
    //cout<<x1<<" "<<x2<<" "<<x3<<" "<<x4<<endl;
    // system("pause");
    if (x1 == 0 && x2 == 0 && x3 == 0 && x4 == 0)
        if (is)
            return 1;
        else
            return 0;

    if (dp[x1][x2][x3][x4][is] != -1)
        return dp[x1][x2][x3][x4][is];

    /* take less than x1
     * then x1 become i,
     * x2 becomes x2+px1-i
     */
    int ret = 0;
    for (int i = 0; i < x1; i++) {
        ret += f(i, x2 + x1 - i - 1, x3, x4, (x4 != 0) || is);
    }
    for (int i = 0; i < x2; i++) {
        ret += f(x1, i, x3 + x2 - i - 1, x4, (x4 != 0) || is);
    }
    for (int i = 0; i < x3; i++) {
        ret += f(x1, x2, i, x4 + x3 - i - 1, (x4 != 0) || is);
    }
    // for(int i=0;i<x4;i++){
    if (x4)
        ret += f(x1, x2, x3, x4 - 1, (x4 != 0) || is);
    // }
    //cout<<"foo "<<ret<<endl;
    /*  if(ret<0){
          system("pause");
      }*/
    ret %= MOD;

    return dp[x1][x2][x3][x4][is] = ret;

}

int dp1[63][63][63][2];

int f1(int x1, int x2, int x3, bool is) {
    //cout<<x1<<" "<<x2<<" "<<x3<<" "<<is<<endl;
    //cout<<x1<<" "<<x2<<" "<<x3<<" "<<x4<<endl;
    // system("pause");
    if (x1 == 0 && x2 == 0 && x3 == 0)
        if (is)
            return 1;
        else
            return 0;

    if (dp1[x1][x2][x3][is] != -1)
        return dp1[x1][x2][x3][is];

    /* take less than x1
     * then x1 become i,
     * x2 becomes x2+px1-i
     */
    int ret = 0;
    for (int i = 0; i < x1; i++) {
        ret += f1(i, x2 + x1 - i - 1, x3, (x3 != 0) || is);
    }
    for (int i = 0; i < x2; i++) {
        ret += f1(x1, i, x3 + x2 - i - 1, (x3 != 0) || is);
    }
    //  for(int i=0;i<x3;i++){
    if (x3)
        ret += f1(x1, x2, x3 - 1, (x3 != 0) || is);

    //cout<<"foo "<<ret<<endl;
    /*  if(ret<0){
          system("pause");
      }*/
    ret %= MOD;

    return dp1[x1][x2][x3][is] = ret;

}

main() {
    cin >> n;
    memset(dp, -1, sizeof(dp));
    memset(dp1, -1, sizeof(dp1));
    int l = f(n, 0, 0, 0, 0);
    int r = f1(n, 0, 0, 0);

    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
        fact %= MOD;
    }
    cout << (fact - l - r + MOD + MOD) % MOD << endl;
}