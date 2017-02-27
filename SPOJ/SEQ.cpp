#include<bits/stdc++.h>
using namespace std;
#define mat vector<vector<int> >
#define int long long int
#define endl '\n'
const int MOD=1e9+7;
mat mult(mat &a,mat &b)
{
    //n*n
    int n=a.size();
    mat ret(n,vector<int>(n,0));

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            for(int k=0; k<n; k++)
            {
                ret[i][j]+=a[i][k]*b[k][j];
                ret[i][j]%=MOD;
            }
        }
    }
    return ret;
}

mat powMat(mat a,int p)
{
    int n=a.size();
    mat ret(n,vector<int>(n,0));
    for(int i=0; i<n; i++)
        ret[i][i]=1;
    if(p<=0)
        return ret;
    if(p%2)
    {
        mat tmp=powMat(a,p-1);
        return mult(a,tmp);
    }
    else
    {
        mat tmp=powMat(a,p/2);
        return mult(tmp,tmp);
    }
}
void prnt(mat &a)
{
    int n=a.size();
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}
int cnt[10];
main()
{
    ios_base::sync_with_stdio(false);
    int n,b,k,x;
    cin>>n>>b>>k>>x;
    for(int i=0;i<n;i++)
    {
        int y;cin>>y;
        cnt[y]++;
    }

    mat a(x,vector<int>(x,0));
    for(int i=0;i<x;i++){
        for(int j=1;j<=9;j++)
            a[i][(i*10+j)%x]+=cnt[j];
    }

    mat res=powMat(a,b);
    cout<<res[0][k]<<endl;
}
