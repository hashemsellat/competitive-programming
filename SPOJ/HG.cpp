#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int
const int MOD=1e9;
bool f;
int powMod(int a,int b){
    if(b==0)
        return 1;
    if(b%2==1){
        int cur=a*powMod(a,b-1);
        if(cur>=MOD)
            f=1;
        return cur%MOD;
    }
    int tmp=powMod(a,b/2);
    int cur=tmp*tmp;
    if(cur>=MOD)
        f=1;
    return cur%MOD;
}
main(){
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n;
    map<int,int> M,M1;
    for(int i=0;i<n;i++){
       // cout<<"DSF "<<endl;
        int x;
        x=1e9;
        cin>>x;
        for(int j=2;j*j<=x;j++){
            if(x%j==0){
                int cnt=0;
                while(x%j==0){
                    cnt++;
                    x/=j;
                }
                M[j]+=cnt;
            }
        }
        if(x!=1){
            M[x]++;
        }
    }
    cin>>m;
    for(int i=0;i<m;i++){
      //  cout<<"DSF JDSF "<<endl;
        int x;
        cin>>x;
        //x=1e9;
        for(int j=2;j*j<=x;j++){
            if(x%j==0){
                int cnt=0;
                while(x%j==0){
                    cnt++;
                    x/=j;
                }
                M1[j]+=cnt;
            }
        }
        if(x!=1){
            M1[x]++;
        }
    }
    map<int,int>::iterator it=(M.begin());
    int ans=1;
    for(it;it!=M.end();it++){
        int k=it->first,value=it->second;
        if(M1[k])
            ans*=powMod(k,min(value,M1[k]));
        if(ans>=MOD)
            f=1;
        ans%=MOD;
    }
    stringstream ss;
    ss<<ans;
    string res=ss.str();
    if(f){
        while(res.size()<9)
            res="0"+res;
    }
    cout<<res<<endl;
}
