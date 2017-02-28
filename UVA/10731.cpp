#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int
#define ii pair<int,int>
int cc,cnt;
vector<int> adj[100],ans[100];
int low[100],timer[100],in[100];
void dfs(int v,vector<int> &s)
{
    s.push_back(v);
    low[v]=timer[v]=++cnt;
    int sz=adj[v].size();
    in[v]=1;
    for(int i=0; i<sz; i++)
    {
        int nxt=adj[v][i];
        //cout<<char(v+'A')<<" "<<char(nxt+'A')<<endl;
        if(timer[nxt]==0)
        {
            dfs(nxt,s);
            low[v]=min(low[v],low[nxt]);
        }
        else
        {
            if(in[nxt])
                low[v]=min(low[v],timer[nxt]);
        }
    }

    if(low[v]==timer[v])
    {

        while(1)
        {
            int cur=s.back();
        //    cout<<char(cur+'A')<<" ";
            in[cur]=0;
            s.pop_back();
            ans[cc].push_back(cur);
            if(cur==v)
                break;
        }
      //  cout<<endl;
        cc++;
    }


}

main()
{
    ios_base::sync_with_stdio(false);
    int n;
    bool lock=0;
    while(cin>>n)
    {
        if(n==0)
            break;
        cc=0;
        cnt=0;
        memset(low,0,sizeof(low));
        memset(timer,0,sizeof(timer));
        for(int i=0; i<100; i++)
        {

            adj[i].clear();
            ans[i].clear();
        }
        if(lock)
        {
            cout<<endl;
        }
        else
            lock=1;
        bool is[26];
        memset(is,0,sizeof(is));
        for(int i=0; i<n; i++)
        {
            char cur[6];
            for(int i=0; i<6; i++)
            {
                cin>>cur[i];
                cur[i]-='A';
            }
            is[cur[5]]=1;
            for(int i=0; i<5; i++)
            {
                if(cur[i]!=cur[5])
                adj[cur[5]].push_back(cur[i]);
            }
        }
        for(int i=0; i<26; i++)
        {
            vector<int> s;
            if(is[i]&&!timer[i])
                dfs(i,s);
        }
        vector<string> res;
        for(int i=0; i<cc; i++)
        {
            int sz=ans[i].size();
            sort(ans[i].begin(),ans[i].end());
            string str="";
            for(int j=0; j<sz; j++)
            {
                int node=ans[i][j];
                str+=char(node+'A');
                if(j!=sz-1)
                    str+=' ';
                else
                    break;
            }
            res.push_back(str);
        }
        sort(res.begin(),res.end());
        for(int i=0; i<res.size(); i++)
        {
            cout<<res[i]<<endl;
        }
    }
}
