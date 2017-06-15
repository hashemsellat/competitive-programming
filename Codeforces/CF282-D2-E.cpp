#include <iostream>
#include <cstring>
#include <bitset>
#include <cstdio>
#include <cstdlib>

using namespace std;
#define  int long long int
const int N = 1e6;

int a[N];
int BinaryToInt(string &s){
    int ret=0;
    int sz=s.size();
    for(int i=0;i<sz;i++){
        ret+=(1LL<<(sz-i-1))*(s[i]-'0');
    }
    return ret;
}

struct node {
    node *child[2];
    int mx;

    node() {
        mx = 0;
        memset(child, 0, sizeof(child));
    }
} *head;



void add(int s, int id) {
    node *it = head;
    for (int i = 42;i>=0 ;i--) {
        bool cur = s&(1LL<<i);
        if (!it->child[cur]) {
            it->child[cur] = new node();
            it->child[cur]->mx = id;
        }
        it = it->child[cur];
    }
}


int getMax(int s, int id) {
    node *it = head;
    string ret = "";
    for (int i=42;i>=0 ;i--) {
        bool cur = s&(1LL<<i);
        if (it->child[!cur] && (it->child[!cur]->mx) > id) {
            ret = ret + '1';
            it = it->child[!cur];
        } else {
            ret = ret + '0';
            it = it->child[cur];
        }
    }
    return BinaryToInt(ret);
}

#define  endl '\n'

main() {
    head = new node();
  //  ios_base::sync_with_stdio(false);
    int n;
    //cin >> n;
    scanf("%lld",&n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld",&a[i]);
        //a[i]=1e9;
        ans = ans ^ a[i];
    }
    add(0, 1e9);
    int cur = 0;
    for (int i = n - 1; i >= 0; i--) {
        cur = (cur ^ a[i]);
        ans=max(ans,cur);
        add(cur, i);
    }
    cur = 0;
   // cout<<ans<<endl;
    for (int i = 0; i < n; i++) {
        cur = cur ^ a[i];
        ans=max(ans,cur);
        ans = max(ans, getMax(cur, i));
    }
    printf("%lld\n",ans);
}