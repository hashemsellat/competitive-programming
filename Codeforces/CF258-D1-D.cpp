#include <bits/stdc++.h>
using namespace std;
#define  int long long int
const int MAXN=1010;
int a[MAXN];
double e[MAXN][MAXN],tmp[MAXN][MAXN];
main(){
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j])
                e[i][j]=1;
        }
    }

    for(int i=0;i<m;i++){

        int x,y;
        cin>>x>>y;

        x--;y--;
        if(x>y)
            swap(x,y);

        for(int j=x+1;j<y;j++){
            //تبدلو + ما تبدلو
            tmp[x][j]=0.5*(1-e[j][y])+0.5*e[x][j];
            tmp[j][y]=0.5*(1-e[x][j])+0.5*e[j][y];
        }
        for(int j=y+1;j<n;j++){
            tmp[x][j]=0.5*e[y][j]+0.5*e[x][j];
            tmp[y][j]=0.5*e[y][j]+0.5*e[x][j];
            //tmp[y][j]
        }
        for(int j=0;j<x;j++){
            tmp[j][x]=tmp[j][y]=0.5*e[j][x]+0.5*e[j][y];
        }
        e[x][y]=0.5;



        for(int j=x+1;j<y;j++){
            //تبدلو + ما تبدلو
            e[x][j]=tmp[x][j];
            e[j][y]=tmp[j][y];
        }
        for(int j=y+1;j<n;j++){
            e[x][j]=e[y][j]=tmp[x][j];
        }
        for(int j=0;j<x;j++){
            e[j][x]=e[j][y]=tmp[j][x];
        }
       // e[x][y]=tmp[x][y];


    }
    double ans  = 0;
//    for(int i=0;i<n;i++){
//        for(int j=0;j<n;j++){
//            cout<<fixed<<setprecision(4)<<" "<<e[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){

            ans+=e[i][j];
        }
    }
    cout<<fixed<<setprecision(10)<<ans<<endl;
}