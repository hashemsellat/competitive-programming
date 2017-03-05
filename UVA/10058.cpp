#include<bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define iii pair<int,ii>
#define int long long int
#define endl '\n'
#define vi vector<int>
set<string> NOUN,VERB,ARTICLE;
bool solve(vector<string> v)
{
    for(auto &x:v)
    {
        if(NOUN.find(x)!=NOUN.end())
        {
            x="NOUN";
        }
        if(VERB.find(x)!=VERB.end())
        {
            x="VERB";
        }
        if(ARTICLE.find(x)!=ARTICLE.end())
        {
            x="ARTICLE";
        }
    }

    int sz=v.size();
    vector<string> tmp;
    for(int i=0; i<sz; i++)
    {
        if(v[i]=="ARTICLE")
        {
            if(i+1==sz||v[i+1]!="NOUN")
                return 0;
            else
                tmp.push_back("ACTOR");
            i++;
        }
        else
        {
            if(v[i]=="NOUN")
                tmp.push_back("ACTOR");
            else
                tmp.push_back(v[i]);
        }
    }

    v=tmp;
    tmp.clear();
    sz=v.size();
    for(int i=0; i<sz; i++)
    {
        if(i<sz-1&&v[i+1]=="and")
        {
            while(i<sz-1&&v[i+1]=="and")
            {
                if(i+2==sz||v[i]!="ACTOR"||v[i+2]!="ACTOR")
                    return 0;
                i+=2;
            }
            tmp.push_back("ACTIVE_LIST");
        }
        else
        {
            if(v[i]=="ACTOR")
            {
                tmp.push_back("ACTIVE_LIST");
            }
            else
                tmp.push_back(v[i]);
        }
    }
    v=tmp;
    sz=v.size();
    for(int i=0; i<sz; i++)
    {
        if(i<sz-1&&v[i+1]=="VERB")
        {
            if(i+2==sz||v[i]!="ACTIVE_LIST"||v[i+2]!="ACTIVE_LIST")
                return 0;
            tmp.push_back("ACTION");
            i+=2;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}
main()
{
    vector<string> tmp= {"tom","jerry","goofy","mickey","jimmy","dog","cat","mouse"};
    for(auto x:tmp)
        NOUN.insert(x);
    tmp= {"hate","love","know","like"};
    for(auto x:tmp)
        VERB.insert(x);
    for(auto x:tmp)
        VERB.insert(x+"s");
    ARTICLE.insert("a");
    ARTICLE.insert("the");
    string s;
    while(getline(cin,s))
    {
        vector<vector<string> >v;
        stringstream ss(s);
        string tmp;
        vector<string> emp;
        v.push_back(emp);
        //int cnt=0;
        while(ss>>tmp)
        {
            if(tmp==",")
            {
                v.push_back(emp);
                continue;
            }
            v[v.size()-1].push_back(tmp);
        }
        int ret=1;
        for(auto x:v)
        {
            ret&=solve(x);
        }
        if(ret)
        {
            cout<<"YES I WILL"<<endl;
        }
        else
            cout<<"NO I WON'T"<<endl;
    }
}
