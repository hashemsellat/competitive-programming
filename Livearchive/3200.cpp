/*
    we can use backtracking to get the answer
    we should stop searching if we have reached the same set of nodes before, with a lower distance and there was no solution.
    attention .. the output format is not well explained in the problem statement.
*/
#include<bits/stdc++.h>
#define ii pair<int,int>
#define iii pair<ii,int>
#define endl '\n'
using namespace std;
#define iv pair<int,vector<int> >
vector<vector<ii> >adj;
vector<int> cur;
vector<iv> ans;
int sv,dv,maxdist;
short mn[21][(1<<20)+10];
bool dfs(int v,int mask,int l)
{
    if(l>maxdist||mn[v][mask]<=l)//we cant reach using this shit
        return 0;
    cur.push_back(v);
    if(v==dv)
    {
        ans.push_back(iv(l,cur));
        cur.pop_back();
        return 1;
    }
    bool nxt=0;
    for(auto x:adj[v])
    {
        if(!(mask&(1<<x.first)))
            nxt|=dfs(x.first,mask|(1<<x.first),l+x.second);
    }
    if(!nxt)
    {
        mn[v][mask]=l;
    }
    cur.pop_back();
    return nxt;
}
main()
{
    //  freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int n,m;
    int c=1;
    bool is=0;
    while(cin>>n)
    {
        if(n==-1)
            break;
        if(is)  cout<<endl;
        is=1;
        cin>>m;
        adj.clear();
        vector<ii> tmp;
        adj.assign(n+1,tmp);
        ans.clear();
        cur.clear();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<(1<<n); j++)
                mn[i][j]=20000;
        }
        for(int i=0; i<m; i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            u--;
            v--;
            adj[u].push_back(ii(v,w));
            adj[v].push_back(ii(u,w));
        }

        cin>>sv>>dv>>maxdist;
        sv--;
        dv--;
        dfs(sv,(1<<sv),0);
        int sz=ans.size();
        sort(ans.begin(),ans.end());
        //cout<<sz<<endl;
        cout<<"Case "<<c<<":"<<endl;
        if(sz==0)
        {
            cout<<" NO ACCEPTABLE TOURS"<<endl;
            c++;
            continue;
        }
        for(int i=0; i<sz; i++)
        {
            cout<<" "<<ans[i].first<<": ";
            int szz=ans[i].second.size();
            vector<int> tmp=ans[i].second;
            int cnt=0;
            for(auto x:tmp)
            {
                cout<<x+1;
             /*   if(cnt==tmp.size()-1)
                    cout<<endl;
                else*/
                    cout<<" ";
                cnt++;
            }
            cout<<endl;
        }
        c++;
    }
}
