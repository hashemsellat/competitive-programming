#include<bits/stdc++.h>
#define point complex<double>
#define ii pair<int,int>
#define iii pair<int,ii>
#define endl '\n'
#define X real()
#define Y imag()
#define cp(a,b) ((conj(a)*(b)).imag())
using namespace std;
const double EPS=1e-5;
bool isEqual(double x,double y)
{
    return abs(x-y)<EPS;
}
double polygonArea(vector<point> &p)
{
    double ret=0;
    for(int i=0; i<p.size(); i++)
    {
        int j=(i+1)%(p.size());
        ret+=cp(p[i],p[j]);
    }
    return abs(ret)/2;
}
point intersect(point a,point b,point p,point q)
{
    point ret;
    if(isEqual(q.X,p.X))
    {
        swap(a,p);
        swap(b,q);
    }
    if(a.X==b.X)
    {
        //the two point p & q
        double mm=(p.Y-q.Y)/(p.X-q.X);
        double cc=p.Y-mm*p.X;
        //ret.X=a.X;
        //ret.Y=mm*a.X+cc;
        ret=point(a.X,mm*a.X+cc);
    }
    else
    {
        double m=(a.Y-b.Y)/(a.X-b.X);
        double c=a.Y-m*a.X;

        double mm=(p.Y-q.Y)/(p.X-q.X);
        double cc=p.Y-mm*p.X;

        double x=(cc-c)/(m-mm);
        ret=point(x,m*x+c);
    }
    return ret;
}
main()
{
    int n;
    ios_base::sync_with_stdio(false);
    cin>>n;
    while(n--)
    {
        point A,B,C;
        double x,y;
        cin>>x>>y;
        A=point(x,y);
        cin>>x>>y;
        B=point(x,y);
        cin>>x>>y;
        C=point(x,y);
        point D(B.X+1.0/3*(C.X-B.X),B.Y+1.0/3*(C.Y-B.Y));
        point E(C.X+1.0/3*(A.X-C.X),C.Y+1.0/3*(A.Y-C.Y));
        point F(A.X+1.0/3*(B.X-A.X),A.Y+1.0/3*(B.Y-A.Y));

        vector<point> v;
        point R=intersect(A,D,C,F);
        point P=intersect(A,D,E,B);
        point Q=intersect(B,E,C,F);
        v.push_back(R);
        v.push_back(Q);
        v.push_back(P);
        int ans=polygonArea(v)+0.5;
        cout<<ans<<endl;
    }
}
