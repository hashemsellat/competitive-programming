#include<bits/stdc++.h>
using namespace std;
#define int long long int
main(){
    int n;
    cin>>n;
    deque<int> d;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        d.push_back(x);
    }
    sort(d.begin(),d.end());
    int ans=1e18;
    for(int i=0;i<n/2;i++){
       // cout<<d[i]<<" "<<d[i+n/2]<<endl;
        ans=min(ans,abs(d[i]-d[i+n/2]));
    }
    cout<<ans<<endl;
}