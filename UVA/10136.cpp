#include <bits/stdc++.h>
using namespace std;
#define dd pair<double, double>
const double r=2.5;
const double EPS = 1e-9;
double dist(double x1,double y1,double x2,double y2){
  return hypot(x1-x2,y1-y2);
}
bool isEqual(double x,double y){
  return abs(x-y)<EPS;
}

std::vector<dd> v;
main() {
/*  while(1){
    double x,y,x1,y1;
    cin>>x>>y>>x1>>y1;
    cout<<dist(x,y,x1,y1)<<endl;
  }*/
  freopen("out.txt","w",stdout);
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  cin.ignore();
  bool is=0;
  for (int i = 0; i < t; i++) {
    v.clear();
    if(is)  cout<<endl;
    is=1;
    string s;
    int ans=0;
    bool is1=0;
    while (getline(cin, s)) {
      if(s==""&&!is1) continue;
      is1=1;
      if(s=="") break;
      string l = "", r = "";
      int i = 0;
      while (s[i] != ' ') {
        l += s[i];
        i++;
      }
      while (s[i] == ' ')
        i++;
      while (i < s.size()) {
        r += s[i];
        i++;
      }
      double ll = stod(l);
      double rr = stod(r);
    //  cout<<ll<<" "<<rr<<endl;
      v.push_back(dd(ll, rr));
    }

    // v is the vector of points
    int sz = v.size();
  //  cout<<sz<<endl;
    for (int i = 0; i < sz; i++) {
      for (int j = 0; j < sz; j++) {
        if(i==j){
          continue;
        }
        double x1=v[i].first,y1=v[i].second;
        double x2=v[j].first,y2=v[j].second;
        if(dist(x1,y1,x2,y2)>2*r+EPS) continue;
        //now we find the mid points
        double x3=(x2+x1)/2,y3=(y2+y1)/2;
        double l=sqrt(r*r-pow(dist(x1,y1,x2,y2),2)/4.0);
        double x0_0,y0_0,x0_1,y0_1;
        if(isEqual(x1-x2,0)){
          x0_0=x3-l;
          y0_0=y3;
          x0_1=x3+l;
          y0_1=y3;
          int cnt1=0,cnt2=0;
          for(int e=0;e<sz;e++){
            if(dist(v[e].first,v[e].second,x0_0,y0_0)<=r+EPS){
              cnt1++;
            }
            if(dist(v[e].first,v[e].second,x0_1,y0_1)<=r+EPS){
              cnt2++;
            }
          }
          ans=max(ans,cnt1);
          ans=max(ans,cnt2);
        }
        else{
          if(isEqual(y1-y2,0)){
            x0_0=x3;
            y0_0=y3+l;
            x0_1=x3;
            y0_1=y3-l;
            int cnt1=0,cnt2=0;
            for(int e=0;e<sz;e++){
              if(dist(v[e].first,v[e].second,x0_0,y0_0)<=r+EPS){
                cnt1++;
              }
              if(dist(v[e].first,v[e].second,x0_1,y0_1)<=r+EPS){
                cnt2++;
              }
            }
            ans=max(ans,cnt1);
            ans=max(ans,cnt2);
          }
          else{
            double dx[]={1,-1};
            for(int k=0;k<2;k++){
              double m=(y1-y2)/(x1-x2);
              double mm=-1/m;
              double teta=atan(mm);
              double x0,y0;
              x0=x3+dx[k]*l*cos(teta);
              //y=mmx+c
              double c=y3-mm*x3;
              y0=mm*x0+c;
          //    cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<x0<<" "<<y0<<endl;
              int cnt=0;
              for(int e=0;e<sz;e++){
                if(dist(v[e].first,v[e].second,x0,y0)<=r+EPS){
                  cnt++;
                }
              }
              ans=max(ans,cnt);
            }
          }
        }
      }
    }
    if(!ans&&v.size()){
      cout<<1<<endl;
    }
    else
      cout << ans << endl;
  }
}
