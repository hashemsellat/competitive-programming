
#include <iostream>
#include <vector>
#include <map>

#define  ii pair<int,int>
using namespace std;
int a[20], b[20];
int n, m;
vector<int> v;
map<map<int, int>, int> M;
vector<ii > adja[20], adjb[20];


int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        int now = a[i];
        for (int j = 2; j * j <= now; j++) {
            if (now % j == 0) {
                int cnt = 0;
                while (now % j == 0) {
                    cnt++;
                    now /= j;
                }
                adja[i].push_back(ii(j, cnt));
            }
        }
        if (now != 1) {
            adja[i].push_back(ii(now, 1));
        }
    }


    for (int i = 0; i < m; i++) {
        cin >> b[i];
        int now = b[i];
        //  cout<<"SDF"<<endl;
        for (int j = 2; j * j <= now; j++) {
            if (now % j == 0) {
                int cnt = 0;
                while (now % j == 0) {
                    cnt++;
                    now /= j;
                }
                adjb[i].push_back(ii(j, cnt));
                //  cout<<"foo"<<endl;
                //    cout<<adjb[i].back().first<<" "<<adjb[i].back().second<<endl;
            }
        }
        if (now != 1) {
            adjb[i].push_back(ii(now, 1));
        }
    }


    for (int mask = 1; mask < (1 << n); mask++) {
        map<int, int> cur;
        for (int j = 0; j < n; j++) {
            if (mask & (1 << j)) {
                for (int k = 0; k < adja[j].size(); k++) {
                    cur[adja[j][k].first] += adja[j][k].second;
                }
            }
        }
        M[cur] = mask;
    }

    for (int mask = 1; mask < (1 << m); mask++) {
        map<int, int> cur;
        for (int j = 0; j < m; j++) {
            if (mask & (1 << j)) {
                for (int k = 0; k < adjb[j].size(); k++) {
                    cur[adjb[j][k].first] += adjb[j][k].second;

                }
            }
        }

        if (M[cur]) {
            int mask2 = M[cur];
            cout << "Y" << endl;
            cout << __builtin_popcount(mask2) << " " << __builtin_popcount(mask) << endl;
            for (int i = 0; i < n; i++) {
                if (mask2 & (1 << i)) {
                    cout << a[i] << " ";
                }
            }
            cout << endl;
            for (int i = 0; i < m; i++) {
                if (mask & (1 << i)) {
                    cout << b[i] << " ";
                }
            }
            cout << endl;
            return 0;
        }
    }
    cout << "N" << endl;
}