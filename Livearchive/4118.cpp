#include<bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define iii pair<int,ii>
#define X first
#define Y second.first
#define Z second.second
int fx,fy,fz,tx,ty,tz;
iii tstate;
bool isOccupied[200][200][200];

vector<int> d[]= {{1,0,3},{1,0,-3},{1,3,0},{1,-3,0},{2,0,2},{2,0,-2},{2,2,0},{2,-2,0}};
//OK till now
//the first is the current one
int mark(int x){
    return x/abs(x);
}
void addStep(int &x,int &y,int &z,iii state){
    x+=state.X;
    y+=state.Y;
    z+=state.Z;
}
int ix,iy,iz;
int f(int cnt,int x,int y,int z,iii state)
{
    //cout<<state.X<<" "<<state.Y<<" "<<state.Z<<endl;
    //cout<<cnt<<" "<<x<<" "<<y<<" "<<z<<endl;
    if(cnt==7)
        return 1e9;
    if(x==tx&&y==ty&&z==tz&&state==tstate) {
        return 0;
    }
    if(x<1||y<1||z<1||x>fx||y>fy||z>fz)
        return 1e9;
    //the one which is controlled by state should be the first
    //now what to do :/

    int idx=0,idy=0,idz=0;

    if(state.X) {
        idy=1;
        idz=2;
    }
    if(state.Y) {
        idx=2;
        idz=1;
    }
    if(state.Z) {
        idx=2;
        idy=1;
    }
    int ret=1e9;
    iii nextState;
    for(int i=0;i<8;i++){
       // cout<<"sharabova"<<endl;
        int nx,ny,nz;
        iii nstate={0,{0,0}};
        if(idx==0){
         //   cout<<"dodo"<<endl;
            nx=x+state.X*d[i][idx];
            ny=y+d[i][idy];
            nz=z+d[i][idz];
            if(d[i][idy]!=0)
                nstate.Y=mark(d[i][idy]);
            else
                nstate.Z=mark(d[i][idz]);
        }
        if(idy==0){
           // cout<<"dodo"<<endl;
            ny=y+state.Y*d[i][idy];
            nx=x+d[i][idx];
            nz=z+d[i][idz];
          //  cout<<"fofo"<<endl;
          //  cout<<i<<" "<<idx<<" "<<idz<<" "<<d[i][idx]<<" "<<d[i][idz]<<endl;
            if(d[i][idx]!=0)
                nstate.X=mark(d[i][idx]);
            else
                nstate.Z=mark(d[i][idz]);
        }
        if(idz==0){
            nz=z+state.Z*d[i][idz];
            nx=x+d[i][idx];
            ny=y+d[i][idy];
            if(d[i][idy]!=0)
                nstate.Y=mark(d[i][idy]);
            else
                nstate.X=mark(d[i][idx]);
        }
        int curx=x,cury=y,curz=z;
        vector<iii> tmp;
        tmp.push_back({x,{y,z}});
        bool ff=1;
        for(int j=0;j<d[i][0];j++){
            addStep(curx,cury,curz,state);
            if(curx>=0&&cury>=0&&curz>=0&&!isOccupied[curx][cury][curz]){
                tmp.push_back({curx,{cury,curz}});
            }
            else{
                ff=0;
                break;
            }
        }
        for(int j=0;j<d[i][1]+d[i][2];j++){
            addStep(curx,cury,curz,nstate);
            if(curx>=0&&cury>=0&&curz>=0&&!isOccupied[curx][cury][curz]){
                tmp.push_back({curx,{cury,curz}});
            }
            else{
                ff=0;
                break;
            }
        }
        if(!ff)
            continue;

        for(auto foo:tmp){
            isOccupied[foo.X][foo.Y][foo.Z]=1;
        }
        ret=min(ret,1+f(cnt+1,nx,ny,nz,nstate));
        for(auto foo:tmp){
            isOccupied[foo.X][foo.Y][foo.Z]=0;
        }
    }
    return ret;
}



iii getState(string s)
{
    int mult=1;
    if(s[0]=='-')
        mult=-1;
    if(s[1]=='x')
        return iii(mult,ii(0,0));
    if(s[1]=='y')
        return iii(0,ii(mult,0));
    return iii(0,ii(0,mult));
}




void extendOne(int &x,string state)
{
    if(state[0]=='+') {
        x++;
    } else
        x--;
}
#define endl '\n'
main()
{
    ios_base::sync_with_stdio(false);

    iii istate;
    string is,ts;
    for(int c=1;; c++) {
        cin>>fx;
        if(fx==0)
            break;
        cout<<"Case "<<c<<": ";
        cin>>fy>>fz>>ix>>iy>>iz>>is>>tx>>ty>>tz>>ts;



        for(int i=0; i<=fx+10; i++)
            for(int j=0; j<=fy+10; j++)
                for(int k=0; k<=fz+10; k++)
                    isOccupied[i][j][k]=0;
        istate=getState(is);
        tstate=getState(ts);
        if(tstate.X) {
            extendOne(tx,ts);
        }
        if(tstate.Y)
            extendOne(ty,ts);
        if(tstate.Z)
            extendOne(tz,ts);
        //cout<<tx<<" "<<ty<<" "<<tz<<endl;
        int ans=f(0,ix,iy,iz,istate);
        if(ans!=1e9) {
            cout<<ans<<endl;
        } else {
            cout<<"Impossible"<<endl;
        }
    }
}
