#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define double long double
#define int long long int
const int N = 1e6;
int a[N], b[N], d[N];
#define  A first
#define  B second.first
#define ii pair<int,int>
#define di pair<double,int>
#define idi pair<int,di>
main() {
  int t;
  ios_base::sync_with_stdio(false);
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<ii> v;
    for (int i = 0; i < n; i++) {
      cin >> a[i] >> b[i] >> d[i];
      v.push_back(ii(d[i],i));
    }
    sort(v.begin(), v.end());
    double time = 0;
    set<idi> s;
    double ans=0;
    for (int i = 0; i < n; i++) {
      int id=v[i].second;
      s.insert(idi(a[id],di(b[id],id)));
      if (time + b[id] <= d[id]) {
        time += b[id];
        continue;
      } else {
        while (time + b[id] > d[id]) {
          idi cur = *s.rbegin();
          // a b id
          s.erase(cur);
          double need = time + b[id] - d[id];
          // a*x=need  => x=need/a
          double x = need / cur.A;
          if (cur.B - need >= 0) {
          //  cout<<"YES"<<endl;
            ans+=x;
          //  cout<<ans<<endl;
            time = d[id];
            cur.B -= need;
            if(cur.B!=0)
              s.insert(cur);
            break;
          }
          ans+=cur.B/cur.A;
          time -= cur.B;
        }
      }
    }
    cout << fixed << setprecision(2) << ans << endl;
  }
}
