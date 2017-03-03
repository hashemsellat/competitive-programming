#include<bits/stdc++.h>
using namespace std;
#define endl '\n'


main(){
    string s;
    while(cin>>s){
        if(s=="0")
            break;
        int sz=s.size();
        int sml=0,smr=0;
        for(int i=0;i<sz;i++){
            if(i%2==0)
                sml+=s[i]-'0';
            else
                smr+=s[i]-'0';
        }
        if((sml-smr)%11==0){
            cout<<s<<" is a multiple of 11."<<endl;
        }
        else
            cout<<s<<" is not a multiple of 11."<<endl;
    }
}
