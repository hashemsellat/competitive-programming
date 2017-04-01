/*
 let valid number be the number which is divisable by K and it's sum of digits is also divisable by K
 let S(x) be the number of valid numbers below x
 then answer is obviously S(B)-S(A)+(isValid(A))
 dp[i][mod][sm][isLess] is the number of valid numbers we can get if we are at digit #i
, the sum of previous digits is sm ,mod=(the previous digits*10^(the number of the rest digits))%K and isLess is 1 if we go below the number
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'
string s,s1;
int dp[12][10001][100][2];
int poae[100],A,B,K;
int f(int i,int mod,int sm,bool isLess,string &s){
//  cout<<i<<" "<<mod<<" "<<sm<<" "<<isLess<<endl;
  if(i==s.size()){
  //  cout<<"test "<<s.size()<<endl;
    if(sm%K==0&&mod==0)
      return 1;
    return 0;
  }
  if(dp[i][mod][sm][isLess]!=-1)
    return dp[i][mod][sm][isLess];
  int ret=0;
  for(int j=0;j<=9;j++){
    if(!isLess&&j>s[i]-'0')
      continue;
    ret+=f(i+1,(j*poae[s.size()-1-i]+mod)%K,sm+j,isLess||j<s[i]-'0',s);
  }
  return dp[i][mod][sm][isLess]=ret;
}
main(){
  ios_base::sync_with_stdio(false);
  int t;
  cin>>t;
  while(t--){
    memset(dp,-1,sizeof(dp));
    cin>>A>>B>>K;
    poae[0]=1;
    for(int i=1;i<100;i++)
      poae[i]=(poae[i-1]*10)%K;
    stringstream ss,ss1;
    ss<<A;
    s=ss.str();
    ss1<<B;
    s1=ss1.str();
  //  cout<<s<<" "<<s1<<endl;
    int l=f(0,0,0,0,s);
  //  cout<<endl;
    memset(dp,-1,sizeof(dp));
    int r=f(0,0,0,0,s1);
  //  cout<<l<<" "<<r<<endl;
    int ans=r-l;
    int smA=0;
    for(int i=0;i<s.size();i++){
      smA+=s[i]-'0';
    }
    if(A%K==0&&smA%K==0){
      ans++;
    }
    cout<<ans<<endl;
  }
}
