#include <bits/stdc++.h>
using namespace std;
bool isV(char x){
  x=tolower(x);
  return (x=='a'||x=='e'||x=='i'||x=='o'||x=='u');

}
bool isLetter(char x){
  return ((x>='a'&&x<='z')||(x>='A'&&x<='Z'));
}
main(){
  string s;
  while (getline(cin,s)) {
    int sz=s.size();
    s+=' ';
    bool isBegin=1;
    string cur="";
    for(int i=0;i<sz;i++){
    //  cout<<i<<" "<<s[i]<<endl;
      if(!isLetter(s[i])){
          isBegin=1;
        cout<<s[i];
        cur="";
      }
      else{
        cur+=s[i];
        if(!isLetter(s[i+1])){
          if(isV(cur[0])){
            cur+="ay";
            cout<<cur;
          }
          else{
            char add=cur[0];
            for(int j=1;j<int(cur.size());j++){
              cout<<cur[j];
            }
            cout<<add<<"ay";
          }
        }
        isBegin=0;
      }
    }
    cout<<endl;
  }
}
