#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
struct node{
    map<string,node*> child;
}*head;
void insert_(string s){
    int sz=s.size();
    string t="";
    node *it=head;
    for(int i=0;i<=sz;i++){
        if(s[i]=='\\'||i==sz){
            if(it->child.count(t)==0){
                it->child[t]=new node();
            }
            it=it->child[t];
            t="";
        }
        else
            t+=s[i];
    }
}
void dfs(node *it,string prefix){
    map<string,node*>::iterator itt=it->child.begin();
    for(itt ;itt!=it->child.end();itt++){
        cout<<prefix<<itt->first<<endl;
        dfs(itt->second,prefix+" ");
    }
}
main(){

    int n;
    while(cin>>n){
        head=new node();
        while(n--){
            string s;
            cin>>s;
            insert_(s);
        }
        dfs(head,"");
        cout<<endl;
    }
}
