#include <iostream>
using namespace std;
const int MAXN = 1e6;
int b[MAXN],tree[MAXN];
int rev[MAXN],ans[MAXN];
void build(int node,int l,int r){

    if(l==r){
        tree[node]=1;
        rev[node]=r;
        return;
    }
    int md=(l+r)/2;
    build(2*node,l,md);
    build(2*node+1,md+1,r);
    tree[node]=tree[2*node]+tree[2*node+1];
}
// i need the element number x from the right
int query(int node,int l,int r,int x){
    int md=(l+r)/2;
    if(l==r)
        return node;
    if(x==0){
            if(tree[2*node]!=0){
                return query(2*node,l,md,0);
            }
            else{
                return query(2*node+1,md+1,r,0);
            }
    }
    if(tree[2*node+1]>=x){
        return query(2*node+1,md+1,r,x);
    }
    else{
        return query(2*node,l,md,x-tree[2*node+1]);
    }
}
int n;
void update(int x,int hoo){
    int node = query(1,0,n-1,x+1);
    ans[hoo-1]=rev[node]+1;
    tree[node]--;
    node/=2;
    while (node)
    {
        tree[node]=tree[2*node]+tree[2*node+1];
        node/=2;
    }
}
int main() {
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        build(1,0,n-1);
        for(int i=n-1;i>=0;i--){
            update(b[i],i+1);
        }
        for(int i=0;i<n;i++) {
            if(i)
                cout<<" ";
            cout<<ans[i];
        }
        cout<<endl;
//        cout<<"HOO"<<endl;
//        int x;
//        while(cin>>x){
//            cout<<query(1,0,n-1,x);
//        }
    }
}