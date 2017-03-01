#include<bits/stdc++.h>
using namespace std;
#define point complex<double>
#define X real()
#define Y imag()
const double EPS=1e-9;
const double PI=2*acos(0);
bool isEqual(double x,double y)
{
    return abs(x-y)<EPS;
}
main()
{
    int n;
    int cnt=0;
    while(cin>>n)
    {
        if(n==0)    break;
        vector<point> p;
        for(int i=0; i<3; i++)
        {
            double x,y;
            cin>>x>>y;
            p.push_back(point(x,y));
            //0 1 0 2 1 2
        }
        point A,B,C;
        A=p[0];
        B=p[1];
        C=p[2];
        if(isEqual(A.X,C.X))
            swap(B,C);
        point ret;
        if(isEqual(A.X,B.X))
        {
            if(isEqual(A.Y,C.Y))
            {
                ret=point((A.X+C.X)/2,(A.Y+B.Y)/2);
            }
            else
            {
                double curY=(A.Y+B.Y)/2;
                point MIDAC((A.X+C.X)/2,(A.Y+C.Y)/2);
                //we have a point now we should calculate the line
                //y=mx+c
                double m=(A.Y-C.Y)/(A.X-C.X);
                double mm=-(1/m);
                double cc=MIDAC.Y-mm*MIDAC.X;
                ret=point((curY-cc)/mm,curY);
            }
            //seams OK
        }
        else
        {
            if(isEqual(A.Y,C.Y))
                swap(B,C);

            if(isEqual(A.Y,B.Y))
            {
                double curx=(A.X+B.X)/2;
                point MIDAC((A.X+C.X)/2,(A.Y+C.Y)/2);
                //we have a point now we should calculate the line
                //y=mx+c
                double m=(A.Y-C.Y)/(A.X-C.X);
                double mm=-(1/m);
                double cc=MIDAC.Y-mm*MIDAC.X;
                ret=point(curx,mm*curx+cc);
            }
            else
            {
                //ÿ·⁄ „⁄«œ· Ì‰ Ê«‘ €·
                //y=mx+c AB
                //y=mmx+cc  AC
                //(cc-c)/(m-mm)=x
                //y=prvx*m+c
                // cout<<"NIAO"<<endl;
                point MDAB((A.X+B.X)/2,(A.Y+B.Y)/2);
                point MDAC((A.X+C.X)/2,(A.Y+C.Y)/2);
                double m=-1/((A.Y-B.Y)/(A.X-B.X));
                double mm=-1/((A.Y-C.Y)/(A.X-C.X));

                double c=MDAB.Y-m*MDAB.X;
                double cc=MDAC.Y-mm*MDAC.X;

                double curx=(cc-c)/(m-mm);

                ret=point(curx,curx*mm+cc);
            }
        }
        //   cout<<fixed<<setprecision(3)<<ret.X<<" "<<ret.Y<<endl;
        double tmp=2*abs(ret-B);
        //  cout<<tmp*tmp<<endl;
        point cur(A.X-ret.X,A.Y-ret.Y);
        double teta=(2*PI)/(n);
        double mnx=cur.X,mny=cur.Y,mxx=cur.X,mxy=cur.Y;
        for(int i=0; i<n; i++)
        {
            point tmp=cur;
            cur=point(tmp.X*cos(teta)-tmp.Y*sin(teta),
                      tmp.X*sin(teta)+tmp.Y*cos(teta));
            mnx=min(mnx,cur.X);
            mny=min(mny,cur.Y);
            mxx=max(mxx,cur.X);
            mxy=max(mxy,cur.Y);
        }
        cout<<"Polygon "<<++cnt<<": ";
        cout<<fixed<<setprecision(3)<<(mxx-mnx)*(mxy-mny)<<endl;
    }

}
