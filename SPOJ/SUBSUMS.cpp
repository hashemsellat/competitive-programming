#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'
int s[50];
vector<int> v;
main(){
    ios_base::sync_with_stdio(false);
    int n,a,b;
    cin>>n>>a>>b;
    for(int i=0;i<n;i++)
        cin>>s[i];
    int ans=0;
    for(int i=0;i<(1<<(n/2+(n%2)));i++){
        int cur=0;
        for(int j=0;j<n/2+(n%2);j++){
            if(i&(1<<j)){
                cur+=s[j];
            }
        }
        v.push_back(cur);
    }
    sort(v.begin(),v.end());
    int shift=n/2+n%2;
    for(int i=0;i<(1<<(n/2));i++){
        int cur=0;
        for(int j=shift;j<n;j++){
            if(i&(1<<(j-shift))){
                cur+=s[j];
            }
        }
        int now=upper_bound(v.begin(),v.end(),b-cur)-lower_bound(v.begin(),v.end(),a-cur);
        ans+=now;
    }
    cout<<ans<<endl;
}
