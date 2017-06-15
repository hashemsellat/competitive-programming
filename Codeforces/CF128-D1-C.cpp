#include<iostream>
using namespace std;
#define int long long int
const int MOD=1e9+7;

int powMod(int a,int b)
{
    if(b==0)
        return 1;
    if(b%2) {
        return (a*powMod(a,b-1))%MOD;
    }
    int tmp=powMod(a,b/2);
    return (tmp*tmp)%MOD;
}
int fact[2000];
int c(int n,int r)
{
    if(r>n)
        return 0;
    int makam=(fact[r]*fact[n-r])%MOD;
    return(fact[n]*powMod(makam,MOD-2))%MOD;
}

main()
{
    fact[0]=1;
    for(int i=1; i<2000; i++) {
        fact[i]=(i*fact[i-1])%MOD;
    }
    int n,m,k;
    cin>>n>>m>>k;
    cout<<(c(n-1,2*k)*c(m-1,2*k))%MOD<<endl;
}
