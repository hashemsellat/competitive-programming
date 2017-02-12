#include<bits/stdc++.h>
using namespace std;

#define N int(1e6)

int n,m,k;

int sparse_table[N][31];
int a[N];
int v[N];
int main(){
    cin>>n>>k>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=k;i++)
        cin>>v[i];
    for(int i=1;i<=k;i++)
        sparse_table[i][0]=i;
    for(int i=1;i<=(log2(m)+0.01);i++){
        for(int j=1;j<=k;j++){
          //  cout<<v[sparse_table[sparse_table[j][i-1]][j-1]]<<endl;
            sparse_table[j][i]=v[sparse_table[sparse_table[j][i-1]][i-1]];
        }
    }

    /*for(int j=1;j<=k;j++){
        for(int i=0;i<=(log2(m)+0.01);i++){
            cout<<sparse_table[j][i]<<" ";
        }
        cout<<endl;
    }*/
    for(int i=1;i<=n;i++){
        int now=m;
        int step;
        step=a[i];
        for(int i=(log2(now)+0.01);i>=0;i--){
            if((1<<i)<now){
               // cout<<(1<<i)<<" "<<now<<endl;
                now-=(1<<i);
                step=sparse_table[step][i];
                step=sparse_table[step][1];
            }
            //cout<<now<<endl;
        }
        cout<<step;
        if(i==n)    cout<<endl;
        else        cout<<" ";
    }
}
