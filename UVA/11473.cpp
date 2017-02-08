    #include<bits/stdc++.h>
    using namespace std;
    #define point complex<double>
    #define X real()
    #define Y imag()
    #define fixed fixed<<setprecision(2)
    #define double long double
    const double EPS=1e-5;
    const double EPS2=1e-12;
    bool isEqual2(double x,double y){
        return abs(x-y)<EPS2;
    }
    bool isEqual(double x,double y)
    {
        return abs(x-y)<EPS;
    }
    bool isBetween(point l,point r,point p)
    {
        if(isEqual(abs(l-r),abs(l-p)+abs(r-p)))
            return 1;
        return 0;
    }
    point p[111];
    #define endl '\n'
    main()
    {
     //   freopen("out.txt","w",stdout);
        /* double x,y,x1,y1;
         cin>>x>>y>>x1>>y1;
         point a(x,y),b(x1,y1);
         cout<<abs(a-b)<<endl;*/
        ios_base::sync_with_stdio(false);
        int t;
        cin>>t;
        int cnt=1;
        while(t--)
        {

            int n,T;
            cin>>n>>T;
            double D=0;
            for(int i=0; i<n; i++)
            {
                double x,y;
                cin>>x>>y;
                p[i]=point(x,y);
                if(i!=0)
                    D+=abs(p[i]-p[i-1]);
            }
            D/=(T-1);
            //   cout<<D<<endl;
            double d=D;
            int nxt=1;
            point now=p[0];
            cout<<"Road #"<<cnt++<<":"<<endl;
            cout<<fixed<<now.X<<" "<<now.Y<<endl;
            while(nxt!=n)
            {
                point r0,r1;
                if(now.X!=p[nxt].X){
                    double m=(p[nxt].Y-now.Y)/(p[nxt].X-now.X);
                    double c=p[nxt].Y-m*p[nxt].X;
                    double a=(m*m+1);
                    double b=-2*now.X-2*now.Y*m+2*m*c;
                    double cc=c*c-d*d+now.X*now.X+now.Y*now.Y-2*now.Y*c;
                    double delta=b*b-4*a*cc;
                    double x2_0=(-b+sqrt(delta))/(2*a);
                    double x2_1=(-b-sqrt(delta))/(2*a);
                    r0=point(x2_0,m*x2_0+c);
                    r1=point(x2_1,m*x2_1+c);
                }
                else
                {
                    r0=point(p[nxt].X,now.Y+d);
                    r1=point(p[nxt].X,now.Y-d);
                }
                if(isBetween(now,p[nxt],r0))
                {
                    // cout<<"FOO"<<endl;
                    cout<<fixed<<r0.X<<" "<<r0.Y<<endl;
                    now=r0;
                    d=D;
                }
                else if(isBetween(now,p[nxt],r1))
                {
                    // cout<<"NIA"<<endl;
                    cout<<fixed<<r1.X<<" "<<r1.Y<<endl;
                    now=r1;
                    d=D;
                }
                else
                {
                    //cout<<fixed<<p[nxt].X<<" "<<p[nxt].Y<<endl;
                    d-=abs(p[nxt]-now);
                    if(d<0) d=0;
                    now=p[nxt];
                    nxt++;
                    // cout<<"TOO "<<nxt<<" "<<d<<endl;
                }
            }
            cout<<endl;

        }
    }
