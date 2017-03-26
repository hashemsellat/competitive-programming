#include<bits/stdc++.h>
using namespace std;
double dist(double x,double y,double x1,double y1){
  return hypot(x-x1,y-y1);
}
main(){
  char e;
  vector<vector<double> >v;
  while(cin>>e){
    if(e=='c'){
      vector<double> tmp;
      tmp.assign(3,3);
      cin>>tmp[0]>>tmp[1]>>tmp[2];
      v.push_back(tmp);
    }
    if(e=='r'){
      vector<double> tmp;
      tmp.assign(4,4);
      cin>>tmp[0]>>tmp[1]>>tmp[2]>>tmp[3];
  //    cout<<"HOO"<<endl;
      v.push_back(tmp);
    }
    if(e=='*'){
      double x,y;
      int cnt=0;
      while(cin>>x>>y)
      {
        if(x==9999.9&&y==9999.9){
          break;
        }
        cnt++;
        int sz=v.size();
        bool is=0;
        for(int i=0;i<sz;i++){
          vector<double> tmp=v[i];
          if(tmp.size()==3){
            //circle
            if(dist(x,y,tmp[0],tmp[1])<tmp[2]){
              is=1;
              cout<<"Point "<<cnt<<" is contained in figure "<<i+1<<endl;
            }
          }
          else{
            double ulx=tmp[0],uly=tmp[1],lrx=tmp[2],lry=tmp[3];

            if(x>ulx&&x<lrx&&y>lry&&y<uly){
              is=1;
              cout<<"Point "<<cnt<<" is contained in figure "<<i+1<<endl;
            }
          }
        }
        if(!is){
          cout<<"Point "<<cnt<<" is not contained in any figure"<<endl;
        }
      }
      break;
    }
  }
}
