#include<bits/stdc++.h>
using namespace std;


main(){
  string s,s1;
  while(getline(cin,s)){
    getline(cin,s1);
    s+="#";
    s1+="#";
    int sz=s.size();
    int sz1=s1.size();
    int i=0;
    string cur="";
    vector<string> v,v1;
    for(int i=0;i<sz;i++){
      if(s[i]>='0'&&s[i]<='9')
        cur+=s[i];
      else{
        if(cur!="")
          v.push_back(cur);
        cur="";
      }
    }
    for(int i=0;i<sz1;i++){
      if(s1[i]>='0'&&s1[i]<='9'){
        cur+=s1[i];
      }
      else{
        if(cur!="")
          v1.push_back(cur);
        cur="";
      }
    }
    sort(v.begin(),v.end());
    sort(v1.begin(),v1.end());
    if(v==v1){
      cout<<"A equals B"<<endl;
    }
    else{
      string fst="A";
      string scd="B";
      sz=v.size();
      sz1=v1.size();
      if(sz>sz1){
        swap(fst,scd);
        swap(v,v1);
        swap(sz,sz1);
      }
      map<string,bool> is;
      for(int i=0;i<sz1;i++){
        is[v1[i]]=1;
      }
      bool X=0,Y=0;
      for(int i=0;i<sz;i++){
        if(!is[v[i]]){
          X=1;
        }
        else{
          Y=1;
        }
      }
      if(!X&&Y){
        cout<<fst<<" is a proper subset of "<<scd<<endl;
      }
      if(X&&!Y){
        cout<<"A and B are disjoint"<<endl;
      }
      if(X&&Y){
        cout<<"I'm confused!"<<endl;
      }
    }
  }
}
