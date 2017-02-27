#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int
#define ii pair<int,int>
int a[2000][2000],sm[2000][2000];

main(){
    int t;
    int s;
    ios_base::sync_with_stdio(false);
    while(cin>>t){
        if(t==0){
            cin>>s;
        }
        if(t==1){
            int x,y,m;
            cin>>x>>y>>m;
            x++;y++;
            a[x][y]=m+a[x][y];
            for(int j=y;j<=s;j++)
                sm[x][j]=sm[x][j-1]+a[x][j];
        }
        if(t==2){
            int l,b,r,t;
            cin>>l>>b>>r>>t;
            l++;b++;r++;t++;
            int ans=0;
            for(int i=l;i<=r;i++){
                ans+=sm[i][t]-sm[i][b-1];
            }
            cout<<ans<<endl;
        }
     /*   for(int i=1;i<=s;i++){
            cout<<"Test ";
            for(int j=1;j<=s;j++)
                cout<<a[i][j]<<" ";
            cout<<endl;
        }*/
        if(t==3){
            break;
        }
    }
}
