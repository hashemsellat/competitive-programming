#include<bits/stdc++.h>
using namespace std;
#define double long double
#define point complex<double>
#define PI (2*acos(0))
#define dp(a,b)  ((conj(a)*(b)).real())
#define X real()
#define Y imag()
void in(point &p){
    double x,y;
    cin>>x>>y;
    p=point(x,y);
}


main(){
    freopen("C:/Users/HashemH/Desktop/out.txt","w",stdout);
    freopen("C:/Users/HashemH/Desktop/in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
        while(n--){
        point a,b;
        double r;
        in(a);in(b);
        cin>>r;
       // cout<<dp(a-c,b-c)<<endl;
       // cout<<180.0/PI*(acos(dp(a-c,b-c)/(abs(a-c)*abs(b-c))))<<endl;
        if(a.Y<b.Y) swap(a,b);
        if(abs(a.X-b.X)==0){
            if(a.X>=-r&&a.X<=r){
                double tmp=r*r-a.X*a.X;
                if(tmp<0)
                    tmp*=-1;
                double y1=sqrt(tmp);
                double y2=-sqrt(tmp);
                if(y1<=a.Y&&y1>=b.Y&&y2<=a.Y&&y2>=b.Y){
                }
                else{
                   // cout<<"DONE"<<endl;
                    cout<<fixed<<setprecision(3)<<abs(a-b)<<endl;
                    continue;
                }
            }
            else{
               // cout<<"DONE"<<endl;
                cout<<fixed<<setprecision(3)<<abs(a-b)<<endl;
                continue;
            }
        }
        else{
            if(a.X<b.X)
                swap(a,b);
            double m=(a.Y-b.Y)/(a.X-b.X);
            double cc=a.Y-m*a.X;
            double d=m*m+1,e=2*m*cc,f=(cc*cc-r*r);
            double delta=e*e-4*d*f;
            if(delta<0){
              //  cout<<"HOO"<<endl;
                cout<<fixed<<setprecision(3)<<abs(a-b)<<endl;
                continue;
            }
          //  cout<<e<<" "<<d<<" "<<delta<<endl;
            double x1=(-e+sqrt(delta))/(2*d);
            double x2=(-e-sqrt(delta))/(2*d);
            //cout<<x1<<" "<<x2<<endl;
            if(x1<=a.X&&x1>=b.X&&x2<=a.X&&x2>=b.X){
              //  cout<<y1<<" "<<y2<<endl;
            }
            else
            {
              //  cout<<y1<<" "<<y2<<endl;
              //  cout<<"DSO"<<endl;
                cout<<fixed<<setprecision(3)<<abs(a-b)<<endl;
                continue;
            }
          //  cout<<"FOO"<<" "<<y1<<" "<<y2<<endl;
        }
      //  cout<<"HOO"<<endl;
        point zero(0,0);
        double watar=abs(zero-b);
       // cout<<watar<<endl;
        double f=sqrt(watar*watar-r*r);
        watar=abs(zero-a);
       // cout<<watar<<endl;
        double d=sqrt(watar*watar-r*r);
      //  cout<<f<<" "<<d<<endl;
        double angle=acos(dp(b,a)/(abs(a)*abs(b)));
       // cout<<angle*180/PI<<endl;
        angle-=acos(r/abs(b))+acos(r/abs(a));
        angle*=180.0/PI;
      //  cout<<angle<<endl;
        cout<<fixed<<setprecision(3)<<f+d+2*PI*r*angle/360<<endl;
    }
}
