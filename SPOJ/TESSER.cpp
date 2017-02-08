#include<bits/stdc++.h>
using namespace std;
int a[1000000];
main(){
    int t;
    cin>>t;
    while(t--){
        vector<int> z;
        int n;
        cin>>n;
        string s="";
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(i>0){
                if(a[i]>a[i-1])
                    s+="G";
                if(a[i]<a[i-1])
                    s+="L";
                if(a[i]==a[i-1])
                    s+="E";
            }
        }
        string p;
        cin>>p;
        int szp=p.size();
        s=p+"#"+s;
        int l=0,r=0;
        int sz=s.size();
        z.assign(sz+10,0);
        bool f=0;
        for(int k=1;k<sz;k++){
            if(k>r){
                l=r=k;
                while(s[r]==s[r-l]&&r<sz){
                    r++;
                }
                z[k]=r-l;
                r--;
            }
            else{
                int k1=k-l;
                if(z[k1]<r-k+1){
                    z[k]=z[k1];
                }
                else{
                    l=k;
                    while(s[r]==s[r-l]){
                        r++;
                    }
                    z[k]=r-l;
                    r--;
                }
            }
            if(z[k]==szp){
                f=1;
                break;
            }
        }
        if(f){
            cout<<"YES"<<endl;
        }
        else
            cout<<"NO"<<endl;

    }
}
