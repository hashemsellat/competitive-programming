/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: hashem
 *
 * Created on October 21, 2017, 11:03 PM
 */

#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e5;
int all = 0;

int a[MAXN], tree[MAXN], rev[MAXN];
int cnt[40000];
#define endl '\n'

void build(int node, int l, int r) {

    if (l == r) {
        rev[r] = node;
        tree[node] = 0;
        return;
    }
    int md = (l + r) / 2;
    build(2 * node, l, md);
    build(2 * node + 1, md + 1, r);
}

int query(int node, int l, int r, int x) {
    int md = (l + r) / 2;
    if (l == r)
        return l;
    if (x == 0) {
        if (tree[2 * node + 1] != 0) {
            return query(2 * node + 1, md + 1, r, 0);
        } else {
            return query(2 * node, l, md, 0);
        }
    }
    if (tree[2 * node] >= x) {
        return query(2 * node, l, md, x);
    } else {
        return query(2 * node + 1, md + 1, r, x - tree[2 * node]);
    }
}

void update(int id) {
    int node = rev[id];
    tree[node] = 1;
    node /= 2;
    while (node) {
        tree[node] = tree[2 * node] + tree[2 * node + 1];
        node /= 2;
    }
}
int orginal[MAXN];

main() {
   // freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int k;
    cin>>k;
    bool is = 0;
    for (int i = 0; i < k; i++) {
        all = 0;
        memset(cnt, 0, sizeof (cnt));
        memset(tree, 0, sizeof (tree));
        if (is)
            cout << endl;
        is = 1;
        int m, n;
        cin >> m>>n;
        set<int> s;
        map<int, vector<int> > adj;
        for (int i = 0; i < m; i++) {
            cin >> a[i];
            adj[a[i]].push_back(i);
            s.insert(a[i]);
        }
        for (auto x : s) {
            for (auto y : adj[x]) {
                a[y] = all++;
                orginal[all - 1] = x;
            }
        }

        //        for(int i=0;i<m;i++){
        //            cout<<a[i]<<" ";
        //        }
        //        cout<<endl;

        for (int j = 0; j < n; j++) {
            int x;
            cin>>x;
            cnt[x]++;
        }
        build(1, 0, all);
        int counter = 0;
        for (int i = 0; i <=m; i++) {
            while (cnt[i]) {
                counter++;
                int x = query(1, 0, all, counter);
                cout << orginal[x] << endl;
                cnt[i]--;
            }
            update(a[i]);
            //            for(int i=0;i<all;i++){
            //                cout<<foo[i]<<" ";
            //            }
            //            cout<<endl;
        }
//        cout<<endl;
    }
}
