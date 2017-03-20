/*
  the first thing i noticed which made me solve this problem is that if the substring
in the interval[l,r] is a regular expression then the answer is 1 otherwise the answer is 0.
  i used MO's algorithm to solve this
  first sort queries using MO's sort
  we maintain a stack (st) to check the expression.
  for each query we add/remove elements to/from the top or the bottom of the stack(its a stack with two sides :p)
or we add/remove elements to/from the top of the stack.
*/
#include<bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define iii pair<ii,int>

const int N = 1e6;
const int middle=N/2;
int top,bottom,blockSize;
inline bool comp(const iii &x,const iii &y){
  ii xx=x.first,yy=y.first;
  int xBlock=xx.first/blockSize;
  int yBlock=yy.first/blockSize;
  if(xBlock!=yBlock){
    return xBlock<yBlock;
  }
  return xx.second<yy.second;
}
iii q[N];
char st[N];
int id[N],rev[N];
bool isRemoved[N];
bool isC(const char x){
  return x>='A'&&x<='Z';
}
int ans[N];
main(){
  ios_base::sync_with_stdio(false);
  string s;
  cin>>s;
  blockSize=sqrt(s.size());
  int Q;
  std::cin >> Q;
  for(int i=0;i<Q;i++){
    cin>>q[i].first.first>>q[i].first.second;
    q[i].first.first--;
    q[i].first.second--;
    q[i].second=i;
    //cout<<query(l,r)<<endl;
  }
  bottom=middle;
  top=middle-1;
  sort(q,q+Q,comp);
  int L=0,R=-1;
  for(int i=0;i<Q;i++){
    int l=q[i].first.first,r=q[i].first.second;
    /*cout<<q[i].second<<endl<<l<<" "<<r<<" "<<L<<" "<<R<<endl;
    for(int j=bottom;j<=top;j++)
      cout<<st[j];
    cout<<endl;
    */
    while(R<r){
      //start adding one by one
      R++;
      //Cc
      if(top<bottom){
        top++;
        st[top]=s[R];
        id[top]=R;
        continue;
      }
      if(isC(st[top])&&s[R]==tolower(st[top])){
        isRemoved[R]=1;
        isRemoved[id[top]]=1;
        rev[R]=id[top];
        rev[id[top]]=R;
        top--;
        continue;
      }
      st[++top]=s[R];
      id[top]=R;
    }
    while(R>r){
      if(isRemoved[R]){
        isRemoved[R]=0;
        isRemoved[rev[R]]=0;
        st[++top]=toupper(s[R]);
        id[top]=rev[R];
      }
      else
        top--;
      R--;
    }
    while(L>l){
       //we should take elements !
       //move bottom to the left and add elements one by one starting from L-1
       L--;
       if(top<bottom){
         bottom--;
         st[bottom]=s[L];
         id[bottom]=L;
         continue;
       }
       if(!isC(st[bottom])&&toupper(st[bottom])==s[L]){
         //Cc
         isRemoved[L]=1;
         isRemoved[id[bottom]]=1;
         rev[L]=id[bottom];
         rev[id[bottom]]=L;
         bottom++;
         continue;
       }
       st[--bottom]=s[L];
       id[bottom]=L;
    }
    while(L<l){
      //remove one by one til you reach l
      if(isRemoved[L])
      {
        isRemoved[L]=0;
        isRemoved[rev[L]]=0;
        st[--bottom]=tolower(s[L]);
        id[bottom]=rev[L];
      }
      else
        bottom++;
      L++;
    }

  /*  for(int j=bottom;j<=top;j++)
      cout<<st[j];
    cout<<endl;*/
//    cout<<q[i].second<<" "<<top<<" "<<bottom<<endl;
  if(top<bottom)
      ans[q[i].second]=1;
    else
      ans[q[i].second]=0;
  }
  for(int i=0;i<Q;i++)
    cout<<ans[i];
  cout<<endl;
//  system("pause");
}
