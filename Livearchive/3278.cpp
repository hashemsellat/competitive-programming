
#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>
ii foo[100];
int cnt[100], a[100];
#define endl '\n'
main() {
  ios_base::sync_with_stdio(false);
  int n, m, cnter;
  int c = 0;
  while (cin >> n >> cnter) {
    if (n == 0 && cnter == 0)
      break;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
      int cur = 0;
      int t;
      cin >> t;
      cnt[i] = t;
      for (int j = 0; j < t; j++) {
        int x;
        cin >> x;
        x--;
        cur |= (1 << x);
      }
      foo[i].first = cur;
      cin >> foo[i].second;
    }
    int ansl = 0, ansr;
    for (int mask = 0; mask < (1 << n); mask++) {
      if (__builtin_popcount(mask) != cnter)
        continue;
      int now = 0;
      for (int j = 0; j < n; j++) {
        if (mask & (1 << j)) {
          now += a[j];
        }
      }
      for (int j = 0; j < m; j++) {
        // take it
        if (mask & foo[j].first)
          now -= (__builtin_popcount(mask & foo[j].first) - 1) * foo[j].second;
      }
      if (now > ansl) {
        ansl = now;
        ansr = mask;
      }
    }
    cout << "Case Number  " << ++c << endl;
    cout << "Number of Customers: " << ansl << endl;
    cout << "Locations recommended: ";
    bool is=0;
    for (int j = 0; j < n; j++) {
      if (ansr & (1 << j)) {
        if(is)  cout<<" ";
        is=1;
        cout << j + 1;
      }
      if (j == n - 1)
        cout << endl;
    }
    cout << endl;
  }
}
