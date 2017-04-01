#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'

bool isChar(char x){
  x=tolower(x);
  return (x>='a'&&x<='z');
}
main(){
  int n;
  cin>>n;
  cin.ignore();

  for(int c=1;c<=n;c++){
    bool U=0,P=0,I=0;
    double UU,PP,II;
    string s;
    getline(cin,s);
    int sz=s.size();
    for(int j=0;j<sz;j++){
      int i=j;
      if(s[i]=='=')
      {
        if(s[i-1]=='U'){
          U=1;
          string cur="";
          i++;
          while(!isChar(s[i])){
            cur+=s[i];
            i++;
          }
          UU=stod(cur);
          if(s[i]=='m')
           UU/=1000;
          if(s[i]=='k')
           UU*=1000;
          if(s[i]=='M')
           UU*=1000000;
        }
        else
        if(s[i-1]=='P'){
          P=1;
          string cur="";
          i++;
          while(!isChar(s[i])){
            cur+=s[i];
            i++;
          }
          PP=stod(cur);
          if(s[i]=='m')
           PP/=1000;
          if(s[i]=='k')
           PP*=1000;
          if(s[i]=='M')
           PP*=1000000;
        }
        else
        if(s[i-1]=='I'){
          I=1;
          string cur="";
          i++;
          while(!isChar(s[i])){
            cur+=s[i];
            i++;
          }
          II=stod(cur);
          if(s[i]=='m')
           II/=1000;
          if(s[i]=='k')
           II*=1000;
          if(s[i]=='M')
           II*=1000000;
        }
      }
    }
    cout<<"Problem #"<<c<<endl;
    if(I&&U){
      cout<<"P="<<fixed<<setprecision(2)<<UU*II<<"W"<<endl;
    }
    if(I&&P){
      cout<<"U="<<fixed<<setprecision(2)<<PP/II<<"V"<<endl;
    }
    if(U&&P){
      cout<<"I="<<fixed<<setprecision(2)<<PP/UU<<"A"<<endl;
    }
    cout<<endl;
  }
}
