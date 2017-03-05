#include<bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define iii pair<int,ii>
#define int long long int
#define endl '\n'
#define vi vector<int>
main()
{
    int n;
    int r;
    //freopen("out.txt","w",stdout);
    cin>>r;
    while(r--)
    {
        cin>>n;
        int to3o=n;
        int cur=100000000000000000;
        int cnt=0;
        while(n--)
        {
            int foo=cur*10;
            int too=foo/2;
            int after=cur/2;
            int hoo=0,tmp=after;
            while(tmp)
            {
                hoo++;
                tmp/=10;
            }
            //cout<<hoo<<endl;
            if(hoo<18)
            {
                //   cout<<hoo<<" "<<after<<endl;
                cnt++;
                after*=10;
                after+=too%10;
            }
            cur=after;
            //   cout<<cur<<endl;
            // system("pause");
        }
        stringstream ss;
        ss<<cur;
        string s=ss.str();
        string ans=s.substr(0,4);
        if(s[4]>='5')
        {
            int j=3;
            while(ans[j]=='9')
            {
                ans[j]='0';
                j--;
            }
            ans[j]++;
        }
        cout<<2<<"^-"<<to3o<<" = "<<ans[0]<<"."<<ans[1]<<ans[2]<<ans[3]<<"E-"<<cnt<<endl;
    }
}
