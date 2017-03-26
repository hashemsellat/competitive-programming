#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int
int h[1000000];
main()
{
    int n;
    while(cin>>n)
    {
        if(n==0)
            break;
        for(int i=0; i<n; i++)
            cin>>h[i];
        vector<int> v;
        int ans=h[0];
        v.push_back(0);
        for(int i=1; i<n; i++)
        {
            //cout<<v.size()<<endl;
            while(!v.empty()&&h[v.back()]>=h[i])
            {
                int prv;
                int cur=v.back();
                if(v.size()>1)
                {
                    prv=v[v.size()-2];
                }
                else
                    prv=-1;
                ans=max(ans,(i-prv-1)*h[cur]);
                v.pop_back();
            }
            if(v.empty())
            {
                ans=max(ans,h[i]*(i+1));
            }
            v.push_back(i);
            /*  for(int i=0; i<v.size(); i++)
              {
                  cout<<v[i]<<" ";
              }
              cout<<endl;*/
        }
        int last=v.back();
        // cout<<ans<<endl;
        while(v.size())
        {
//cout<<"test "<<v.back()<<endl;
            int cur=v.back();
            int prv;
            if(v.size()>1)
            {
                prv=v[v.size()-2];
            }
            else
                prv=-1;
            ans=max(ans,(last-prv)*h[cur]);
            v.pop_back();
            //cout<<ans<<endl;
        }
        cout<<ans<<endl;
    }
}
