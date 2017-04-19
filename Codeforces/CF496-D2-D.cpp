#include<bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define endl '\n'
main(){
  ios_base::sync_with_stdio(false);
  int n;
  cin>>n;
  vector<int> a(n+1,0),b(n+1,0);
  int last=0;
  for(int i=1;i<=n;i++){
    int x;
    cin>>x;
    a[i]=a[i-1];
    b[i]=b[i-1];
    if(x==1){
      last=1;
      a[i]++;
    }
    else
    {last=2;
      b[i]++;
    }
  }
  std::vector<ii> ans;
  for(int i=1;i<=n;i++){
    int id=0,cnt1=0,cnt2=0;
    while(1){
      int l=lower_bound(a.begin()+id+1,a.end(),a[id]+i)-a.begin();
      int r=lower_bound(b.begin()+id+1,b.end(),b[id]+i)-b.begin();
      //first player win
      cout<<"hoo "<<b[id]+i<<endl;
      cout<<"test "<<i<<" "<<id<<" "<<l<<" "<<r<<endl;
      if(l<r){
        id=l;
        cnt1++;
      }
      else{
        //second player win
        if(l>r){
          id=r;
          cnt2++;
        }
        else{
          if(l==n+1&&r==n+1)  break;
        }
      }
      if(id==n){
          if(cnt1>cnt2&&last==1||cnt2>cnt1&&last==2)
          ans.push_back(ii(max(cnt1,cnt2),i));
        break;
      }
    }
  }
  sort(ans.begin(),ans.end());
  cout<<ans.size()<<endl;
  for(int i=0;i<ans.size();i++){
    cout<<ans[i].first<<" "<<ans[i].second<<endl;
  }
}
