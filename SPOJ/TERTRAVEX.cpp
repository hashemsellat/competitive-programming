#include<bits/stdc++.h>
#define ii pair<int,int>
#define iii pair<ii,int>
#define endl '\n'
using namespace std;
#define A first.first
#define B first.second
#define C second.first
#define D second.second
#define ii pair<int,int>
#define iiii pair<ii,ii>
iiii a[3][3];

int rev(int i,int j)
{
    return i*3+j;
}
main()
{
    int t;
    ios_base::sync_with_stdio(false);
    cin>>t;
    for(int c=1; c<=t; c++)
    {
        int p[]= {0,1,2,3,4,5,6,7,8};
        iiii tmp[10];
        for(int i=0; i<9; i++)
        {
            cin>>tmp[i].A>>tmp[i].B>>tmp[i].C>>tmp[i].D;
        }
        bool is=1;
        do
        {
            is=1;
            for(int k=0; k<9; k++)
            {
                int i=k/3;
                int j=k%3;
                if(i+1!=3)
                {
                    iiii nxt=tmp[p[rev(i+1,j)]];
                    if(nxt.A!=tmp[p[k]].C)
                        is=0;
                }
                if(j+1!=3)
                {
                    iiii nxt=tmp[p[rev(i,j+1)]];
                    if(nxt.D!=tmp[p[k]].B)
                        is=0;
                }
            }
            if(is)
            {
                break;
            }
        }
        while(next_permutation(p,p+9));
        if(is)
        {
            cout<<"Case "<<c<<": "<<"YES"<<endl;
        }
        else
            cout<<"Case "<<c<<": "<<"NO"<<endl;
    }
}
