#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#define int long long int
#define endl '\n'
#define ii pair<int,int>
#define iii pair<int,ii>
const int N = 1e6;
int dp[N];

main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<iii > vec;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        vec.push_back(iii(w, ii(u, v)));
    }

    sort(vec.begin(), vec.end());

    for (int i = 0; i < m; i++) {
        int now = vec[i].first;
        map<int, int> dp1;
        while (i < m && vec[i].first == now) {
            dp1[vec[i].second.second] = max(dp1[vec[i].second.second],max(dp[vec[i].second.second], dp[vec[i].second.first] + 1));
            i++;
        }
        for (auto x:dp1) {
            dp[x.first] = x.second;
            // cout<<x.first<<" "<<x.second<<endl;
        }
        i--;
        // cout<<endl;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
}