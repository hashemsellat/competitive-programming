#include <iostream>
#include <vector>
#include <cstdlib>
#include <bitset>

#define int long long int
#define endl '\n'
#define  ii pair<int,int>
using namespace std;
#define iii pair<int,ii>
const int N = 3*1e5+ 100;

int n, a[N];

struct node {
    node() {
        zeros = ones = 0;
    }

    int zeros, ones;
};

void update(int v, int l, int r, int i, int j, node tree[], bool lazy[]) {
    if (l > r)
        return;
    if (lazy[v]) {
        swap(tree[v].zeros, tree[v].ones);
        if(l!=r) {
            lazy[2 * v] = !lazy[2 * v];
            lazy[2 * v + 1] = !lazy[2 * v + 1];
        }
        lazy[v] = 0;
    }

    if (l > j || i > r) {
        return;
    }
    if (l >= i && r <= j) {
        swap(tree[v].zeros, tree[v].ones);
        //cout<<"heeeeeeeeeeeer "<<l<<" "<<r<<" "<<tree[v].ones<<" "<<tree[v].zeros<<endl;
        if (l != r) {
            lazy[2 * v] = !lazy[2 * v];
            lazy[2 * v + 1] = !lazy[2 * v + 1];
        }
        return;
    }

    int md = (l + r) / 2;
    update(2 * v, l, md, i, j, tree, lazy);
    update(2 * v + 1, md + 1, r, i, j, tree, lazy);
    tree[v].ones=tree[2*v].ones+tree[2*v+1].ones;
    tree[v].zeros=tree[2*v].zeros+tree[2*v+1].zeros;
}

int query(int v, int l, int r, int i, int j, node tree[], bool lazy[]) {
    if (l > r)
        return 0;
    if (lazy[v]) {
       // cout<<"FSDFD"<<endl;
        swap(tree[v].ones, tree[v].zeros);
        if (l != r) {
            lazy[2 * v] = !lazy[2 * v];
            lazy[2 * v + 1] = !lazy[2 * v + 1];
        }
        lazy[v] = 0;
    }

    if (l > j || r < i)
        return 0;
    if (l >= i && r <= j) {
        return tree[v].ones;
    }
    int md = (l + r) / 2;
    return query(2 * v, l, md, i, j, tree, lazy) + query(2 * v + 1, md + 1, r, i, j, tree, lazy);

}

bool lazy[20][N];
node tree[20][N];

int sum(int l, int r) {
    string foo = "";
    int now=0;
    for (int i = 0; i < 20; i++) {
        int cur= query(1, 0, n - 1, l, r, tree[i], lazy[i]);
        //cout<<"test "<<l<<" "<<r<<" "<<cur<<endl;
        now+=cur;
        foo = char(now % 2 + '0') + foo;
        now/=2;
    }
   // cout<<foo<<endl;
    while(now){
        foo=char(now%2+'0')+foo;
        now/=2;
    }
    //cout<<foo<<endl;
    bitset<60> x(foo);
    return x.to_ullong();
}

void update(int l, int r, int x) {
    int i = 0;
    while (x) {
        if (x % 2) {
            update(1, 0, n - 1, l, r, tree[i], lazy[i]);
        }
        i++;
        x /= 2;
    }
}

node build(int v, int l, int r, int i) {
    if (l == r) {
        tree[i][v].ones = __builtin_popcount(a[l] & (1 << i))!=0;
        tree[i][v].zeros=!tree[i][v].ones;
        //cout<<"sdfsadf "<<i<<" "<<l<<" "<<a[l]<<" "<<tree[i][v].ones<<endl;
        return tree[i][v];
    }
    int md = (l + r) / 2;
    node L = build(2 * v, l, md, i), R = build(2 * v + 1, md + 1, r, i);
    tree[i][v].ones = L.ones + R.ones;
    tree[i][v].zeros = L.zeros + R.zeros;
    return tree[i][v];
}

main() {
   // bitset<20> x("0011");
   // cout<<x.to_ullong()<<endl;
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < 20; i++) {
        build(1, 0, n - 1, i);
    }
    vector<ii > foo;
    vector<iii > hoo;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int t, l, r, x;
        cin >> t;
        if (t == 1) {
            cin >> l >> r;
            l--;
            r--;
            cout << sum(l, r) << endl;
        } else {
            cin >> l >> r >> x;
            l--;
            r--;
            update(l, r, x);
        }
    }


}