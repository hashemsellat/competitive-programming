/*
    use two pointers to trace the interval of valid characters
*/

#include<bits/stdc++.h>
using namespace std;
const int N=3*1e5;
#define endl '\n'
#define sz(s)   int(s.size())
int last[26][N],ans[26][N],is[N],ansr[26][N];
main()
{
    ios_base::sync_with_stdio(false);
    string s,t;
    ios_base::sync_with_stdio(false);
    cin>>s>>t;
    for(char x='a'; x<='z'; x++)
    {
        if(s[0]!=x)
            last[x-'a'][0]=1e9;
        for(int i=1; i<sz(s); i++)
        {
            if(s[i]==x)
            {
                last[x-'a'][i]=i;
            }
            else
                last[x-'a'][i]=last[x-'a'][i-1];
        }
    }
    int p=0;
    vector<int> v;
    for(int i=0; i<sz(s)&&p<sz(t); i++)
    {
        if(s[i]==t[p])
        {
            p++;

            v.push_back(i);
        }
    }
    if(p!=sz(t))
    {
        cout<<"NO"<<endl;
        return 0;
    }
    int cur=sz(t)-1;
    int lastPointer=sz(s);
    while(!v.empty())
    {
        if(cur<0)
            break;
        int beforeLast=v.back();
        lastPointer=last[t[cur]-'a'][lastPointer-1];
        if(lastPointer==1e9)
        {
            cout<<"NO"<<endl;
            return 0;
        }
        //æÌÈäÇ ÇÎÑ ÇäÏßÓ ÝíäÇ äÓÊÎÏã
        v.pop_back();
        ans[t[cur]-'a'][beforeLast]++;
        ansr[t[cur]-'a'][lastPointer]++;
        cur--;
    }
    for(char x='a'; x<='z'; x++)
    {
        int cnter=0;
        for(int i=0; i<sz(s); i++)
        {
            if(s[i]==x)
            {
                cnter+=ans[x-'a'][i];
                if(cnter)
                    is[i]=1;
                cnter-=ansr[x-'a'][i];
            }
        }
    }
    for(int i=0; i<sz(s); i++)
    {
        if(!is[i])
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;

}
