#include <iostream>
#include <cstring>
#include <vector>

#define  int long long int
const int N = 1e5 + 10;
#define endl '\n'
using namespace std;

int v[N], a[N], dp[N];
#define  ii pair<int,int>
bool vis[N];

struct foo {
    vector<ii > vec;
    int cnt;

    foo() {
        cnt = 0;
        vec.assign(2, ii(0, -1e18));
    }

    void maintain(ii x) {
        //this should keep the best two different
        for (int i = 0; i < 2; i++)
            if (x.first == vec[i].first) {
                vec[i].second = max(vec[i].second, x.second);
                return;
            }

        //not equal
        if (vec[1].second < vec[0].second) {
            swap(vec[1], vec[0]);
        }
        if (x.second > vec[0].second)
            vec[0] = x;
    }

    int getMax(ii x) {
        int ret = 0;
        if (cnt >= 2) {
            if (vec[0].second < vec[1].second) {
                swap(vec[0], vec[1]);
            }
        }
        for (int i = 0; i < min(cnt, 2LL); i++) {
            if (vec[i].first != x.first) {
                return vec[i].second;
            }
        }
        return ret;
    }
};

main() {
    ios_base::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    while (q--) {
        foo glob;
        int ai, bi;
        cin >> ai >> bi;
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i <= n; i++) {
            dp[i] = -1e18;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int callOfDuty = 0;
            if (vis[a[i]]) {
                dp[a[i]] = max(dp[a[i]], dp[a[i]] + ai * v[i]);
            }
            //  cout<<"SSSS "<<glob.getMax(ii(a[i],0))<<endl;
            dp[a[i]] = max(dp[a[i]], max(0LL, glob.getMax(ii(a[i], 0))) + bi * v[i]);
            ans = max(ans, dp[a[i]]);
            glob.maintain(ii(a[i], dp[a[i]]));
            // cout << "fooo " << dp[a[i]] << endl;
            if (!vis[a[i]]) {
                vis[a[i]] = 1;
                glob.cnt++;
            }

        }
        cout << ans << endl;
    }

}