#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e6;
int a[N];
main() {
  ios_base::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  int mn = 0, mx = 0, sm = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sm += a[i];
    mx = max(mx, a[i]);
  }
  if(sm<k){
    cout<<-1<<endl;
    return 0;
  }
  if(sm==k){
    cout<<endl;
    return 0;
  }
  mx++;
  while (mn + 1 < mx) {
    int md = (mn + mx) / 2;
    int cur = 0;
    for (int i = 0; i < n; i++) {
      cur += min(a[i], md);
    }
    if (cur <= k) {
      mn = md;
    } else
      mx = md;
  }
  for (int i = 0; i < n; i++) {
    k-=min(mn,a[i]);
    a[i] = max(a[i]-mn,0LL);
  }
  int i;
//  cout<<mn<<endl;
  for (i = 0; i < n && k; i++) {
    if (a[i]) {
      a[i]--;
      k--;
    }
  }
  //cout<<i<<endl;
  for (int j = 0; j < n; j++) {
    if (a[(i + j) % n])
      cout << (i+j)%n +1<< " ";
  }
  cout << endl;
}
