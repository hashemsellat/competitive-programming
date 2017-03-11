#include<bits/stdc++.h>
using namespace std;
int a[1000000];
#define ii pair<int,int>
#define iii pair<int,ii>
vector<iii> v;
main(){
    int n,k;
    cin>>n>>k;
    bool is=0,notStart=0;
    int beg;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]<0){
            notStart=1;
            if(is){
               // cout<<beg<<" "<<i<<endl;
                v.push_back(iii(i-beg,ii(beg,i)));
            }
            is=0;
            k--;
        }

        if(a[i]>=0){
          //  cout<<is<<" "<<notStart<<endl;
            if(!is&&notStart){
                beg=i;
                is=1;
            }
        }
    }
    sort(v.begin(),v.end());
    int sz=v.size();
    for(int i=0;i<sz;i++){
      //  cout<<v[i].second.first<<" "<<v[i].second.second<<endl;
      //  cout<<v[i].first<<endl;
        if(v[i].first<=k){
            for(int j=v[i].second.first;j<v[i].second.second;j++)
                a[j]=-1;
            k-=v[i].first;
        }
    }
    if(is){
        if(k-(n-beg)>=0)
            for(int i=beg;i<n;i++)
                a[i]=-1;
    }
    if(k<0){
        cout<<-1<<endl;
        return 0;
    }
    int ans=0;
    int cur=10;
    for(int i=0;i<n;i++){
        //cout<<a[i]<<endl;
        if(cur>=0&&a[i]<0){
            cur=-1;
            ans++;
        }
        else
            if(cur<0&&a[i]>=0){
                cur=10;
                ans++;
            }
    }
    cout<<ans<<endl;
}
