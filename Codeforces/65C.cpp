#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define point pair<double,pair<double,double> >
#define X first
#define Y second.first
#define Z second.second
const double EPS=1e-12;
point p[100000];
double dist(point p1,point p2)
{
    return sqrt(pow(p1.X-p2.X,2)+pow(p1.Y-p2.Y,2)+pow(p1.Z-p2.Z,2));
}
main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    double total=0;
    for(int i=0; i<n+1; i++)
    {

        cin>>p[i].X>>p[i].Y>>p[i].Z;
        if(i!=0)
            total+=dist(p[i],p[i-1]);
    }
    double vt,vs;
    cin>>vt>>vs;
    point t;
    cin>>t.X>>t.Y>>t.Z;
    // cout<<total/vs<<" "<<dist(t,p[n])/vt<<endl;
    if(total/vs<dist(t,p[n])/vt)
    {
        cout<<"NO"<<endl;
        return 0;
    }

    int i=n;
    // cout<<total/vs<<" "<<dist(t,p[i])/vt<<endl;
    while(total/vs>dist(t,p[i])/vt-EPS&&i>0)
    {
        //  cout<<"HOO"<<endl;
        total-=dist(p[i],p[i-1]);
        i--;
    }

    double dd=dist(p[i],p[i+1]);
    // cout<<i<<" "<<dd<<endl;
    double mn=0,mx=dd;
    point ans;
    double afff;
    for(int j=0; j<1000; j++)
    {
        point nxt;
        double md=(mn+mx)/2;

        nxt.X=(p[i+1].X-p[i].X)*md/dd+p[i].X;
        nxt.Y=(p[i+1].Y-p[i].Y)*md/dd+p[i].Y;
        nxt.Z=(p[i+1].Z-p[i].Z)*md/dd+p[i].Z;
        if((total+md)/vs>=dist(t,nxt)/vt-EPS)
        {
            ans=nxt;
            afff=(total+md)/vs;
            mx=md;
        }
        else
            mn=md;
    }
    cout<<"YES"<<endl;
    cout<<fixed<<setprecision(10)<<afff<<endl<<ans.X<<" "<<ans.Y<<" "<<ans.Z<<endl;
    //i , i+1

}
