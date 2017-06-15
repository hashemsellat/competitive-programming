#include<bits/stdc++.h>

using namespace std;
const int N = 1e6;
#define ii pair<int,int>
#define endl '\n'
int ans[N], sum[N], foo[N],vis[N];
vector<ii > adj[N];
map<ii, int> M;

main() {

    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        sum[u] += c;
        sum[v] += c;
        foo[u] += c;
        foo[v] += c;
        adj[u].push_back(ii(v, c));
        adj[v].push_back(ii(u, c));
        M[ii(u, v)] = i;
    }

    queue<int> q;
    q.push(1);

    while (!q.empty()) {
        int cur = q.front();
        vis[cur]=1;
      //  cout<<cur<<endl;
        if (cur == n)
            break;
        q.pop();
        for (auto x:adj[cur]) {
            int nxt = x.first, c = x.second;
          //  cout<<cur<<" "<<nxt<<endl;
            if(vis[nxt])
                continue;
           // cout<<cur<<" "<<nxt<<endl;
            if (M[ii(cur, nxt)]) {
                ans[M[ii(cur, nxt)]] = 0;
            } else
                ans[M[ii(nxt, cur)]] = 1;
            sum[nxt] -= c;
            if (sum[nxt] == foo[nxt] / 2&&nxt!=n) {
                q.push(nxt);
                vis[nxt]=1;
            }
        }
    }

    for (int i = 1; i <= m; i++) {
        cout << ans[i] << endl;
    }
}
