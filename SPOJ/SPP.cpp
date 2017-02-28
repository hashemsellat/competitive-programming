#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int
#define ii pair<int,int>
#define mat vector<vector<int> >
int k,MOD;
int csm[20];
mat addI(mat x)
{
    int n=x.size();
    for(int i=0; i<n; i++)
        x[i][i]++;
    return x;
}
mat mult(mat a,mat b)
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
mat powSum(mat a,int k)
{
    //  cout<<k<<endl;
    int n=a.size();
    mat ret(n,vector<int>(n,0));
    if(k==0)
        return ret;
    if(k%2==1)
    {
        return(mult(a,addI(powSum(a,k-1))));
    }
    else
        return mult(powSum(a,k/2),addI(powMat(a,k/2)));
}
mat l,r;
int b[20],c[20];
int sm(int id)
{
    if(id<0)
        return 0;
    int cur=0;
    //if(id<=k){

    for(int i=0; i<k; i++)
        cur+=b[i];
    if(id<=k)
    {
        int foo=0;
        for(int i=0;i<id;i++){
            foo+=b[i];
        }
        return foo;
    }
    //}
    //  cout<<"FOO"<<endl;
    mat ret=mult(l,powSum(r,id-k));
    // cout<<"TOO"<<endl;
    return cur+ret[0][k-1];
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
main()
{
    ios_base::sync_with_stdio(false);
    int d;
    cin>>d;
    while(d--)
    {
        cin>>k;
        for(int i=0; i<k; i++)
            cin>>b[i];
        for(int i=0; i<k; i++)
            cin>>c[i];
        int m,n;
        cin>>m>>n>>MOD;
        mat ll(k,vector<int>(k,0)),
            rr(k,vector<int>(k,0));
        for(int i=0; i<k; i++)
            ll[0][i]=b[i];
        for(int i=1; i<k; i++)
            rr[i][i-1]=1;
        for(int i=0; i<k; i++)
            rr[i][k-1]=c[k-1-i];
        l=ll;
        r=rr;
        //  prnt(l);
        //   prnt(r);
        //  cout<<sm(n)<<endl;
        //  cout<<"HOO"<<endl;
        cout<<(sm(n)-sm(m-1)+MOD)%MOD<<endl;
    }
}
