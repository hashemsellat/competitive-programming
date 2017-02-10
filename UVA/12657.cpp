#include<bits/stdc++.h>
using namespace std;
#define int long long int
struct node{
    int value;
    node *L;
    node *R;
    node(int i){
        value=i;
        L=0;
        R=0;
    }
};
node *a[1000000];
#define endl '\n'
//void putOnRight(node )
main(){
    int n,m;
    int cnter=1;
    freopen("out.txt","w",stdout);
    while(cin>>n>>m){
        for(int i=0;i<=n+1;i++)
            a[i]=new node(i);
       // a[n+1]=new node(n+1);a[0]=new node(0);
        a[0]->R=a[1];
        a[n+1]->L=a[n];

        for(int i=1;i<=n;i++){
          //  a[i]=new node(i);
            a[i]->L=a[i-1];
            a[i]->R=a[i+1];
            //cout<<a[i]->L->value<<endl;
        }bool r=0;
        //cout<<a[1]->L->value<<endl;
        for(int i=0;i<m;i++){
            int t;
            scanf("%lld",&t);
            if(t==4)
            {
                r=!r;
                continue;
            }
            int x,y;
            cin>>x>>y;
            if(t==1&&r==1)
                t=2;
            else
            if(t==2&&r==1)
                t=1;
            if(t==1){
                if(a[y]->L==a[x])   continue;
                a[x]->R->L=a[x]->L;
                a[x]->L->R=a[x]->R;

                a[y]->L->R=a[x];
                a[x]->L=a[y]->L;
                a[y]->L=a[x];

                a[x]->R=a[y];
            }
            if(t==2){
                if(a[y]->R==a[x])   continue;
                a[x]->L->R=a[x]->R;
                a[x]->R->L=a[x]->L;

                a[y]->R->L=a[x];
                a[x]->L=a[y];
                a[x]->R=a[y]->R;
                a[y]->R=a[x];
            }
            if(t==3){
            //    node *xL=a[x]->L;
            //    node *xR=a[x]->R;
                if(a[x]->L==a[y]){
                    node *tmp=a[x]->R;
                    a[x]->R->L=a[y];
                    a[y]->L->R=a[x];

                    a[x]->L=a[y]->L;
                    a[x]->R=a[y];
                    a[y]->R=tmp;
                    a[y]->L=a[x];

                    continue;
                }
                if(a[x]->R==a[y]){
                    a[x]->L->R=a[y];
                    a[y]->R->L=a[x];
                    node *tmp=a[x]->L;

                    a[x]->L=a[y];
                    a[x]->R=a[y]->R;

                    a[y]->L=tmp;
                    a[y]->R=a[x];

                    continue;
                }
                a[x]->L->R=a[y];
                a[x]->R->L=a[y];

                a[y]->L->R=a[x];
                a[y]->R->L=a[x];

                swap(a[y]->L,a[x]->L);
                swap(a[y]->R,a[x]->R);

               // a[y]->L=xL;
               // a[y]->R=xR;
            }
        }
        node *cur=a[1];
        while(cur->L->value!=0){
            cur=cur->L;
            //cout<<cur->L->value<<endl;
        }
        //cout<<"TOO"<<endl;
        int sm=(n*(n+1))/2,ans=0;
        int cnt=1;
        while(cur->value!=n+1){
            if(cnt%2)
                ans+=cur->value;
            cnt++;
           // cout<<cur->value<<" ";
            //cout<<cur->value<<endl;
            cur=cur->R;
        }
      //  cout<<endl;
        if(r&&(n%2==0))   ans=sm-ans;
        cout<<"Case "<<cnter++<<": "<<ans<<endl;
      //  printf("Case %lld: %lld\n",cnter++,ans);
    }
}
