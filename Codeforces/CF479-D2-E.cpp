#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int MOD=1e9+7;
const int N=5010;
  int n,a,b,k;
/*
    WARING::
    don't continue reading from here because this is the stupidest edit i've Ever made
*/
void update(int x,int val,int tree[]){
    tree[x]+=val;
}

int get(int x,int tree[]){
    return tree[x];
}
int query(int l,int r,int tree[]){
    if(l>r) return 0;
    return (2*MOD+get(r,tree)-get(max(0LL,l-1),tree))%MOD;
}
int tree[N][N];
main(){
    ios_base::sync_with_stdio(false);

    cin>>n>>a>>b>>k;

    for(int i=1;i<=n;i++){
        if((a<b&&i<b||a>b&&i>b)){
            update(i,1,tree[0]);
         //   cout<<"FOO "<<i<<endl;
        }
    }
    for(int i=1;i<=n;i++){
        tree[0][i]=tree[0][i]+tree[0][i-1];
    }
    int ans=0;
    for(int e=1;e<=k;e++){
        for(int i=1;i<=n;i++){
            int foo=abs(i-b)-1;
            //max(0,i-foo) to min(n,i+foo)
            int now;
            if(e==1){
             //   int now=(get(min(n,i+foo),tree[e-1])-get(max(0LL,i-foo),tree[e-1])+2*MOD)%MOD;
            //    cout<<"Too"<<endl;
                now=(query(max(0LL,i-foo),min(n,i+foo),tree[e-1])-query(i,i,tree[e-1])+2*MOD)%MOD;
              //  cout<<"foo"<<endl;
                update(i,now,tree[e]);
                if(e==k&&i==a)
                    ans=now;
                if(e==k&&i==a)
                    ans=now;
            }
            else{
                int l,r;
                if(i>b){
                    l=max(i-foo,b+2);
                    r=min(n,i+foo);
                }
                else{
                    l=max(0LL,i-foo);
                    r=min(i+foo,b-2);
                }
                now=(query(l,r,tree[e-1])-query(i,i,tree[e-1])+2*MOD)%MOD;
                update(i,now,tree[e]);
                if(e==k&&i==a)
                    ans=now;
            }
        //    cout<<e<<" "<<i<<" "<<now<<endl;


            }
            for(int i=1;i<=n;i++){
                tree[e][i]=tree[e][i]+tree[e][i-1];
            }
    }
    cout<<ans<<endl;
}