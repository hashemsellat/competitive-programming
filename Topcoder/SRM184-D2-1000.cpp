#include<bits/stdc++.h>
#define ii pair<int,int>
#define endl '\n'
bool vis[100];
#define vi vector<int>
using namespace std;
struct TeamBuilder
{
    int n;
    int dfs(int v,vector<string> &paths)
    {
        if(vis[v])  return 0;
        int ret=0;
        if(!vis[v])
        {
            vis[v]=1;
            ret=1;
        }
        for(int i=0; i<n; i++)
        {
            if(paths[v][i]=='1')
                ret+=dfs(i,paths);
        }
        return ret;
    }
    vi specialLocation(vector<string> paths)
    {
        vector<string> rpaths;
        rpaths=paths;
        n=paths.size();
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                rpaths[i][j]='0';
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(paths[i][j]=='1')
                {
                    rpaths[j][i]='1';
                }
            }
        }
        vector<int> ret;
        ret.push_back(0);
        ret.push_back(0);
        for(int i=0; i<n; i++)
        {
            memset(vis,0,sizeof(vis));
            int now=dfs(i,paths);
            if(now==n)
                ret[0]++;
            memset(vis,0,sizeof(vis));
            now=dfs(i,rpaths);
            if(now==n)
                ret[1]++;
        };
        return ret;
    }
};
main()
{
    vector<string> paths=
{"0110000","1000100","0000001","0010000","0110000","1000010","0001000"}

    ;
    TeamBuilder a;
    vi ans=a.specialLocation(paths);
    cout<<ans[0]<<" "<<ans[1]<<endl;
}
