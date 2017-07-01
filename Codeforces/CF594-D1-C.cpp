#include<bits/stdc++.h>
#define int long long int
using namespace std;
#define dd pair<int,int>
#define double long double
#define ddi pair<dd,int>
multiset<dd> s,rs;
bool shouldRemove[1000000];
main()
{
    int n,k;
   // scanf("%I64d%I64d",&n,&k);
    scanf("%lld%lld",&n,&k);
   // cin>>n>>k;
    for(int i=0; i<n; i++) {
        int x1,x2,y1,y2;
        scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
    //    cin>>x1>>y1>>x2>>y2;

        int x=(x1+x2),y=(y1+y2);
        // cout<<"test "<<x<<" "<<y<<endl;
        s.insert(dd(x,y));
        rs.insert(dd(y,x));
    }


    int ans=1e18;
    for(int i=0; i<=k; i++) {
        for(int j=0; j<=k; j++) {
            for(int l=0; l<=k; l++) {
                for(int m=0; m<=k; m++) {
                    if(i+j+l+m!=k)
                        continue;
                    int cnti=0;
                    //take i elements from the front of s
                    //cout<<i<<" "<<j<<" "<<l<<" "<<m<<endl;
                    vector<dd> tmp;
                    for(int e=0; e<i; e++) {
                        dd cur=*s.begin();
                        s.erase(s.find(cur));
                        rs.erase(rs.find(dd(cur.second,cur.first)));
                        tmp.push_back(cur);
                    }
                    for(int e=0; e<j; e++) {
                        dd cur=*s.rbegin();
                        s.erase(s.find(cur));
                        rs.erase(rs.find(dd(cur.second,cur.first)));
                        tmp.push_back(cur);
                    }
                    for(int e=0; e<l; e++) {
                        dd cur=*rs.begin();
                        rs.erase(rs.find(cur));
                        s.erase(s.find(dd(cur.second,cur.first)));
                        tmp.push_back(dd(cur.second,cur.first));
                    }
                    for(int e=0; e<m; e++) {
                        dd cur=*rs.rbegin();
                        rs.erase(rs.find(cur));
                        s.erase(s.find(dd(cur.second,cur.first)));
                        tmp.push_back(dd(cur.second,cur.first));
                    }
                    double topX=(*s.begin()).first/2.0;
                    double lessX=(*s.rbegin()).first/2.0;

                    double topY=(*rs.begin()).first/2.0;
                    double lessY=(*rs.rbegin()).first/2.0;

                    double l=ceil(abs(topX-lessX));
                    double r=ceil(abs(topY-lessY));
                    if(l==0)
                        l++;
                    if(r==0)
                        r++;
                   // cout<<"foo "<<topX<<" "<<lessX<<" "<<topY<<" "<<lessY<<endl;
                    int foo=l*r;
                    ans=min(ans,foo);
                    for(auto x:tmp) {
                        s.insert(x);
                        rs.insert(dd(x.second,x.first));
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
}
