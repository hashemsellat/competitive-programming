#include <bits/stdc++.h>

using namespace std;
#define  int long long int
#define point pair<int,int>
#define X first
#define Y second
vector<point > v;
const int MAXN = 1e5 + 10;

#define dot(a,b) ((conj(a)*(b)).real())

int detProduct(point p, point p1) {

    return p.X*p1.Y+p.Y*p1.X;
}

bool isE(int x, int x1) {
    if (x % 2 == 0 || x1 % 2 == 0)
        return 1;
    return 0;
}

bool isEven(int x, int y, int x1, int y1) {
    //x*x1+y*y1
    x %= 2;
    y %= 2;
    //o + o
    if (!isE(x, y1) && !isE(x1, y))
        return 1;
    if (isE(x, y1) && isE(x1, y))
        return 1;
    return 0;
}

main() {
    ios_base::sync_with_stdio(false);

    freopen("integral.in","r",stdin);
    freopen("integral.out","w",stdout);
    int n;
    cin >> n;
    int mn=0;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        mn=min(mn,min(x,y));
        v.push_back(point(x, y));
    }

    for(int i=0;i<n;i++){
        v[i].first+=abs(mn);v[i].second+=abs(mn);
    }

    v.push_back(v[0]);



    int ans = 0;
    int area = 0;
    for (int i = 0; i < n; i++) {
        area += detProduct(v[i], v[i + 1]);
    }
    if (area % 2 != 0) {
        cout << 0 << endl;
        return 0;
    }
    int a[2][2][2] = {0};
    int cnt = 0, tmpCnt, tmpL, tmpR;
    int ppl = v[0].X % 2, ppr = v[0].Y % 2, ppcnt = 0;
    int pl = v[0].X % 2, pr = v[0].Y % 2, pcnt = 0;
    for (int i = 0; i < n - 1; i++) {
        if (i + 1 == n - 1) {
            a[0][ppl][ppr]--;
        }
        int curSubArea = detProduct(v[i], v[i + 1]);
    //    cout<<curSubArea<<endl;
        if (curSubArea % 2 != 0)
            cnt++;

        cnt %= 2;
        int add = 0;
        //خدا كاملة او لا تاخدا كاملة
        for (int k = 0; k < 2; k++)
            for (int j = 0; j < 2; j++) {
                if (cnt) {
                    if (isEven(v[i + 1].X, v[i + 1].Y, k, j)) {

                        add += a[1][k][j];
                    } else
                        add += a[0][k][j];
                } else {
                    if (isEven(v[i + 1].X, v[i + 1].Y, k, j)) {
                        add += a[0][k][j];
                    } else {
                        add += a[1][k][j];
                    }
                }
            }

    //    cout << v[i + 1].X << " " << v[i + 1].Y << " " << add << endl;
        ans += add;
        int l = v[i + 1].X % 2, r = v[i + 1].Y % 2;
        //a[cnt][l][r]++;
        a[pcnt][pl][pr]++;
        pl = l;
        pr = r;
        pcnt = cnt;
    }
    cout << ans << endl;
}