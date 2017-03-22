#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N = 21000;
int BIT[N];
int n;
int query(int id) {
  int ret = 0;
  for (; id > 0; id -= (id & (-id))) {
    ret += BIT[id];
  }
  return ret;
}
void update(int id, int val) {
  for (id; id <= n; id += (id & (-id))) {
    BIT[id] += val;
  }
}
int ans[N];
main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    memset(BIT, 0, sizeof(BIT));
    for (int i = 1; i <= n; i++) {
      update(i, 1);
    }
    int cur = 0;
    for (int i = 1; i <= n; i++) {
      int l = 0, r = n;
      int full = i + 1;
      if (query(r) < i + 1) {
        int now = query(r) - query(cur);

        full = (i - now) % query(r) + 1;
        cur = 0;
      } else {
        if (query(r) - query(cur) < full) {
          full -= query(r) - query(cur);
          cur = 0;
        }
      }
      while (l + 1 < r) {
        int md = (l + r) / 2;
        if (query(md) - query(cur) >= full)
          r = md;
        else
          l = md;
      }
      //    cout<<i<<" "<<r<<" "<<full<<endl;
      ans[r] = i;
      cur = r;
      update(r, -1);
    }
    for (int i = 1; i <= n; i++) {
      cout << ans[i];
      if (i != n)
        cout << " ";
      else
        cout << endl;
    }
  }
}
