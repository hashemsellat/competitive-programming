#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ii pair<int,int>
#define endl '\n'
#define vi vector<int>
#define vii pair<vi,int>
//map<vii,bool> vis;
unordered_map<string,string> M;
string mstra="034305650121078709a90";
void PV(vi &v,int s,int e){
    for(int i=s;i<e;i++)
        cout<<v[i]<<" ";
    cout<<endl;
}
inline string acw(string &v){
    string tmp=v;
    tmp[0]=v[10];
    tmp[1]=v[11];
    for(int i=2;i<=11;i++)
    {
        tmp[i]=v[i-2];
    }
    return tmp;
}
inline string bcw(string &v){
   // PV(v,9,21);
    string tmp=v;
    tmp[20]=v[10];
    tmp[19]=v[9];
    for(int i=18;i>=9;i--){
        tmp[i]=v[i+2];
    }
    return tmp;
   // PV(tmp,9,21);
   // system("pause");
}
inline string accw(string &v){
   // PV(v,0,12);
    string tmp=v;
    tmp[11]=v[1];
    tmp[10]=v[0];
    for(int i=9;i>=0;i--){
        tmp[i]=v[i+2];
    }
    return tmp;
  //  PV(tmp,0,12);
   // system("pause");
}

inline string bccw(string &v){
    string tmp=v;
    tmp[9]=v[19];
    tmp[10]=v[20];
    for(int i=11;i<=20;i++){
        tmp[i]=v[i-2];
    }
    return tmp;
}

void init(int prev,int cnt,string s,string res){
  //  cout<<prev<<" "<<cnt<<" "<<s<<" "<<res<<endl;
  //  system("pause");
    if(cnt==9)
        return;

    if(M.find(s)==M.end()||M[s].size()>res.size()||M[s].size()==res.size()&&res<M[s])
        M[s]=res;

    if(prev!=3)
        init(1,cnt+1,acw(s),"3"+res);
    if(prev!=4)
        init(2,cnt+1,bcw(s),"4"+res);
    if(prev!=1)
        init(3,cnt+1,accw(s),"1"+res);
    if(prev!=2)
        init(4,cnt+1,bccw(s),"2"+res);
}
string ans;
void solve(int prev,int cnt,string s,string res){
    if(cnt==9)
        return;
    if(M.find(s)!=M.end()){
        string cur=res+M[s];
        if(ans=="#"||cur.size()<ans.size()||cur.size()==ans.size()&&cur<ans){
            ans=cur;
        }
    }
    if(prev!=3)
        solve(1,cnt+1,acw(s),res+"1");
    if(prev!=4)
        solve(2,cnt+1,bcw(s),res+"2");
    if(prev!=1)
        solve(3,cnt+1,accw(s),res+"3");
    if(prev!=2)
        solve(4,cnt+1,bccw(s),res+"4");
}
main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    init(0,0,mstra,"");
    for(int i=0;i<n;i++){
        string a="";
        ans="#";
        for(int i=0;i<21;i++){
            int x;cin>>x;
            if(x<=9)
                a+=char('0'+x);
            else
                a+="a";
        }
        int x,y,z;
        cin>>x>>y>>z;
        solve(0,0,a,"");
        if(a==mstra)
            cout<<"PUZZLE ALREADY SOLVED"<<endl;
        else
            if(ans=="#"){
                cout<<"NO SOLUTION WAS FOUND IN 16 STEPS"<<endl;
            }
            else
                cout<<ans<<endl;

    }
}
