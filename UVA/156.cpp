#include<bits/stdc++.h>

using namespace std;
#define endl '\n'
main(){
    ios_base::sync_with_stdio(false);
    map<string,string> name;
    map<string,int> M;
    string s;
    while(getline(cin,s)){
        if(s=="#")
            break;
        int sz=s.size();
        string cur="";
        for(int i=0;i<sz+1;i++){
            if(i==sz||s[i]==' '){
                if(cur!=""){
                    string tmp=cur;
                    for(int j=0;j<tmp.size();j++){
                        if(tmp[j]>='A'&&tmp[j]<='Z'){
                            tmp[j]=char('a'+tmp[j]-'A');
                        }
                    }
                    sort(tmp.begin(),tmp.end());
                   // cout<<"test "<<tmp<<endl;
                    M[tmp]++;
                    name[tmp]=cur;
                }
                cur="";
            }
            else{
                cur+=s[i];
            }
        }
    }
    vector<string> ans;
    for(auto v:M)
    {
        int x=v.second;
        string ss=v.first;
        if(x==1)
        {
            ans.push_back(name[ss]);
        }
    }
    sort(ans.begin(),ans.end());
    for(auto e:ans){
        cout<<e<<endl;
    }
}
