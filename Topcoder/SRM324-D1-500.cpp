#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ll long long int

struct TournamentPlan{
    int getTravelDistance(vi street,vi avenue){
        int n=street.size();
        int to=0,hii=0;
        for(int i=0;i<n;i++){
            to=max(to,street[i]);
            hii=max(hii,avenue[i]);
        }
        ll ret=1e9;
        int mnx=1e9,mny=1e9;
        for(int i=0;i<=to;i++){
            int now=0;
            for(int j=0;j<n;j++){
                now+=abs(street[j]-i);
            }
            //cout<<i<<" "<<now<<endl;
            mnx=min(mnx,now);
        }
        for(int i=0;i<=hii;i++){
            int now=0;
            for(int j=0;j<n;j++)
                now+=abs(avenue[j]-i);
            mny=min(mny,now);
        }
        //cout<<mnx<<" "<<mny<<endl;
        return mnx+mny;
    }
};
main(){
  vi x=  {0,2,0,2,1};
vi y={0,0,2,2,1};

    TournamentPlan a;
    cout<<a.getTravelDistance(x,y);

}
