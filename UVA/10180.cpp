#include<bits/stdc++.h>
using namespace std;
//#define long double long long double
#define point complex<long double>
#define PI (2*acos(0))
#define dp(a,b)  ((conj(a)*(b)).real())
#define X real()
#define Y imag()
#define endl '\n'
#define EPS 1e-5
//#define long double long long double
void in(point &p){
    long double x,y;
    cin>>x>>y;
    p=point(x,y);
}


main(){
 //   freopen("C:/Users/HashemH/Desktop/out.txt","w",stdout);
 //   freopen("C:/Users/HashemH/Desktop/in.txt","r",stdin);
    int cnt=0;
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    while(n--){
        point a,b;
        long double r;
        in(a);in(b);
        cin>>r;
        if(r==0){
            cout<<fixed<<setprecision(3)<<abs(a-b)<<endl;continue;
        }
        if(a.Y<b.Y) swap(a,b);
        if(abs(a.X-b.X)<EPS){
            if(a.X>=-r&&a.X<=r){
                long double tmp=r*r-a.X*a.X;
                if(tmp<0)
                    tmp*=-1;
                long double y1=sqrt(tmp);
                long double y2=-sqrt(tmp);
                if(y1<=a.Y+EPS&&y1>=b.Y-EPS&&y2<=a.Y+EPS&&y2>=b.Y-EPS){
                }
                else{
                    cout<<fixed<<setprecision(3)<<abs(a-b)<<endl;
                    continue;
                }
            }
            else{
                cout<<fixed<<setprecision(3)<<abs(a-b)<<endl;
                continue;
            }
        }
        else{
            if(a.X<b.X)
                swap(a,b);
            long double m=(a.Y-b.Y)/(a.X-b.X);
            long double cc=a.Y-m*a.X;
            long double d=m*m+1,e=2*m*cc,f=(cc*cc-r*r);
            long double delta=e*e-4*d*f;
            if(delta<0){
                cout<<fixed<<setprecision(3)<<abs(a-b)<<endl;
                continue;
            }
            long double x1=(-e+sqrt(delta))/(2*d);
            long double x2=(-e-sqrt(delta))/(2*d);
            if(x1<=a.X+EPS&&x1>=b.X-EPS&&x2<=a.X+EPS&&x2>=b.X-EPS){
            }
            else
            {
                cout<<fixed<<setprecision(3)<<abs(a-b)<<endl;
                continue;
            }
        }
        point zero(0,0);
        long double watar=abs(zero-b);
        long double f=sqrt(watar*watar-r*r);
        watar=abs(zero-a);
        long double d=sqrt(watar*watar-r*r);
        double o=dp(a,b)/(abs(a)*abs(b));
        long double angle=acos(o);
        angle-=acos(r/abs(b))+acos(r/abs(a));
        angle*=180.0/PI;
        cout<<fixed<<setprecision(3)<<f+d+2*PI*r*angle/360<<endl;
    }
}
