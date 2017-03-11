#include<bits/stdc++.h>
#define ii pair<int,int>
using namespace std;
#define int long long int
#define point complex<double>
#define double long double
#define endl '\n'
ii A[1000000],B[1000000];
int l[1000000];
double dst[1000000];
inline double dist(ii p,ii p1){
    return sqrt(pow(p.first-p1.first,2)+pow(p.second-p1.second,2));
}
main(){
    //ios_base::sync_with_stdio(false);
    int n,m,a,b;
    scanf("%lld%lld%lld%lld",&n,&m,&a,&b);
    for(int i=0;i<n;i++)
    {
        int y;
        scanf("%lld",&y);
        A[i]=ii(a,y);
    }
    for(int i=0;i<m;i++){
        int x;
        scanf("%lld",&x);
        B[i]=ii(b,x);
    }
    for(int i=0;i<m;i++)
        scanf("%lld",&l[i]);
    double ans=1e18;
    ii cur;
    for(int i=0;i<n;i++){
        dst[i]=dist(A[i],ii(0,0));
    }
    for(int i=0;i<m;i++){
        int lo=-1,hi=n;
        while(hi-lo>1){
            int mid = (hi + lo)>>1;
            int g=mid,h=mid+1;

            double dist1=l[i]+dist(B[i],A[g])+dst[g];
            double dist2=l[i]+dist(B[i],A[h])+dst[h];
            if(!(g>=0&&g<n))
                dist1=1e18;
            if(!(h>=0&&h<n))
                dist2=1e18;
            if (dist1<dist2)
                 hi = mid;
            else
                 lo = mid;
            if(dist1<ans){
                ans=dist1;
                cur=ii(g,i);
            }
            if(dist2<ans){
                ans=dist2;
                cur=ii(h,i);
            }
        }
    }
    printf("%lld %lld",cur.first+1,cur.second+1);

}
