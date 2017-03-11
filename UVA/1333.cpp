
#include<bits/stdc++.h>
using namespace std;
const double PI = 2*acos(0);
main()
{
    double d,h;
    cin>>d>>h;
    double a,b,g;
    while(cin>>a>>b>>g)
    {
        if(a<=0||b<=0||g<=0)
            break;
        b*=PI/180;
        a*=PI/180;
        g*=PI/180;
        // cout<<a<<" "<<b<<" "<<g<<endl;
        double aoo=(1/(2*sin(a)*sin(a))+1/(2*sin(g)*sin(g))-1/(sin(b)*sin(b)));
        double ans=d*d/aoo;
        int anse=sqrt(ans)+0.5+h;
        cout<<anse<<endl;
    }

}
