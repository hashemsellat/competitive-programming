/* the idea to solve this problem and similar problems is that if we should move k steps to reach a
permutation state and in each step we should apply one of two actions and these actions are counteractive
,we can apply a single action in each step and if we reached a solution and (k-i) is even where i is the current step,
so there is a solution because we can apply the two actions (k-i)/2 times then we reach the final state.
*/
#include<bits/stdc++.h>
#define ii pair<int,int>
#define iii pair<ii,int>
using namespace std;
vector<int> q;
int n,k;
vector<int> forward(vector<int> v){
  int sz=v.size();
  vector<int> ret(sz,0);
  for(int i=1;i<=n;i++){
    ret[i]=v[q[i]];
  }
  return ret;
}
vector<int> backward(vector<int> v){
  int sz=v.size();
  vector<int> ret(sz,0);
  for(int i=1;i<=n;i++){
    ret[q[i]]=v[i];
  }
  return ret;
}
void prnt(vector<int>&v){
  for(int i=0;i<int(v.size());i++){
    cout<<v[i]<<" ";
  }
  cout<<endl;
}
main(){
  cin>>n>>k;
  vector<int> v;
  for(int i=0;i<=n;i++){
    v.push_back(i);
  }
  q.push_back(0);
  for(int i=1;i<=n;i++){
    int x;cin>>x;q.push_back(x);
  }
  vector<int> s;
  s.push_back(0);
  for(int i=0;i<n;i++){
    int x;cin>>x;s.push_back(x);
  }
  vector<int> cur=v,prv=v;
  if(s==v){
    cout<<"NO"<<endl;ييي
    return 0;
  }
//  cur=forward(cur);
//  prnt(cur);
//  cur=backward(cur);
//  prnt(cur);
  for(int i=1;i<=k;i++){

    cur=forward(cur);
    if(cur==prv)  break;
    if(cur==s){
      if((k-i)%2==0&&!((i!=k)&&backward(prv)==s)){
        cout<<"YES"<<endl;
        return 0;
      }
      else
        break;
    }
    prv=cur;
  }
  //cout<<"..."<<endl;
  cur=v;
  prv=v;
  for(int i=1;i<=k;i++){
    cur=backward(cur);
    if(cur==prv)  break;
    if(cur==s){
      if((k-i)%2==0&&!((i!=k)&&forward(prv)==s)){
        cout<<"YES"<<endl;
        return 0;
      }
      else
        break;
    }
    prv=cur;
  }
  cout<<"NO"<<endl;
//  system("pause");
}
