#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 111;
#define  ii pair<int,int>
#define  iii pair<int,ii>
#define int unsigned long long int
int x, k, M;
vector<iii > tmp;
int n, m, b;
int dp[1 << 20];
inline int log2(int x){
    int ret=0;
    while(x){
        ret++;
        x/=2;
    }
    return ret;
}
bool overFlow(int x,int y){
    if(log2(x)+log2(y)<=64)
        return 0;
    return 1;
}
const int INF = 2 * 1e18;
#define endl '\n'
main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> b;
    for (int i = 1; i <= n; i++) {
        cin >> x >> k >> M;
        int curMask = 0;
        for (int j = 0; j < M; j++) {

            int e;
            cin >> e;
            curMask |= (1 << (e - 1));

        }
        M = curMask;
        tmp.push_back(iii(k, ii(x, M)));
    }
    int ans = INF;
    sort(tmp.begin(), tmp.end());

    for(int i=0;i<(1<<(m));i++){
        if(__builtin_popcount(i)!=0)
            dp[i]=INF;
        else
            dp[i]=0;
    }

    for(int i=0;i<n;i++){
        for(int mask=0;mask<(1<<(m));mask++) {
            int nmask = mask | tmp[i].second.second;
            dp[nmask]=min(dp[nmask],dp[mask]+tmp[i].second.first);
        }
        ans = min(ans , dp[(1<<m)-1]+b*tmp[i].first);
    }
    if (ans == INF) {
        cout << -1 << endl;
    } else
        cout<<ans<<endl;
}