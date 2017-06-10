#include <iostream>
#include <vector>
#include <set>

#define ii pair<int,int>
using namespace std;
const int N = 1e6;
int a[N], ans[N], n, m;

vector<int> adj[N], q[N];

vector<ii > val[N];

void update(int x, int val, int tree[]) {
    while (x <= m) {
        tree[x] += val;
        x += (x & -x);
        // cout<<x<<endl;
    }
}

int get(int x, int tree[]) {
    int ret = 0;
    while (x) {
        ret += tree[x];
        x -= (x & -x);
        //  cout<<x<<endl;
    }
    return ret;
}

int tree[2][N];

void dfs(int v, int p, int l = 0, int r = 1) {

    //cout << v << endl;
    //l is for adding,r is for removing
    for (auto x:val[v]) {
        update(x.second, x.first, tree[l]);
    }
    for (auto x:q[v]) {
        ans[x] = get(x, tree[l]) - get(x, tree[r]) + a[v];
        //cout<<"FOO "<<x<<" "<<ans[x]<<endl;
    }
    for (auto x:adj[v]) {

        if (x == p)
            continue;

        dfs(x, v, r, l);
    }
    for (auto x:val[v]) {
        update(x.second, -x.first, tree[l]);
    }

}

#define endl '\n'

main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> a[i + 1];
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }
    vector<int> foo;
    for (int i = 1; i <= m; i++) {
        int x, t, v;
        cin >> t >> x;
        if (t == 1) {
            cin >> v;
            val[x].push_back(ii(v, i));
        } else {
            foo.push_back(i);
            q[x].push_back(i);
        }
    }
    dfs(1, 0);
    // cout<<"HOO"<<endl;
    for (int i = 0; i < foo.size(); i++) {
        cout << ans[foo[i]] << endl;
    }

}