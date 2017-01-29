#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ii pair<int,int>
#define endl '\n'
#define N 2000000
int a[3000000];
vector<ii> v;
main(){
    ios_base::sync_with_stdio(false);
    v.push_back(ii(0,1));
    for(int i=2;i<=N;i++){
        if(!a[i]){
            int cur=i;
            while(cur<=N){
                for(int j=cur;j<=N;j+=cur)
                    a[j]++;
                cur*=i;
            }
        }
        v.push_back(ii(a[i],i));
    }
  //  cout<<a[9]<<endl;
   // cout<<v[0].seocnd<<" "<<v[1].seocnd<<" "<<v[2].seocnd<<" "<<v[3].second<<" "<<v[4]<<endl;
    sort(v.begin(),v.end());
    int cnt=0;
    int n;
    while(cin>>n){
        if(n==0)    break;
        cout<<"Case "<<++cnt<<":"<<" "<<v[n-1].second<<endl;
    }
}
