#include <iostream>
#include <stack>
#include <set>
#include <map>
#include <algorithm>

using namespace std;


const int N = 1e6 + 100;
int q[N], p[N];

#define endl '\n'
main() {
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) {
        scanf("%d",&p[i]);
    }
  /*  int cnt = 1;
    map<int, int> M;
    for (auto x:st) {
        M[x] = cnt++;
    }*/
    int t;
    scanf("%d",&t);
    for (int i = 1; i <= t; i++) {
        scanf("%d",&q[i]);
        //    isNegative[q[i]]=1;
        p[q[i]] *= -1;
    }
    stack<int> s;
    for (int i = n; i >= 1; i--) {
        if (p[i] < 0) {
            s.push(-p[i]);
            //isClose[i]=1;
            continue;
        }
        if (!s.empty()) {
            if (p[i] == s.top()) {
                s.pop();
                continue;
            }
        }
        s.push(p[i]);
        p[i] *= -1;
    }
    if(!s.empty()){
        puts("NO");
        return 0;
    }
    puts("YES");
    for(int i=1;i<=n;i++){
       // cout<<p[i]<<" ";
        printf("%d ",p[i]);
    }
}