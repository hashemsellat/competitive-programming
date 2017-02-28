#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int
#define ii pair<int,int>
int a[2000][2000],bit[2000][2000],s;
void updatey(int x,int y,int val){
    for(;y<=s;){

        bit[x][y]+=val;
        y+=(y&(-y));
    }
}
void update(int x,int y,int val){
    for(;x<=s;){
        updatey(x,y,val);
        x+=(x&(-x));
    }
}
int query(int x,int yy){
    int ret=0;
    for(;x>0;){
        int y=yy;
       // cout<<"TOO"<<" "<<x<<" "<<y<<endl;
        for(;y>0;){
           // cout<<"Test "<<x<<" "<<y<<endl;
            ret+=bit[x][y];
            y-=(y&(-y));
        }
       // cout<<"FOO"<<" "<<x<<" "<<x-(x&(-x))<<endl;
        x-=(x&(-x));
    }
    return ret;
}
main(){
    int t;
    ios_base::sync_with_stdio(false);
    while(cin>>t){
        if(t==0){
            cin>>s;
        }
        if(t==1){
            int x,y,m;
            cin>>x>>y>>m;
            x++;y++;
            update(x,y,m);
        }
        if(t==2){
            int l,b,r,t;
            cin>>l>>b>>r>>t;
            l++;b++;r++;t++;
            int ans=0;
           // cout<<"test"<<endl;
            //cout<<r<<" "<<t<<" "<<query(r,t)<<endl;
          //  cout<<query(r,t)<<" "<<query(l-1,b)<<" "<<query(l,b-1)<<" "<<query(l-1,b-1)<<endl;
            cout<<query(r,t)-query(l-1,t)-query(r,b-1)+query(l-1,b-1)<<endl;
        }
     /*   for(int i=1;i<=s;i++){
            cout<<"Test ";
            for(int j=1;j<=s;j++)
                cout<<a[i][j]<<" ";
            cout<<endl;
        }*/
        if(t==3){
            break;
        }
    }
}
