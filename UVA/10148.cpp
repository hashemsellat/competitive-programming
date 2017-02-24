#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ii pair<int,int>
#define endl '\n'
const int AD = 20001;
const int MX=100000;
bool check[MX];
int x[MX],xx[MX];
vector<int> start[MX],end_[MX];
int cnt[MX];
main()
{
    int t;
    ios_base::sync_with_stdio(false);
    cin>>t;
    while(t--)
    {
        for(int i=0; i<MX; i++)
        {
            start[i].clear();
            end_[i].clear();
            check[i]=0;
            cnt[i]=0;
        }
        int n,k;
        cin>>k>>n;
        for(int i=0; i<n; i++)
        {
            cin>>x[i]>>xx[i];
            x[i]+=AD;
            xx[i]+=AD;
            if(x[i]>xx[i])
                swap(x[i],xx[i]);
            if(xx[i]-x[i]+1<=k)
            {
                for(int j=x[i]; j<=xx[i]; j++)
                {
                    check[j]=1;
                }
            }
            else
            {
                start[x[i]].push_back(i);
                end_[xx[i]].push_back(i);
            }
        }


        set<int> s;
        stack<int> sta;
        for(int i=0; i<MX; i++)
        {
            int sz=start[i].size();
            for(int j=0; j<sz; j++)
            {
                s.insert(start[i][j]);
            }
            if(check[i])
            {
                set<int>::iterator it = s.begin();
                vector<int> tmp;
                for(it; it!=s.end(); it++)
                {
                    int cur=*it;
                    cnt[cur]++;
                    if(cnt[cur]==k)
                    {
                        tmp.push_back(cur);
                    }
                }
                for(int j=0; j<tmp.size(); j++)
                    s.erase(tmp[j]);
            }
            else
            {
                sta.push(i);
            }

            sz=end_[i].size();
            for(int j=0; j<sz; j++)
            {
                int node=end_[i][j];
                while(cnt[node]<k)
                {
                    int prv=sta.top();
                    sta.pop();
                    check[prv]=1;
                    vector<int> tmp;
                    set<int>::iterator it = s.begin();
                    for(it; it!=s.end(); it++)
                    {
                        int cur=*it;
                        if(prv>=x[cur]&&prv<=xx[cur])
                            cnt[cur]++;
                        if(cnt[cur]>=k)
                        {
                            tmp.push_back(cur);
                        }
                    }
                    for(int j=0; j<tmp.size(); j++)
                        s.erase(tmp[j]);
                }
                if(s.find(node)!=s.end())
                    s.erase(node);
            }

        }
        int ans=0;
        for(int i=1; i<MX; i++)
        {
            if(check[i])
            {
                ans++;
                //cout<<i-AD<<endl;
            }
        }
        cout<<ans<<endl;
        for(int i=1; i<MX; i++)
        {
            if(check[i])
                cout<<i-AD<<endl;
        }
        if(t)
        cout<<endl;
    }
}
