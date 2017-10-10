#include <iostream>
using namespace std;
#define int long long int
const int MAXN = 1e6;
struct node{
    int sm;
    int sqsm;
    int cnt;
};
node tree[MAXN];
bool isSetLazy[MAXN];
int lazy[MAXN],lazySet[MAXN];
void init(int n)
{
    for(int i=0;i<3*n;i++){
        lazy[i]=lazySet[i]=isSetLazy[i]=0;
    }
}
void pass(int node,int x,bool isSet){
    if(isSet){
        lazy[node]=0;
        isSetLazy[node]=1;
        lazySet[node]=x;
    }
    else{
        lazy[node]+=x;
    }
}
inline void checkIfLazy(int node,int l,int r){
    if(isSetLazy[node]){
        int num=lazySet[node]+lazy[node];
        tree[node].sm=num*tree[node].cnt;
        tree[node].sqsm=(num*num)*tree[node].cnt;
        isSetLazy[node]=0;
        if(l!=r){
            pass(2*node,lazySet[node],1);
            pass(2*node,lazy[node],0);
            pass(2*node+1,lazySet[node],1);
            pass(2*node+1,lazy[node],0);
        }
        lazy[node]=0;
    }
    else
    if(lazy[node])
    {
        tree[node].sqsm=tree[node].sqsm+2*lazy[node]*tree[node].sm+tree[node].cnt*lazy[node]*lazy[node];
        tree[node].sm=tree[node].sm+tree[node].cnt*lazy[node];
        if(l!=r){
            pass(2*node,lazy[node],0);
            pass(2*node+1,lazy[node],0);
        }
        lazy[node]=0;
    }
}
node merge_(node L,node R){
    node ret;
    ret.cnt=L.cnt+R.cnt;
    ret.sm=L.sm+R.sm;
    ret.sqsm=L.sqsm+R.sqsm;
    return ret;
}
void update(int node,int l,int r,int i,int j,int c,bool isSet){
    if(l>r){
        return;
    }
    checkIfLazy(node,l,r);
    if(l>j||r<i)
        return;
    if(l>=i&&r<=j)
    {
        if(isSet){
            isSetLazy[node]=1;
            lazySet[node]=c;
            checkIfLazy(node,l,r);
        }
        else{
            lazy[node]+=c;
            checkIfLazy(node,l,r);
        }
        return ;
    }
    int md=(l+r)/2;
    update(2*node,l,md,i,j,c,isSet);
    update(2*node+1,md+1,r,i,j,c,isSet);
    tree[node]=merge_(tree[2*node],tree[2*node+1]);
}
int query(int node,int l,int r,int i,int j){
    if(l>r)
        return 0;
    checkIfLazy(node,l,r);
    if(l>j||r<i){
        return 0;
    }
    if(l>=i&&r<=j){
        return tree[node].sqsm;
    }
    int md=(l+r)/2;
    return query(2*node,l,md,i,j)+query(2*node+1,md+1,r,i,j);
}
#define endl '\n'
int a[MAXN];
void build_(int node,int l,int r){
    if(l==r){
        tree[node].sqsm=a[l]*a[l];
        tree[node].sm=a[l];
        tree[node].cnt=1;
        return;
    }
    int md=(l+r)/2;
    build_(2*node,l,md);
    build_(2*node+1,md+1,r);

    tree[node].sm=tree[2*node].sm+tree[2*node+1].sm;
    tree[node].sqsm=tree[2*node].sqsm+tree[2*node+1].sqsm;
    tree[node].cnt=tree[2*node].cnt+tree[2*node+1].cnt;
}
main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    int cnt=0;
    while(t--){
        cout<<"Case "<<++cnt<<":"<<endl;
        int n,q;
        cin>>n>>q;
        init(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        build_(1,0,n-1);
        for(int i=0;i<q;i++){
            int x,st,ed,type;
            cin>>type>>st>>ed;
            if(type!=2)
                cin>>x;
            st--;ed--;
            if(type==0){
                update(1,0,n-1,st,ed,x,1);
            } else
            if(type==1){
                update(1,0,n-1,st,ed,x,0);
            } else
            {
                cout<<query(1,0,n-1,st,ed)<<endl;
            }

        }
    }
}