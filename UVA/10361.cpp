#include<bits/stdc++.h>
using namespace std;

main(){
  int n;
  cin>>n;
  string s;
  cin.ignore();
  while(n--){

    getline(cin,s);
    int sz=s.size();
    string cur="";
    bool is=0;
    vector<string> v;
    bool foo=0;
    for(int i=0;i<sz;i++){
      if(s[i]!='<'&&s[i]!='>')
        cout<<s[i];
    }
    v.clear();
    int j=0;
    while(s[j]!='<'){
      cur+=s[j];
      j++;
    }
    v.push_back(cur);
    cur="";
    j++;
    while(s[j]!='>'){
      cur+=s[j];
      j++;
    }
    v.push_back(cur);
    cur="";
    j++;
    while(s[j]!='<'){
      cur+=s[j];
      j++;
    }
    v.push_back(cur);
    cur="";
    j++;
    while(s[j]!='>'){
      cur+=s[j];
      j++;
    }
    v.push_back(cur);
    cur="";
    j++;
    while(j<sz){
      cur+=s[j];
      j++;
    }
    v.push_back(cur);
    cout<<endl;
    getline(cin,s);
    sz=s.size();
    for(int i=0;i<sz;i++){
      if(s[i]=='.'&&s[i+1]=='.'&&s[i+2]=='.'){
        cout<<v[3]<<v[2]<<v[1]<<v[4]<<endl;break;
      }
      else
        cout<<s[i];
    }
  }
}
