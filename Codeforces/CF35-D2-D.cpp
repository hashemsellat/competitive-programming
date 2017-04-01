#include <bits/stdc++.h>
using namespace std;
#define int long long int

main(){
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  int n,X;
  cin>>n>>X;
  std::vector<int> v;
  for(int i=0;i<n;i++){
    int y;
    cin>>y;
    v.push_back(y*(n-i));
  }
  sort(v.begin(),v.end());
  int sm=0,ans=0;
  for(auto x:v){
    if(sm+x<=X){
      ans++;
      sm+=x;
    }
  }
  cout<<ans<<endl;
}
