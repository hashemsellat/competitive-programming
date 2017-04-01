#include<bits/stdc++.h>
#define ii pair<int,int>
#define iii pair<ii,int>
#define endl '\n'
using namespace std;
#define int long long int
int start[1000000],cnt[1000000];
bool vis[1000000];
main()
{
    ios_base::sync_with_stdio(false);
    int b,d;
    cin>>b>>d;
    string c,a;
    cin>>a>>c;
    int idc=0;
    int x=0;
    int wl=a.size()*b;
    int ans=0;
    for(int i=0; i<wl; i++)
    {
        if(i>100000&&x==0)  break;
        int ida=(i%a.size());
        if(a[ida]==c[idc])
        {
            //we don't put any thing in position i
            if(idc==0)
            {
                //we started here
                if(vis[ida])
                {
                    //we discovered a period which already started here
                    //the period is in the interval [start[ida],i[
                    int periodLength=i-start[ida];
                    //there are x-cnt[ida] of strings c in each period
                    //now there are #strings_in_the_periods * (wl-i)/periodLength of strings c
                    //x covers the interval [0,i[
                    ans+=x;
                    //now we will cover the interval [i,wl[
                    ans+=((x-cnt[ida]))*((wl-i)/periodLength);
                    int rest=((wl-i))%periodLength;

                    int idcc=0;
                    for(int id=i+(wl-i)/periodLength*periodLength;id<wl;id++)
                    {
                        idcc%=c.size();
                        int ida=id%a.size();

                        if(c[idcc]==a[ida])
                            idcc++;

                        if(idcc==c.size())
                            ans++;
                    }
                    // cout<<ans<<endl;
                    cout<<ans/d<<endl;
                    return 0;
                }
                // cout<<i<<" "<<x<<endl;
                //  system("pause");
                cnt[ida]=x;
                vis[ida]=1;
                start[ida]=i;
            }
//            last_a_pos=i;
            idc++;
            idc%=c.size();
            if(idc==0)
                x++;
        //    cout<<"test "<<i<<" "<<x<<endl;
        }
    }
    cout<<x/d<<endl;
}
