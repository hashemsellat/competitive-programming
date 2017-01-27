#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define point complex<double>
#define cp(a,b) ((conj(a)*(b)).imag())
#define dp(a,b) ((conj(a)*(b)).real())
#define EPS 1e-10
#define X real()
#define Y imag()
const double PI=2*acos(0);
double angle(point v,point v1){
    double dot=v.X*v1.X+v.Y*v1.Y;
    double det=v.X*v1.Y-v.Y*v1.X;
    return atan2(det,dot);
}
main(){
   // cout<<asin(4.0/5.0)*180/PI<<endl;
    ios_base::sync_with_stdio(false);
    int n;
    double d;
    while(cin>>d>>n){
        if(d==0&&n==0)
            break;
        vector<point> p;
        for(int i=0;i<n;i++)
        {
            double x,y;
            cin>>x>>y;
            p.push_back(point(x,y));
        }
        p.push_back(p[0]);
        p.push_back(p[1]);
        double orginal = 0;
        //now we need the orginal area
        for(int i=0;i<n;i++){
            orginal+=cp(p[i],p[i+1]);
        }
        orginal/=2;
        if(orginal<0)
            orginal*=-1;
        if(d<EPS){
            cout<<fixed<<setprecision(3)<<orginal<<endl;
            continue;
        }
      double pTeta=angle(p[n-1]-p[0],p[1]-p[0]);
      pTeta/=2;
      // cout<<2*pTeta*180/PI<<endl;
        for(int i=0;i<n;i++){
            double curTeta=angle(p[i]-p[i+1],p[i+2]-p[i+1]);
            //cout<<curTeta*180/PI<<endl;
            curTeta/=2;
            //cout<<curTeta*180/PI<<" "<<pTeta*180/PI<<endl;
            double a=d/sin(pTeta);
            double b=d/sin(curTeta);
            double x=a*cos(pTeta);
            double y=b*cos(curTeta);
            //cout<<abs(p[i]-p[i-1])-x-y<<endl;
            orginal-=d*(2*abs(p[i+1]-p[i])-x-y)/2;
            pTeta=curTeta;
        }
        orginal=max(orginal,0.0);
        cout<<fixed<<setprecision(3)<<orginal<<endl;
    }
}
