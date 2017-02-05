#include<bits/stdc++.h>
using namespace std;
int vis[2][100100];
double dp[2][100100];
double x,l;
double f(bool is,int turn){
    if(vis[is][turn])
        return dp[is][turn];
    if(turn==0)
        if(is==1)
            return 1;
        else
            return 0;
    vis[is][turn]=1;
    double ret=0;
    if(is){
        ret+=(x-l+1)/x*f(1,turn-1);//dont swap
        //cout<<x-l+1<<"/"<<x<<endl;
        ret+=(l-1)/x*f(0,turn-1);//swap
      //  cout<<l-1<<"/"<<x<<endl;
    }
    else{
        ret+=(x-1)/x*f(0,turn-1);//Îáíå ãÇ ÈãÍáæ
        ret+=1/x*f(1,turn-1);//ÑÌÚæ ÚãÍáæ
        //cout<<1<<"/"<<x<<" "<<f(1,turn-1)<<endl;
    }
    return dp[is][turn]=ret;
}
struct RandomSwaps{
    double getProbability(int arrayLength,int swapCount,int a,int b){

        l=arrayLength;
        x=l*(l-1)/2;
       // cout<<x<<endl;
        return f(a==b,swapCount);
    }
};

main(){
    RandomSwaps a;
    cout<<a.getProbability(100,500,3,3)<<endl;
}
