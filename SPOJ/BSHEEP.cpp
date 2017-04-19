#include <bits/stdc++.h>
using namespace std;

#define point complex<double>
#define X real()
#define Y imag()
#define mp make_pair
const double PI = 2 * acos(0);
const double EPS = 1e-9;

#define cp(a, b) ((conj(a) * (b)).imag())
#define dp(a, b) ((conj(a) * (b)).real())
bool isEqual(double x,double y){
  return abs(x-y)<EPS;
}
struct angleCMP {
  point about;
  angleCMP(point c) { about = c; }
  bool operator()(const point &p, const point &q) const {
    double cr = cp(p - about, q - about);
    if (fabs(cr) < EPS)
      return make_pair(p.Y, p.X) > make_pair(q.Y, q.X);
    return cr > 0;
  }
};

#define sz(O) int(O.size())
#define MP make_pair

vector<point> ConvexHull(vector<point> points) {
  if (sz(points) <= 1)
    return points;

  for (int i = 0; i < sz(points); i++)
    if (MP(points[i].Y, points[i].X) < MP(points[0].Y, points[0].X))
      swap(points[0], points[i]);

  sort(points.begin() + 1, points.end(), angleCMP(points[0]));

  vector<point> p, ch;

  // To remove co-linear points, un-comment this part
  for (int i = 0; i < sz(points); i++) {
    if (sz(p) > 1 && !cp(p.back() - p[0], points[i] - p[0])) {
      if (abs(points[0] - p.back()) < abs(points[0] - points[i]))
        p.back() = points[i];
    } else
      p.push_back(points[i]);
  }
  points = p;

  for (int i = 0; i < points.size(); i++) {
    while (sz(ch) > 1 && (isEqual(cp(ch[sz(ch) - 2] - ch[sz(ch) - 1],
                                  points[i] - ch[sz(ch) - 1]), 0) ||
                          cp(ch[sz(ch) - 2] - ch[sz(ch) - 1],
                             points[i] - ch[sz(ch) - 1]) > 0))
      ch.pop_back(); // ALSO Make it <= to remove co-linear points
    //  cout<<"test "<<i<<" "<<points[i].X<<" "<<points[i].Y<<endl;
    ch.push_back(points[i]);
  }
  /*if (sz(ch) >= 3) // Not a line
    ch.push_back(ch[0]);*/
  return ch;
}

#define ii pair<int, int>
#define dd pair<double, double>
main() { /*
   int k;
   cin >> k;
   cout << k << endl;
   for (int j = 1; j <= k; j++) {
     int n;
     cin>>n;
     std::vector<point> v;
     for (int i = 0; i < n; i++) {
       double x, y;
       cin >> x >> y;
       v.push_back(point(x, y));
     }
     int tmp;
     vector<point> CH = ConvexHull(v);
     int sz = CH.size();
     std::vector<ii> ans;
     for (int i = 0; i < sz; i++) {
       ans.push_back(ii(CH[i].Y + 0.1, CH[i].X + 0.1));
     }
     cout<<sz<<endl;
     for (int i = 0; i < sz; i++) {
       cout << ans[i].second << " " << ans[i].first << endl;
     }
     if (j != k) {
       cin >> tmp;
       cout << tmp << endl;
     }
   }*/

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    map<ii, int> M;
    std::vector<point> p;
    for (int i = 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      if (!M[ii(x, y)]) {
        M[ii(x, y)] = i + 1;
        p.push_back(point(x, y));
      }
    }
    if (p.size() == 2) {
      if (mp(p[0].Y, p[0].X) > mp(p[1].Y, p[1].X))
        swap(p[0], p[1]);
      cout << fixed << setprecision(2) << 2 * abs(p[1] - p[0]) << endl;
      cout << M[ii(p[0].X, p[0].Y)] << " " << M[ii(p[1].X, p[1].Y)] << endl;
      cout << endl;
      continue;
    }
    if (p.size() == 1) {
      printf("0.00\n1\n\n");
      continue;
    }
    std::vector<point> ch = ConvexHull(p);
    int sz = ch.size();
    double ans = 0;
    for (int i = 0; i < sz; i++) {
      ans += abs(ch[i] - ch[(i + 1) % sz]);
    }
    std::cout << fixed << setprecision(2) << ans << endl;
    for (int i = 0; i < sz; i++) {
      if (i != 0)
        cout << " ";
      //  cout<<ch[i].X<<" "<<ch[i].Y<<endl;
      cout << M[ii(ch[i].X, ch[i].Y)];
    }
    cout << endl << endl;
  }
}
