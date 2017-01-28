#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
vector<string> v;
struct node{
    vector<int> lst;
    node *child[26];
    node(){
        memset(child,0,sizeof(child));
    }
} *head;
void insert(string &s,int id){
   // cout<<"test"<< " "<<s<<endl;
    int sz=s.size();
    node *it=head;
    for(int i=0;i<sz;i++){
        char cur=s[i]-'a';
        if(!(it->child[cur])){
            (it->child[cur])=new node();
        }
        it=(it->child[cur]);
        if((it->lst).size()<2){
            (it->lst).push_back(id);
        }
    }
}
int getId(string s){
    int sz=s.size();
    node *it=head;
    int ret=-1;
    string rev=s;
    reverse(rev.begin(),rev.end());
    for(int i=0;i<sz;i++){
        char cur=rev[i]-'a';
        if(!(it->child[cur])){
            return ret;
        }
        it=it->child[cur];
        int szlst=it->lst.size();
        for(int j=0;j<szlst;j++){

            if(v[(it->lst[j])]!=s){
                //cout<<"DFdS "<<cur<<" "<<v[it->lst[j]]<<endl;
                ret=it->lst[j];
                break;
            }
        }
    }
    return ret;
}
main(){
    head=new node();
    string l;
    ios_base::sync_with_stdio(false);
    while(getline(cin,l)){
        if(l.size()==0)
            break;
        int sz=l.size();
        v.push_back(l);
    }
    sort(v.begin(),v.end());
    int sz=v.size();
    for(int i=0;i<sz;i++){
        string rev=v[i];
        reverse(rev.begin(),rev.end());
        insert(rev,i);
    }
  //  cout<<v[getId("rhyme")]<<endl;
    while(getline(cin,l)){
        int ans=getId(l);
       // cout<<ans<<endl;
        if(ans!=-1)
            cout<<v[getId(l)]<<endl;
        else{
            for(int i=0;i<2;i++){
                if(v[i]!=l){
                    cout<<v[i]<<endl;
                    break;
                }
            }
        }
    }
}
