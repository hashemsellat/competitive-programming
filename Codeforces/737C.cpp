
#include<bits/stdc++.h>
#define ii pair<int,int>
using namespace std;
#define int long long int
int a[1000000];
int cnt[1000000];
int sm[1000000];
#define ii pair<int,int>
main(){
    int n,s;
    cin>>n>>s;
    s--;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ad=(a[s]!=0);
    int zeros=0;
    for(int i=0;i<n;i++){
        if(i==s)
            continue;
        if(a[i]!=0){
            cnt[a[i]]++;
        }
        else{
            if(i!=s)
                zeros++;
        }
    }
    vector<ii> v;
    v.push_back(ii(0,1));
    for(int i=1;i<n;i++){
        if(cnt[i]!=0)
            v.push_back(ii(i,cnt[i]));
    }
    int sz=v.size();
    for(int i=sz-1;i>=0;i--){
        sm[i]=sm[i+1]+v[i].second;
        //cout<<sm[i]<<endl;
    }
    int ans=1e9;
    int cur=0;
    for(int i=1;i<sz;i++){
        cur+=v[i].first-v[i-1].first-1;
        ans=min(ans,max(zeros+sm[i+1],cur));
    }
    if(ans==1e9){
        ans=zeros;
    }
    cout<<ans+ad<<endl;
}
