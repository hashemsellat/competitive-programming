
#include<bits/stdc++.h>
using namespace std;
int tree[1000100];
#define ii pair<int,int>
#define int long long int
int n,m;
ii a[1000100];
void update(int id,int val){
    while(id<=m){
        tree[id]++;
        id+=(id&(-id));
    }
}
int query(int id){
    int ret=0;
    while(id){
        ret+=tree[id];
        id-=(id&(-id));
    }
    return ret;
}
#define endl '\n'
main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    int cnt=1;
    while(t--){
        memset(a,0,sizeof(a));
        memset(tree,0,sizeof(tree));
        int n,k;
        cin>>n>>m>>k;
        for(int i=0;i<k;i++){
            cin>>a[i].first>>a[i].second;
        }
        int ans=0;
        sort(a,a+k);
        for(int i=0;i<k;i++){
            int u=a[i].first,
                v=a[i].second;

            update(v,1);
            ans+=query(m)-query(v);
          //  cout<<m<<" "<<v<<" "<<query(m)<<" "<<query(v)<<endl;
        }
        cout<<"Test case "<<cnt++<<": "<<ans<<endl;
    }
}
