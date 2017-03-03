#include<bits/stdc++.h>
#define int long long int
#define ii pair<int,int>
using namespace std;
#define endl '\n'
#define A second.first
#define B first
#define H second.second
#define iii pair<int,ii>
const int N = 3*1e5;
iii el[N];
int BIT[N];
int dp[N];
int query(int x)
{
    int id=x;
    int ret=0;
    for(id; id>0; id-=(id&-id))
    {
        ret=max(ret,BIT[id]);
    }
    return ret;
}
void update(int id,int val)
{
    for(id; id<=N; id+=(id&-id))
    {
        BIT[id]=max(BIT[id],val);
    }
}
bool comp(const iii &x,const iii &y)
{
    return x>y;
}
main()
{
    int n;
    cin>>n;
    set<int> s;
    for(int i=0; i<n; i++)
    {
        int  x,y,z;
        cin>>x>>y>>z;
        el[i]=iii(y,ii(x,z));
        s.insert(x);
        s.insert(y);
    }
    int cnt=0;
    map<int,int> M;
    for(auto i:s)
    {
        // cout<<i<<endl;
        M[i]=++cnt;
    }
    for(int i=0; i<n; i++)
    {
        el[i].A=M[el[i].A];
        el[i].B=M[el[i].B];
    }
    sort(el,el+n,comp);
    int mx=0;
    for(int i=0; i<n; i++)
    {
        // cout<<el[i].A<<" "<<el[i].B<<" "<<el[i].H<<endl;
        dp[i]=el[i].H+query(el[i].B-1);
        update(el[i].A,dp[i]);
        mx=max(mx,dp[i]);
        //  cout<<i<<" "<<dp[i]<<endl;
    }
    cout<<mx<<endl;
}
