#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int MX = 100;
ll dist[MX][MX], cur[2000][MX];
#define vi std::vector<int>
struct NegativeGraphDiv2 {
  ll findMin(int N, vi s, vi t, vi weight, int charges) {
    int sz = s.size();
    N--;
    for (int i = 0; i <= N; i++) {
      for (int j = 0; j <= N; j++) {
        dist[i][j] = 1e9;
      }
      dist[i][i] = 0;
    }

    for (int i = 0; i < sz; i++) {
      int u = s[i], v = t[i];
      u--;
      v--;
      dist[u][v] = min(1LL * weight[i], dist[u][v]);
    }
    // apply floyd
    for (int k = 0; k <= N; k++) {
      for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }

    for (int i = 0; i <= N; i++) {
      cur[0][i] = dist[i][N];
      cout<<0<<" "<<i<<" "<<cur[0][i]<<endl;
    }

    for (int i = 1; i <= charges; i++) {
      for (int j = 0; j <= N; j++) {
        cur[i][j] = cur[i - 1][j];
        for (int k = 0; k < sz; k++) {
          int u = s[k], v = t[k], w = weight[k];
          u--;v--;
          cur[i][j] = min(cur[i][j], dist[j][u] - w + cur[i - 1][v]);
        }
        cout<<i<<" "<<j<<" "<<cur[i][j]<<endl;
      }
    }
    cout<<cur[charges][0]<<endl;
    return cur[charges][0];
  }
};
main() {
  ios_base::sync_with_stdio(false);
  int n = 1;
  vi s = {1};
  vi t = {1};
  vi weight = {100};
  int ch = 1000;
  NegativeGraphDiv2 a;
  cout << a.findMin(n, s, t, weight, ch) << endl;
}
