#include <iostream>
#include <complex>
#include <vector>
#include <cstring>
#include <iomanip>
#include <map>
#include <algorithm>

using namespace std;
#define point complex<double>
#define X first
#define Y second
#define ii pair<int,int>
#define iii pair<int,ii>
double dp[200][200][2][2];

struct str {

    int i;
    int j;
    bool is;
    bool is1;

    str() {
        i = 1e9;
    }
};

str nxt[200][200][2][2];
int n, b1, b2;
point p[200];

/*double f(int i, int j, bool is, bool is1) {

    // cout << i << " " << j << " " << is << " " << is1 << endl;
    if (i == n - 1 || j == n - 1) {
        if (is && is1)
            return abs(p[n - 1] - p[j]) + abs(p[n - 1] - p[i]);
        else
            return 1e12;
    }
    if (dp[i][j][is][is1] == dp[i][j][is][is1])
        return dp[i][j][is][is1];

    double ret = 1e12;
    int lastj = j;
    double foo = 0;
    bool hoo=lastj==b2;
    for (int k = i + 1; k < n; k++) {
        //take k by i or by j
        //if k is taken by i then all point ]i,k[ should be taken by j

        double now = foo + abs(p[i] - p[k]) + f(k, lastj, is | k == b1, is1 | hoo);
        if (now < ret) {
            ret = now;
            nxt[i][j][is][is1].i = k;
            nxt[i][j][is][is1].j = lastj;
            nxt[i][j][is][is1].is = is | k == b1;
            nxt[i][j][is][is1].is1 = is1 | lastj == b2;
        }
        foo += abs(p[lastj] - p[k]);
        lastj = k;
        hoo|=lastj==b2;
    }
    return dp[i][j][is][is1] = ret;
}
*/
double f(int i, int j, bool is, bool is1) {
    // cout << i << " " << j << " " << is << " " << is1 << endl;
    if (i == n - 1 || j == n - 1) {
        if (is && is1)
            return abs(p[n - 1] - p[j]) + abs(p[n - 1] - p[i]);
        else
            return 1e12;
    }
    if (dp[i][j][is][is1] == dp[i][j][is][is1])
        return dp[i][j][is][is1];

    double ret = 1e12;
    int nxt1=1+max(i,j);

    if(nxt1==b1){
        ret=abs(p[i]-p[nxt1])+f(nxt1,j,1,is1);
        nxt[i][j][is][is1].i=nxt1;
        nxt[i][j][is][is1].j=j;
        nxt[i][j][is][is1].is=1;
        nxt[i][j][is][is1].is1=is1;
    }
    else
    if(nxt1==b2){
        ret=abs(p[j]-p[nxt1])+f(i,nxt1,is,1);
        nxt[i][j][is][is1].i=i;
        nxt[i][j][is][is1].j=nxt1;
        nxt[i][j][is][is1].is=is;
        nxt[i][j][is][is1].is1=1;
    }
    else{
        ret=abs(p[i]-p[nxt1])+f(nxt1,j,is,is1);
        nxt[i][j][is][is1].i=nxt1;
        nxt[i][j][is][is1].j=j;
        nxt[i][j][is][is1].is=is;
        nxt[i][j][is][is1].is1=is1;
        double foo=abs(p[j]-p[nxt1])+f(i,nxt1,is,is1);
        if(foo<ret){
            nxt[i][j][is][is1].i=i;
            nxt[i][j][is][is1].j=nxt1;
            nxt[i][j][is][is1].is=is;
            nxt[i][j][is][is1].is1=is1;
            ret=foo;
        }
    }
    return dp[i][j][is][is1] = ret;
}

main() {
    for (int c = 1;; c++) {
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < 200; i++) {
            str foo;
            for (int j = 0; j < 200; j++) {
                for (int k = 0; k < 2; k++)
                    for (int l = 0; l < 2; l++)
                        nxt[i][j][k][l] = foo;
            }
        }
        ios_base::sync_with_stdio(false);
        cin >> n >> b1 >> b2;
        if (n == 0 && b1 == 0 && b2 == 0)
            break;
        for (int i = 0; i < n; i++) {
            double x, y;
            cin >> x >> y;
            p[i] = point(x, y);
        }
        cout << "Case " << c << ": ";

        cout << fixed << setprecision(2) << f(0, 0, 0, 0)  << endl;
        int i = 0, j = 0, is = 0, is1 = 0;
        vector<int> p1, p2;
        while (nxt[i][j][is][is1].i != 1e9) {
            //  cout<<"test "<<i<<" "<<j<<endl;
            p1.push_back(i);
            p2.push_back(j);
            int nxti = nxt[i][j][is][is1].i;
            int nxtj = nxt[i][j][is][is1].j;
            bool nxtis = nxt[i][j][is][is1].is;
            bool nxtis1 = nxt[i][j][is][is1].is1;

            i = nxti;
            j = nxtj;
            is = nxtis;
            is1 = nxtis1;

        }
        vector<int> ans;
        map<int, int> M;
        for (int i = 0; i < p1.size(); i++) {
            if(!M[p1[i]])
            ans.push_back(p1[i]);
            M[p1[i]] = 1;
        }
        M[n - 1] = 1;
        ans.push_back(n - 1);
        for (int i = n - 1; i > 0; i--) {
            if (!M[i]) {
                ans.push_back(i);
            }
        }
        ans.push_back(0);
        if(ans[1]!=1){
            reverse(ans.begin(),ans.end());
        }
        for (int i = 0; i < ans.size(); i++) {
            if (i != 0) cout << " ";
            cout << ans[i];
        }
        cout << endl;
    }
}
