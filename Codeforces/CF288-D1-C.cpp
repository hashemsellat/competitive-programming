#include <iostream>
#include <vector>
#define int long long int
using namespace std;
const int MAXN = 1e6+10;
int ans[MAXN];
int rev(int x){
    int ret=0;
    int cnt=0;
    for(int i=0;i<32;i++){
        if(x&(1<<i)){
            cnt = i;
        }
    }
    for(int i=0;i<cnt;i++){
        if(!(x&(1<<i)))
            ret|=(1<<i);
    }
    return ret;
}
main(){
    int n;
    cin>>n;
    int sm=0;
    for(int i=n;i>=0;i--){
        if(!ans[i]){
            ans[i]=rev(i);
            ans[ans[i]]=i;
        }
        sm+=ans[i]^i;
    }
    cout<<sm<<endl;
    for(int i=0;i<=n;i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}