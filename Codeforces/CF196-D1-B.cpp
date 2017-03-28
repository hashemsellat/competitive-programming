/* if there is a wall in position i,j so there are walls in positions (i,j+m),..,(i,j+k*m)
also there are walls in positions (i+n,j),..,(i+k*n,j),
  so the grid repeats itself in all the 4 directions.
  now we can simulate the movement, if we reached the same conected componenet we've reached before but NOT the same grid so there is an infinate path
because we can also reach this cc again and again.
*/
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N=2000;
string s[N];
int cc[N][N],n,m;
bool vis[4000000];
#define ii pair<int,int>
#define iii pair<int,ii>
vector<iii> adj[4000000];
int di[]={0,0,1,-1};
int dj[]={1,-1,0,0};
void dfs(int i,int j,int c){
  cc[i][j]=c;
  if(i==n-1)
    adj[c].push_back(iii(0,ii(0,j)));
  if(i==0)
    adj[c].push_back(iii(1,ii(n-1,j)));
  if(j==m-1)
    adj[c].push_back(iii(2,ii(i,0)));
  if(j==0)
    adj[c].push_back(iii(3,ii(i,m-1)));
  for(int k=0;k<4;k++){
    int ni=i+di[k];
    int nj=j+dj[k];
    if(ni==n||nj==m||ni<0||nj<0||cc[ni][nj]||s[ni][nj]=='#')
      continue;
    dfs(ni,nj,c);
  }
}
bool is=1;
int cu,cr;
map<iii,bool> vist;
bool solve(int i,int j,int cu,int cr){
//  cout<<"test "<<i<<" "<<j<<" "<<cu<<" "<<cr<<endl;
  //system("pause");
  int cur=cc[i][j];
  if(cur==0)  return 0;
  if(vist[iii(cur,ii(cu,cr))])
    return 0;
  vist[iii(cur,ii(cu,cr))]=1;
  if(vis[cur])  return 1;
  vis[cur]=1;
  for(auto x:adj[cur]){
    int ni=x.second.first,nj=x.second.second;

    int ncu=cu;
    int ncr=cr;
    if(x.first==0){
      ncu--;
    }
    if(x.first==1){
      ncu++;
    }
    if(x.first==2){
      ncr++;
    }
    if(x.first==3){
      ncr--;
    }
    if(solve(ni,nj,ncu,ncr))
      return 1;
  }
  return 0;
}
main(){
  ios_base::sync_with_stdio(false);
  cin>>n>>m;
  for(int i=0;i<n;i++)
    cin>>s[i];
  int cnt=0;
  int sti,stj;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){

      if(s[i][j]=='S')
      {
        sti=i;
        stj=j;
      }
      if(!cc[i][j]&&s[i][j]!='#'){
        dfs(i,j,++cnt);
      }
    }
  }
  //cout<<sti<<" "<<stj<<endl;
  if(solve(sti,stj,0,0)){
    cout<<"Yes"<<endl;
  }
  else
    cout<<"No"<<endl;
}
