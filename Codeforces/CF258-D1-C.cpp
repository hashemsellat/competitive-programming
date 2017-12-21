#include <bits/stdc++.h>
#define  int long long int
using namespace std;
#define  endl '\n'
const int MAXN = 1e5+10;

const int MOD = 1e9+ 7;
int pow(int a,int b){
    if(b==0)
        return 1;
    if(b%2){
        return (a*pow(a,b-1))%MOD;
    }
    else
    {
        int tmp=pow(a,b/2);
        return (tmp*tmp)%MOD;
    }
}
main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int mx=0;
    vector<int> a;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
        mx=max(mx,a[i]);
    }
    int ans=0;
    sort(a.begin(),a.end());
    for(int j=1;j<=mx;j++) {
        vector<int> divisors;
        for (int i = 1; i*i <= j; i++) {
            if (j % i == 0) {
                if(i*i!=j){
                    divisors.push_back(i);
                }
                divisors.push_back(j/i);
            }
        }
        sort(divisors.begin(),divisors.end());
        divisors.push_back(mx+1);
        int foo=1;
        for(int i=0;i<divisors.size()-1;i++){
            //number of valid elements are between [ divisors[i],divisors[i+1] [
            int l = lower_bound(a.begin(),a.end(),divisors[i])-divisors.begin();
            int r = lower_bound(a.begin(),a.end(),divisors[i+1])-divisors.begin();
            int cur = r-l;
            int mult;
            mult = pow(i+1,cur);
            if(divisors[i]==j)
                mult-=pow(i,cur);
            (mult+=MOD)%=MOD;
            (foo*=mult)%=MOD;

        }
    //    cout<<j<<" "<<foo<<endl;
        (ans+=foo)%=MOD;
    }
    cout<<ans<<endl;
}