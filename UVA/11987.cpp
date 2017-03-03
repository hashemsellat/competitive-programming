#include<bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define iii pair<int,ii>
#define int long long int
#define endl '\n'
#define vi vector<int>
int n;
struct DSU
{
    unordered_map<int,int> p,r;
    unordered_map<int,int> ansl,ansr;
    unordered_map<int,int> cnt;
    int findSet(int x)
    {

        if(!p[x]||p[x]==x)
            return x;
        else
            return p[x]=findSet(p[x]);
    }

    void Union(int x,int y)
    {
        int u=findSet(x),
            v=findSet(y);
        if(u==v)
        {
            return;
        }
        if(r[u]>r[v])   swap(u,v);
        if(r[u]<=r[v])
        {
            p[u]=v;
            ansl[v]+=ansl[u];
            ansr[v]+=ansr[u];
        }
        if(r[u]==r[v])
            r[v]++;
    }
};
main()
{
    ios_base::sync_with_stdio(false);
    int m;
    while(cin>>n>>m)
    {
        DSU a;
        for(int i=1; i<=n; i++)
        {
            a.ansl[i]=i;
            a.ansr[i]=1;
        }
        for(int i=0; i<m; i++)
        {
            int t,x,y;
            cin>>t;
            if(t==1)
            {
                cin>>x>>y;
                a.Union(x+n*a.cnt[x],y+n*a.cnt[y]);
            }
            if(t==2)
            {
                cin>>x>>y;
                //move p to q
                //so cnt[p]++ and p = cnt[p]*n+p
                int u=a.findSet(x+a.cnt[x]*n);
                int v=a.findSet(y+a.cnt[y]*n);
                if(u==v)
                    continue;
                a.ansl[u]-=x;
                a.ansr[u]--;
                a.cnt[x]++;
                a.Union(y+a.cnt[y]*n,x+a.cnt[x]*n);
                int foo=a.findSet(y+a.cnt[y]*n);
                a.ansl[foo]+=x;
                a.ansr[foo]++;
            }
            if(t==3)
            {
                cin>>x;
                int u=a.findSet(x+a.cnt[x]*n);
                cout<<a.ansr[u]<<" "<<a.ansl[u]<<endl;
            }
        }
    }
}
