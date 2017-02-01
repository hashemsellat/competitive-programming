#include<bits/stdc++.h>
using namespace std;
#define point complex<double>
#define cp(a,b) ((conj(a)*(b)).imag())
#define dp(a,b) ((conj(a)*(b)).real())
#define X real()
#define Y imag()
#define endl '\n'
const double PI=2*acos(0);
const double EPS=1e-9;
double angle(point v,point v1)
{
    double sinT=cp(v,v1)/(abs(v)*abs(v1));
    double cosT=dp(v,v1)/(abs(v)*abs(v1));
    return atan2(sinT,cosT);
}
int n;
bool isEqual(double x,double y){
    if(abs(x-y)<EPS)
        return 1;
    return 0;
}
bool isIntersect(double s,double e,double s1,double e1){
    if(s>e1||s1>e)  return 0;
    return 1;
}
bool f(vector<point> &p){
    p.push_back(p[0]);
    double mnX=1e9,mxX=-1e9,mnY=1e9,mxY=-1e9;
    for(int i=0;i<n;i++){
        mnX=min(mnX,p[i].X);
        mnY=min(mnY,p[i].Y);
        mxX=max(mxX,p[i].X);
        mxY=max(mxY,p[i].Y);
    }
    vector<double> mnXV,mxXV,mnYV,mxYV;
    for(int i=0;i<n;i++){
        if(isEqual(p[i].X,mnX))
            mnXV.push_back(p[i].Y);
        if(isEqual(p[i].X,mxX))
            mxXV.push_back(p[i].Y);
        if(isEqual(p[i].Y,mxY))
            mxYV.push_back(p[i].X);
        if(isEqual(p[i].Y,mnY))
            mnYV.push_back(p[i].X);
    }
    sort(mnYV.begin(),mnYV.end());
    sort(mxYV.begin(),mxYV.end());
    sort(mnXV.begin(),mnXV.end());
    sort(mxXV.begin(),mxXV.end());
    vector<double> v;
    for(int i=1;i<n;i++){
        v.push_back(angle(p[i+1]-p[i],p[i-1]-p[i]));
    }
    int sz=v.size();
    for(int i=0;i<sz-1;i++){
        if(abs(v[i]-PI/2)<EPS&&abs(v[i+1]-PI/2)<EPS)
            return 0;
    }
    if(!isIntersect(mnYV[0],mnYV[1],mxYV[0],mxYV[1])||!isIntersect(mnXV[0],mnXV[1],mxXV[0],mxXV[1]))
        return 0;
    return 1;
}
main(){
  //  cin>>n;
    int cnt=1;
    ios_base::sync_with_stdio(false);
    while(cin>>n){
        if(n==0)
            break;
        vector<point> p;
        for(int i=0;i<n;i++){
            double x,y;
            cin>>x>>y;
            p.push_back(point(x,y));
        }
        cout<<"Floor #"<<cnt++<<endl;
        if(f(p))
            cout<<"Surveillance is possible."<<endl;
        else
            cout<<"Surveillance is impossible."<<endl;
        cout<<endl;
    }
}
