#include<bits/stdc++.h>
using namespace std;
double dp[45][45][45];
const double pi=2*acos(0);
double a[100];
int m,n;
double f(int cur,int start,int cnt){
   // cout<<cur<<" "<<start<<" "<<cnt<<endl;
    double sangle=(a[cur]-a[start])*2*pi;
    if(cnt==m){

        if(sangle<pi){
            return -1.0/2.0*sin(sangle);
        }
        else{
            sangle=2*pi-sangle;
            return 1.0/2.0*sin(sangle);
        }
    }
    if(dp[cur][start][cnt]==dp[cur][start][cnt])
        return dp[cur][start][cnt];
    double ret=-1e9;
    for(int i=cur+1;i<n;i++){
        double nangle=(a[i]-a[cur])*2*pi;
        //take it
        if(nangle<=pi){
            ret=max(ret,1.0/2.0*sin(nangle)+f(i,start,cnt+1));
        }
        else{
            nangle=2*pi-nangle;
            ret=max(ret,-1.0/2.0*sin(nangle)+f(i,start,cnt+1));
        }
    }
    return dp[cur][start][cnt]=ret;
}
main(){
    while(cin>>n>>m){
        if(n==0&&m==0)
            break;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        double ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,f(i,i,1));
           // cout<<endl;
        }
        cout<<fixed<<setprecision(6)<<ans<<endl;
    }
}
