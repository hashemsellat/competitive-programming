#include<bits/stdc++.h>
#define point complex<double>
#define ii pair<int,int>
#define iii pair<int,ii>
#define endl '\n'
using namespace std;
int i,sz;
string f(string &s){
    vector<string> child;
    string ret="(";
    while(i<sz&&s[i]=='0'){
        i++;
        string cur=f(s);
        child.push_back(cur);
    }
    i++;
    sort(child.begin(),child.end());
    for(auto v:child){
        ret+=v;
    }
    return ret+")";
}

main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        sz=s.size();
        i=0;
        string one=f(s);
        cin>>s;
        sz=s.size();
        i=0;
        string two=f(s);
        if(one==two){
            cout<<"same"<<endl;
        }
        else
            cout<<"different"<<endl;
    }
}
