#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define endl '\n'

int dp[110][1 << 15];
int sum[1 << 15];
vector<int> masks[110 * 110];

int f(int r, int c, int mask) {
  //  cout<<r<<" "<<c<<endl;
    if (sum[mask] != r * c)
        return 0;

    if (__builtin_popcount(mask) == 1)
        return 1;

    if (dp[r][mask] != -1)
        return dp[r][mask];

    bool ret = 0;

    for (int i = 1; i < r; i++) {
        int u = i, d = r - i;
        for (int j = 0; j < masks[u * c].size(); j++) {
            int curmask = masks[u * c][j];
            //every bit of curmask should be common with mask
            if (~mask & curmask)
                continue;
            int nxtmask = mask & (~curmask);
            if (sum[nxtmask] == d * c) {
                ret = ret | (f(u, c, curmask) && f(d, c, nxtmask));
                if(ret)
                    goto foo;
            }
        }
    }

    for (int i = 1; i < c; i++) {
        int l = i, ri = c - i;
        for (int j = 0; j < masks[r * l].size(); j++) {
            int curmask = masks[r * l][j];
            if (~mask & curmask)
                continue;
            int nxtmask = mask & (~curmask);
            if (sum[nxtmask] == ri * r) {
                ret = ret | (f(r, l, curmask) && f(r, ri, nxtmask));
                if(ret)
                    goto foo;
            }
        }
    }

    foo:
    return dp[r][mask] = ret;
}

int p[20];

main() {
    ios_base::sync_with_stdio(false);

    for (int foo = 1;; foo++) {
        memset(dp, -1, sizeof(dp));
        memset(sum, 0, sizeof(sum));
        int n;
        cin >> n;
        if(n==0)
            break;
        int r, c;
        cin >> r >> c;
        for(int i=0;i<=r*c;i++)
            masks[i].clear();
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }

        for (int mask = 1; mask < (1 << n); mask++) {
            int sm = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i))
                    sm += p[i];
            }
            sum[mask] = sm;
            masks[sm].push_back(mask);
        }

        int ans = f(r, c, (1 << n) - 1);
        cout << "Case " << foo << ": ";
        if (ans == 0) {
            cout << "No" << endl;
        } else
            cout << "Yes" << endl;
    }
}