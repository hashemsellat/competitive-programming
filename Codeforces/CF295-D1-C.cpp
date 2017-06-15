#include<iostream>
#include <cstring>


#define  int long long int
#define  ii pair<int,int>
using namespace std;
int k;
int dp[300][51][51][2];
int fifty, hundred;
const int MOD = 1e9 + 7;
int c[1001][1001];

int f(int cnt, int _50, int _100, int t) {
    if (cnt == 0)
        if (_50 == 0 && _100 == 0 && t == 1)
            return 1;
        else
            return 0;
    if (_50 < 0 || _100 < 0)
        return 0;
    if (dp[cnt][_50][_100][t] != -1)
        return dp[cnt][_50][_100][t];
    int ret = 0;
    int foo;
    if (t == 0) {
        for (int i = 0; i <= _50; i++) {//number of 50 we take in the trip
            if (i * 50 > k)
                break;
            for (int j = 0; j <= _100; j++) {//number of 100s we take in the trip
                if (!i && !j)
                    continue;
                //use i fifties and j hundreds
                if (i * 50 + j * 100 > k)
                    break;
                //    if(t==0){
                foo = f(cnt - 1, _50 - i, _100 - j, 1);
                (foo *= c[_50][i]) %= MOD;
                (foo *= c[_100][j]) %= MOD;
                ret += foo;
                ret%=MOD;
            }

        }
    } else {
        for (int i = 0; i <= fifty - _50; i++) {//return 0,1,2,..
            if (i * 50 > k)
                break;
            for (int j = 0; j <= hundred - _100; j++) {//number of 100s we take in the trip
                if (!i && !j)
                    continue;
                //use i fifties and j hundreds
                if (i * 50 + j * 100 > k)
                    break;
                //    if(t==0){
                foo = f(cnt - 1, _50 + i, _100 + j, 0);
                (foo *= c[fifty - _50][i]) %= MOD;
                (foo *= c[hundred - _100][j]) %= MOD;
                ret += foo;
                //  }
            }

        }
    }
    return dp[cnt][_50][_100][t]=ret%MOD;
}

main() {

    c[0][0] = 1;
    for (int i = 1; i < 1000; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
            c[i][j] %= MOD;
        }
    }

    //  cout<<c[5][5]<<endl;
    int n;

    cin >> n >> k;

    fifty = 0, hundred = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 50) {
            fifty++;
        } else
            hundred++;
    }

    memset(dp, -1, sizeof(dp));

    for(int i=1;i<300;i++){
        int cur=f(i,fifty,hundred,0);
        if(cur){
            cout<<i<<endl<<cur<<endl;
            return 0;
        }
    }

    cout<<-1<<endl;
    cout<<0<<endl;
}
