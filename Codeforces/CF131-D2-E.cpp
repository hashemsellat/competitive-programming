#include <iostream>
#include <vector>
#include <set>

using namespace std;
#define ii pair<int,int>
set<ii > adj[1000000];
const int N = 1e5 + 10;
set<int> adj1[1000000];
int ans[10];
main() {
    int n, m;
    vector<ii > queens;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int r, c;
        cin >> r >> c;
        adj[2*N + r + c].insert(ii(r, c));
        adj[N + r - c].insert(ii(r, c));
        queens.push_back(ii(r, c));

        adj1[r].insert(c);
        adj1[N + c].insert(r);
    }
    for (int i = 0; i < m; i++) {
        int cnt = 0;
        int r = queens[i].first, c = queens[i].second;
        set<int>::iterator it = adj1[r].lower_bound(c);
        if (it != adj1[r].begin()) {
            cnt++;
        }
        it++;
        if (it != adj1[r].end())
            cnt++;


        it = adj1[N + c].lower_bound(r);
        if (it != adj1[N + c].begin())
            cnt++;
        it++;
        if (it != adj1[N + c].end())
            cnt++;

        set<ii >::iterator it1;
        it1 = adj[2*N + r + c].lower_bound(ii(r, c));
        if (it1 != adj[2*N + r + c].begin())
            cnt++;
        it1++;
        if (it1 != adj[2*N + r + c].end())
            cnt++;


        it1 = adj[N + r - c].lower_bound(ii(r, c));

        if (it1 != adj[N + r - c].begin())
            cnt++;
        it1++;
        if (it1 != adj[N + r - c].end())
            cnt++;

        ans[cnt]++;

    }
    for(int i=0;i<=8;i++){
        if(i)cout<<" ";
        cout<<ans[i];
    }
    cout<<endl;
}