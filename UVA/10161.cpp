/*
    lets see if the elements of the main diagonal can be generated, every one can be obtained by adding
2*it's position (starting at zero from the bottom left to the top right) to the previous element.

    now we keep generating the elements of the main diagonal one by one until we reach an element md so that n lies in the interval [md-i,md+i] where i is the current index .. now there are two cases
        -the index of the element is odd then there are also two cases
            -n>=md  so the row number is i-(n-md) and the column number is i
            -n<md   so the row number is i and the column number is i-(md-n)
        -the index of the element is even then we reverse the previous steps..


*/
#include<bits/stdc++.h>
#define ii pair<int,int>
#define iii pair<ii,int>
#define endl '\n'
#define int long long int
using namespace std;
main()
{
    int n;
    while(cin>>n)
    {
        if(n==0)
            break;
        int i=1;
        int md=1,cur=0;
        while(1)
        {
            if(i%2)
            {
                if(n<=md+cur&&n>=md)
                {
                    cout<<i-(n-md)<<" "<<i<<endl;
                    break;
                }
                if(n<=md&&n>=md-cur)
                {
                    cout<<i<<" "<<i-(md-n)<<endl;
                    break;
                }
            }
            else
            {
                if(n<=md+cur&&n>=md)
                {
                    cout<<i<<" "<<i-(n-md)<<endl;
                    break;
                }
                if(n<=md&&n>=md-cur)
                {
                    cout<<i-(md-n)<<" "<<i<<endl;
                    break;
                }
            }
            md=md+(cur+1)*2;
            cur++;
            i++;
        }
    }
}
