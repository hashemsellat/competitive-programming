    #include<bits/stdc++.h>
    using namespace std;
    #define point complex<double>
    #define X real()
    #define Y imag()
    #define fixed fixed<<setprecision(2)
   // #define double long double
    const double EPS=1e-8;
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
        //freopen("out.txt","w",stdout);
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
                if(abs(p[nxt]-now)+EPS>d){
                    double ll=abs(p[nxt]-now);
                    point cur(now.X+d*(p[nxt].X-now.X)/ll,now.Y+d*(p[nxt].Y-now.Y)/ll);
                    cout<<fixed<<cur.X<<" "<<cur.Y<<endl;
                    now=cur;
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
