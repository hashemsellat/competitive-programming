#include<bits/stdc++.h>
using namespace std;
const int N = 1000000;
#define endl '\n'
int tree[N],rev[N/3],a[N/3];
int build(int v,int l,int r){
    int md=(l+r)/2;
    if(l==r){
        rev[l]=v;
        tree[v]=a[l];
        return a[l];
    }
    int L=build(2*v,l,md);
    int R=build(2*v+1,md+1,r);
    return tree[v]=min(L,R);
}
int query(int v,int l,int r,int i,int j){
    int md=(l+r)/2;
    if(l>=i&&r<=j){
       // cout<<"HOO "<<l<<" "<<r<<endl;
        return tree[v];
    }
    if(l>j||r<i||l>r)
        return 1e9;
    int L=query(2*v,l,md,i,j);
    int R=query(2*v+1,md+1,r,i,j);

    return min(L,R);
}
void update(int v,int num){
    a[v]=num;
    int id=rev[v];
    tree[id]=num;
    id/=2;
    while(id!=0){
        tree[id]=min(tree[2*id],tree[2*id+1]);
        id/=2;
    }
}
main(){
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    build(1,1,n);
    for(int i=0;i<m;i++){
        string s;
        cin>>s;
        vector<int> v,vv;
        int j=0;
        int sz=s.size();
        while(!(s[j]>='0'&&s[j]<='9')){
            j++;
        }
     //   cout<<j<<endl;
        string num="";
        for(j;j<sz;j++){
            if(s[j]==','||s[j]==')'){
                //cout<<":D "<<num<<endl;
                //num="";
                int cur=atoi(num.c_str());
                v.push_back(cur);
                vv.push_back(a[cur]);
                num="";
                continue;
            }
            num+=s[j];
        }
        sz=v.size();
        /*for(int i=0;i<sz;i++){
            cout<<v[i]<<endl;
        }*/
        if(s[0]=='q'){
          //  cout<<v[0]<<" "<<v[1]<<endl;
            cout<<query(1,1,n,v[0],v[1])<<endl;
        }
        else{
            for(int i=0;i<sz;i++){
                update(v[i],vv[(i+1)%(sz)]);
                //cout<<v[i]<<" "<<vv[(i+1)]
            /*    for(int j=1;j<=n;j++)
                    cout<<a[j]<<" ";
                cout<<endl;*/
            }
        }
    }
}
