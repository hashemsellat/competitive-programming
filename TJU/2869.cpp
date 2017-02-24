#include<bits/stdc++.h>
using namespace std;
//#define double long double
//#define int long long int
#define ii pair<int,int>
#define iii pair<int,ii>
#define int long long int
#define endl '\n'
#define vi vector<int>
int o,e,d;
void extendedEuclid(int a,int b)
{
    if(b==0)
    {
        o=1;
        e=0;
        d=a;
        return;
    }
    extendedEuclid(b,a%b);
    int x1=e;
    int y1=o-(a/b)*e;
    o=x1;
    e=y1;

}
main()
{
    int x,y,z,n;
  /*  for(x=1; x<=200; x++)
        for(z=1; z<=200; z++)
            for(y=1; y<=200; y++)
                for(n=1; n<=200; n++)*/
    while(cin>>x>>y>>z>>n)
    {
        int g1=__gcd(y,z);
        if(n%(__gcd(x,g1))!=0)
        {
            cout<<-1<<endl;
            continue;
        }

        extendedEuclid(x,g1);
        int x0=o;
        int g2=__gcd(g1,x);
        x0=(x0%(g1/g2)+(g1/g2))%(g1/g2);
        int b=(g2-x0*x)/g1;
        //áäØáÚæ ÝæÞ ÇáÕÝÑ
        x0*=n/g2;
        b*=n/g2;
        extendedEuclid(y,z);
        int y0,z0;
        if(b==0)
        {
            y0=z0=0;
        }
        else
        {
            if(b<0)
            {
                //y0 should be bigger than zero
                y0=(o%(z/g1)+(z/g1))%(z/g1);
                if(y0>0)
                    y0-=(z/g1);
                z0=(g1-y0*y)/z;

                y0*=b;
                z0*=b;

            }
            else
            {
                z0=(e%(y/g1)+(y/g1))%(y/g1);
                if(z0>0)
                    z0-=(y/g1);
                //  cout<<"HOO"<<endl;
                //   cout<<g2<<" "<<z0<<" "<<z<<endl;
                y0=(g2-z0*z)/y;
                y0*=b;
                z0*=b;
            }
        }
        cout<<x0<<" "<<y0<<" "<<z0*-1<<endl;
       /* if(x0*x+y0*y+z0*z!=n)
        {
            cout<<x<<" "<<y<<" "<<z<<" "<<n<<endl;
            system("pause");
        }*/
    }
}
