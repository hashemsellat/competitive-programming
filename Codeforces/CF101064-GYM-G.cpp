/*
it's tutorial explains it well
*/
#include <iostream>
#include <vector>
#include <deque>

using namespace std;
const int N = 1e5 + 100;
int cnt = 1;
int par[N], root[N];
#define  ii pair<int,int>
int val[N];

vector<ii > adj[N];

void add(int v, int value) {

    int num = cnt++;

    val[num] = value;

    adj[v].push_back(ii(num, 1));

}


void delete_(int v) {
    int num = cnt++;
    adj[v].push_back(ii(num, 0));
}

deque<int> d;

int ans[N];
bool vis[N];

void dfs(int v) {
  //  cout << "test " << v << endl;
    for (auto x:adj[v]) {
        int num = x.first, type = x.second;
        if (type == 0) {
          //  cout<<":D"<<endl;
            ans[num] = d.front();
            vis[num] = 1;
            d.pop_front();
            dfs(num);
            d.push_front(ans[num]);
        } else {
            d.push_back(val[num]);
            dfs(num);
            d.pop_back();
        }

    }
}
#define  endl '\n'
int main() {
    ios_base::sync_with_stdio(false);

    int q;
    cin >> q;
    while (q--) {
        char c;
        int v, r;
        cin >> c;
        if (c == 'E') {
            cin >> v >> r;
            add(v, r);
        } else {
            cin >> v;
            //cout<<val[v];
            delete_(v);
        }
    }

    dfs(0);

    for (int i = 0; i < cnt; i++) {
        if (vis[i]) {
            cout << ans[i] << endl;
        }
    }
}