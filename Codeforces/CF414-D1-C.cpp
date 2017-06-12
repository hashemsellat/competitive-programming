#include<iostream>
#include <cstdio>
#include <vector>

#define  int long long int
using namespace std;
const int N = (1LL << 20);
#define  ii pair<int,int>

int a[N];

void prnt(vector<int> v) {
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

int cntInversions(vector<int> L, vector<int> R, vector<int> &ret) {
    int i = 0, j = 0;
    int sz = L.size(), cnt = 0;
    while(i<sz&&j<sz){
        if(L[i]<=R[j]){
            ret.push_back(L[i++]);
        }
        else{
            ret.push_back(R[j++]);
            cnt+=sz-i;
        }
    }
    for (j; j < sz; j++) {
        ret.push_back(R[j]);
    }
    //cout << "foo " << sz << " " << i << endl;
    for (i; i < sz; i++) {

        ret.push_back(L[i]);
    }

    return cnt;
}

ii foo[30];

vector<int> f(int h, int l, int r) {
    vector<int> ret;
    if (l == r) {
        ret.push_back(a[l]);
        return ret;
    }
    int md = (l + r) / 2;
    vector<int> L = f(h - 1, l, md), R = f(h - 1, md + 1, r);

    foo[h].first += cntInversions(L, R, ret);
    vector<int> tmp;
    foo[h].second += cntInversions(R, L, tmp);

    //  cout << "L" << endl;
    // prnt(L);
    //   cout << "R" << endl;
    //prnt(R);
    //  cout << h << " " << foo[h].first << " " << foo[h].second << endl;
    return ret;
}

main() {

    int n;
    scanf("%I64d", &n);
    for (int i = 0; i < (1LL << n); i++) {
        scanf("%d", &a[i]);
    }
    f(n, 0, (1LL << n) - 1);
    int m;
    scanf("%I64d", &m);
    while (m--) {
        int x;
        scanf("%I64d", &x);
        int ans=0;
        for (int j = 1; j <= n; j++) {
            if(j<=x){
                swap(foo[j].first,foo[j].second);
            }
            ans+=foo[j].first;
        }
        printf("%I64d\n",ans);
    }
}