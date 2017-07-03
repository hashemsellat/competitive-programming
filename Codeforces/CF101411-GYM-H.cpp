#include<bits/stdc++.h>
using namespace std;
#define int long long int
string s;
int dp[20][2][2];
int f(int pos,bool prvOne,bool isSmaller){
    if(pos==s.size())
        return 1;
    if(dp[pos][prvOne][isSmaller]!=-1)
        return dp[pos][prvOne][isSmaller];
    int ret=0;
    for(int i=0;i<10;i++){
        if(i==3&&prvOne)
            continue;
        if(!isSmaller&&i>s[pos]-'0')
            break;
        ret+=f(pos+1,i==1,isSmaller||i<s[pos]-'0');
    }
    return dp[pos][prvOne][isSmaller]=ret;
}
int cnt(int num){
    memset(dp,-1,sizeof(dp));
    string cur="";
    int tmp=num;
    while(tmp){
        cur=char('0'+tmp%10)+cur;
        tmp/=10;
    }
    s=cur;
  //  cout<<"FS "<<cur<<endl;
    return f(0,0,0)-1;
}
string convert(int num){
    int tmp=num;
    string cur="";
    while(tmp){
        cur=char('0'+tmp%10)+cur;
        tmp/=10;
    }

    for(int i=0;i<cur.size()-1;i++){
        if(cur[i]=='1'&&cur[i+1]=='3'){
            cur[i+1]='2';
            for(int j=i+2;j<cur.size();j++)
                cur[j]='9';
            return cur;
        }
    }
    return cur;
}
main(){
    freopen("hotel.in","r",stdin);
    freopen("hotel.out","w",stdout);
    int t;
    cin>>t;
    while(t--){

        int n;
        cin>>n;
        int mn=1,mx=4*1e18;
        //cout<<mx<<endl;
        while(mn+1<mx){
            int md=(mn+mx)/2;
            int tmp=cnt(md);
           // cout<<md<<" "<<cnt(md)<<endl;
            if(tmp<=n){
                mn=md;
            }
            else
                mx=md;
        }
        cout<<convert(mn)<<endl;
    }
}