#include<bits/stdc++.h>
using namespace std;
#define point complex<double>
#define cp(a,b) ((conj(a)*(b)).imag())
#define dp(a,b) ((conj(a)*(b)).real())
#define X real()
#define Y imag()
#define endl '\n'
double dist[100][100];
bool is[100][100];
const double EPS=1e-9;
bool isEqual(double x,double y){
    return abs(x-y)<EPS;
}
main(){
    freopen("out.txt","w",stdout);
    freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int n,m;
    while(cin>>n>>m){
        memset(is,0,sizeof(is));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                if(i!=j)
                    dist[i][j]=1e9;
                else
                    dist[i][i]=0;
            }
        vector<point> p;
        if(n==0&&m==0)
            break;
        for(int i=0;i<n;i++){
            double x,y;
            cin>>x>>y;
            p.push_back(point(x,y));
        }
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            u--;v--;
            is[u][v]=is[v][u]=1;
            dist[u][v]=dist[v][u]=abs(p[u]-p[v]);
        }
        double mx=0;
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++){
                    dist[i][j]=min(dist[i][k]+dist[k][j],dist[i][j]);
                }
        }
        //OK
        int u=0,v=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(is[i][j])
                    continue;
                double ad=abs(p[i]-p[j]);
                double curSum=0,pSum=0;
                for(int k=0;k<n;k++)
                    for(int l=0;l<n;l++)
                    {
                        pSum+=dist[k][l];
                        curSum+=dist[k][l]-min(dist[l][k],min(ad+dist[l][i]+dist[j][k],ad+dist[k][i]+dist[j][l]));
                    }
                if(curSum>0&&curSum>mx+EPS){
                    mx=curSum;u=i;v=j;
                }
            }
        }

        if(mx<=1.0+EPS){
            cout<<"No road required"<<endl;
        }
        else
            cout<<u+1<<" "<<v+1<<endl;
    }

}
