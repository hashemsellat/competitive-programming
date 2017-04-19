#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
#define int long long int
const int MX=1e6;
int sm[MX],dp[MX];
std::vector<int> adj[MX];
#define ii pair<int,int>
main() {
  int n, m;
  cin >> n >> m;
  set<int> s;
  bool is=0,is1=0;
  std::vector<ii> v(m);
  for (int i = 0; i < m; i++) {
    cin >> v[i].second >> v[i].first;
    if (v[i].first == n)
      is = 1;
    if(v[i].second==0)  is1=1;
    s.insert(v[i].first);
    s.insert(v[i].second);
  }
  if(!is||!is1){
    cout<<0<<endl;
    return 0;
  }
  map<int, int> M;

  int cnt = 0;

  for (auto x : s) {
    M[x] = ++cnt;
  }
  for (int i = 0; i < m; i++) {
    v[i].first = M[v[i].first];
    v[i].second = M[v[i].second];
    adj[v[i].first].push_back(v[i].second);
  }
  dp[1] = 1;
  sm[1]=1;
  for (int i = 1; i <=cnt; i++) {
    int sz = adj[i].size();
    sm[i] = sm[i - 1];
    for (int k = 0; k < sz; k++) {
      int e =i, s = adj[i][k];
    //  cout<<e<<" "<<s<<endl;
      dp[e] += sm[e - 1] - sm[s - 1];
      dp[e] += MOD;
      dp[e] %= MOD;
    }
    sm[i] += dp[i];
  //  cout<<"test "<<i<<" "<<sm[i]<<endl;
    sm[i]%=MOD;
  }
  cout << dp[cnt] << endl;
}
