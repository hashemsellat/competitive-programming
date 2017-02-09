#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int MOD = 1e9+7;
const int N   = 1e7  ;
bool check[N];
int intlog(double base,double x){
    return log(x)/log(base);
}
int power(int a,int b){
    if(b==0)
        return 1;
    if(b%2==1){
        return (a*power(a,b-1))%MOD;
    }
    else{
        int tmp=power(a,b/2);
        return (tmp*tmp)%MOD;
    }
}
#define endl '\n'
main(){
    int n;
    vector<int> prms;
    for(int i=2;i<=N/2;i++){
        if(!check[i]){
            //cout<<i<<endl;
            //system("pause");
            prms.push_back(i);
            for(int j=2*i;j<=N/2;j+=i){
                check[j]=1;
            }
        }
    }
    ios_base::sync_with_stdio(false);
    int sz=prms.size();
    //cout<<sz<<endl;
    //system("pause");
    while(cin>>n){
        if(n==0)
            break;
        int ans=1;
        for(int i=0;i<sz;i++){
            int cur=prms[i];
            int sm=0;
            if(n/cur==0)    break;
            while(n/cur!=0){
                sm+=n/cur;
                cur*=prms[i];
            }
            if(sm%2==1)
                sm--;
            //cout<<prms[i]<<" "<<sm<<" "<<ans<<endl;
            //system("pause");
            ans*=power(prms[i],sm);
            ans%=MOD;
        }
        cout<<ans<<endl;
    }
}
