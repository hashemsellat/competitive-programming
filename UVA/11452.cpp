
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
main(){
    int n;
    ios_base::sync_with_stdio(false);
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        int n=s.size();
        for(int i=0;i<n;i++){
            int sz=i+1;
            bool f=1;
            for(int j=i+1;j<2*sz;j++){
                if(s[j]!=s[j-sz]){
                    f=0;break;
                }
            }
            if(f){
                int j=2*sz;
                for(j;j<n;j++){
                    //cout<<">> "<<j<<endl;
                    if(j-2*sz>=sz)
                    {
                        f=0;break;
                    }
                    if(s[j]!=s[j-2*sz])
                    {
                        //cout<<sz<<" "<<j<<endl;
                        f=0;
                        break;
                    }
                }
                if(f){
                   // cout<<sz<<" "<<j<<endl;
                    int cnt=0;

                    for(int k=j-2*sz;cnt<8;k++,cnt++)
                        cout<<s[(k%sz)];
                    cout<<"..."<<endl;
                    break;
                }
            }
        }
    }
}
