#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e5 + 10,MXL=17;
int dfs_number[MAXN],finish_number[MAXN];
int n ,q, par[MAXN][17] ;
#define ii pair<int,int>
#define endl '\n'
vector<int> adj[MAXN];
int dn,fn;
int xxx[MAXN],was[MAXN];
int dfs(int x , int p){
    dfs_number[x]=dn++;
    int ret = 0;
    for(auto nxt:adj[x]){
        par[nxt][0]=x;
        ret+=dfs(nxt,x);
    }

    if(adj[x].size() == 0)
        ret=1;
    xxx[x]=ret;
    finish_number[x]=fn++;
    return ret;
}
void precalc(){
    for(int j=1;j<MXL;j++)
        for(int i=1;i<=n;i++)
            par[i][j]=par[par[i][j-1]][j-1];
}
int findNode(int node,int maxFinishNumber,int minDfsNumber){
    if(finish_number[node]>=maxFinishNumber&&dfs_number[node]<=minDfsNumber)
        return node;
    for(int i=0;i<17;i++){
        int p = par[node][i];
        if(p==0){
            return findNode(par[node][i-1],maxFinishNumber,minDfsNumber);
        }
        if(finish_number[p]>=maxFinishNumber&&dfs_number[p]<=minDfsNumber)
            if(i==0){
                return par[node][i];
            }
            else
                return findNode(par[node][i-1],maxFinishNumber,minDfsNumber);
    }

}
int p[MAXN];set<ii> fs[MAXN],ds[MAXN];

main(){
    ios_base::sync_with_stdio(false);
    freopen("gangsters.in","r",stdin);
    freopen("gangsters.out","w",stdout);
    cin>>n>>q;
    for(int i=2;i<=n;i++){
        cin>>p[i];
        adj[p[i]].push_back(i);
    }

    vector<int> interevals;
    dfs(1,0);
    for(int i=0;i<adj[1].size();i++){
        interevals.push_back(dfs_number[adj[1][i]]);
        //cout<<interevals.back()<<endl;
    }
    sort(interevals.begin(),interevals.end());
    precalc();
  //  cout<<xxx[7]<<endl;
    int cnt = 0;
    int total=0;
    for(int i=0;i<q;i++){
        char c;int x;
        cin>>c>>x;
        vector<int>::iterator it = lower_bound(interevals.begin(),interevals.end(),dfs_number[x]);

        if(it==interevals.end()|| *it!=dfs_number[x]){
            it--;
        }

        int num= it - interevals.begin();
      //  cout<<dfs_number[x]<<endl;
      //  cout<<num<<endl;
        if(c=='+'){
            if(fs[num].size()==0)
                cnt++;
            fs[num].insert(ii(finish_number[x],x));
            ds[num].insert(ii(dfs_number[x],x));
            ii down = *fs[num].rbegin();
            int maxFinishNumber =(*fs[num].rbegin()).first;
            int minDfsNumber=(*ds[num].begin()).first;
            int node = findNode(x,maxFinishNumber,minDfsNumber);
            total -= was[num];
            total += xxx[node]-fs[num].size();
          //  cout<<was[num]<<endl;
            was[num]=xxx[node]-fs[num].size();

         //   cout<<"node "<<node<<" "<<xxx[node]<<" "<<fs[num].size()<<endl;
            cout << cnt << " " << total<<endl;
        }
        else{
            fs[num].erase(ii(finish_number[x],x));
            ds[num].erase(ii(dfs_number[x],x));

            if(fs[num].empty()){
                cnt--;
                total-=was[num];
                was[num] = 0;
                cout << cnt << " " << total <<endl;
                continue;
            }
            int node=(*fs[num].rbegin()).second;
            int maxFinishNumber =(*fs[num].rbegin()).first;
            int minDfsNumber=(*ds[num].begin()).first;
            node = findNode(node,maxFinishNumber,minDfsNumber);
            total -= was[num];
            total += xxx[node]-fs[num].size();
            was[num]=xxx[node]-fs[num].size();
            cout << cnt << " " << total<<endl;
        }
    }
}