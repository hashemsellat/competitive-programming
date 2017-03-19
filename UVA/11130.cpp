/*
    we simulate the movement of the ball
    first we calculate the average speed of the ball (v-v0)/2
    the speed on x axis should be (v*cos(A))
    the speed on y axis should be (v*sin(A))

    we maintain some variables
        curx: the current x position of the ball
        cury: the current y position
        dx:   the speed on x axis
        dy:   the speed on y axis

    when the ball hits the side parallel to the x axis it reflect with an angle 45degree so dy becomes -dy
    the same thing happens when the ball hits the side parallel to the y axis but dx becomes -dx
*/

#include<bits/stdc++.h>
using namespace std;
const double PI=2*acos(0);
const double EPS=1e-9;
bool isEqual(double x,double y)
{
    return abs(x-y)<EPS;
}
double curx,cury,dx,dy,a,b,s,dd;
bool f(int c,double e,double &ret,double &cs)
{
    if(c==1)
    {
        //y work
        //y = e , ret=x;
        if(isEqual(dy,0)||isEqual(cury,e))
            return 0;

        double t=(e-cury)/dy;

        //cout<<"test1 "<<t<<" "<<curx<<" "<<cury<<" "<<e<<" "<<dy<<endl;
        if(abs(t)>s+EPS||t<=0)
        {
            cs=0;
            return 0;
        }
        //cout<<"HOO"<<endl;
        ret=curx+dx*t;
        cs=s-abs(t);
        if(ret+EPS<-a/2||ret>a/2+EPS)
            return 0;
        return 1;
    }
    else
    {
        if(isEqual(dx,0)||isEqual(curx,e))
            return 0;
        double t=(e-curx)/dx;
        if(abs(t)>s+EPS||t<=0)
        {
            return 0;
        }
        cs=s-abs(t);
        ret=cury+dy*t;
        if(ret+EPS<-b/2||ret>b/2+EPS)   return 0;
        return 1;
    }

}
main()
{

    double v,A;
    while(cin>>a>>b>>v>>A>>s)
    {
        if(a==0&&b==0&&v==0&&A==0&&s==0)
            break;
        curx=0;
        cury=0;
        A*=PI/180;
        v=1.0/2*v;
        dx=v*cos(A);
        dy=v*sin(A);
        int l=0,r=0;
        while(1)
        {
        //    cout<<curx<< " "<<cury<<endl;
            double cdx,cdy,cs,ccurx,ccury,tmp,x,y;
            bool is=0;
            if(f(1,b/2,x,tmp))
            {
             //   cout<<"one"<<endl;
                is=1;
                l++;
                ccurx=x;
                ccury=b/2;
                cdx=dx;
                cdy=-dy;
                cs=tmp;
            }
            else
            if(f(1,-b/2,x,tmp))
            {
               // cout<<"two"<<endl;
                is=1;
                l++;
                ccurx=x;
                ccury=-b/2;
                cdx=dx;
                cdy=-dy;
                cs=tmp;
            }

            if(f(0,a/2,y,tmp))
            {
              //  cout<<"three"<<endl;
                is=1;
                r++;
                ccurx=a/2;
                ccury=y;
                cdx=-dx;
                cdy=dy;
                cs=tmp;
            }
            else
            if(f(0,-a/2,y,tmp))
            {
               // cout<<"four"<<endl;
                is=1;
                r++;
                ccurx=-a/2;
                ccury=y;
                cdx=-dx;
                cdy=dy;
                cs=tmp;
            }
            if(!is) break;
            //cout<<cs<<endl;
            dx=cdx;
            dy=cdy;
            s=cs;
            curx=ccurx;
            cury=ccury;
        }
        cout<<r<<" "<<l<<endl;
    }
}
