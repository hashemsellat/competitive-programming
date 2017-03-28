/*
  the answer should be 1-an odd number 2-it has an odd number of divisors
  to satisfy the first condition number 2 should not be a divisor of the final answer
  any integer can be represented as (x1^k1 * x2^k2 * .. xm^km) where (x1..xm) are primes and
We know that the number of divisors of any integer is (k+1)*(k1+1)*..*(km+1) so we just need to factorize n.
  but wait  n is less or equal 10^18 and the trivial factorization works in O(sqrt(n)) so we shouldn't use it here.
  lets find the prime factors of n from (3 to 1000000 or (n^(1/3))), and lets divide n by these prime divisors.
we get n=A*B; where A is(x1^k1 * x2^k2 * xm^km) and  xi is a prime number less than 1000000
  now B has three possible states
    either it's a prime (so we dont take it since the number of divisors will be even then)
    or it's a multiple of two distinct primes (we also dont take it because of the previous reason)
    or it's equal to y^2 where y is a prime so we take it and add it to the answer
*/
#include<bits/stdc++.h>
#define ii pair<int,int>
#define iii pair<ii,int>
using namespace std;
#define int long long int
int pow(int a,int b){
  if(b==0)  return 1;
  if(b%2==1){
    return a*pow(a,b-1);
  }
  int tmp=pow(a,b/2);
  return tmp*tmp;
}
main(){

  int n;
  while(cin>>n){
    int ans=1;
    for(int i=3;i*i*i<=n;i++){
      if(n%i==0){
        int cnt=0;
        while(n%i==0){
          cnt++;
          n/=i;
        }
        if(cnt%2) cnt--;
        ans*=pow(i,cnt);
      }
    }
    int sq=(sqrt(n)+0.1);
    if(sq*sq==n){
      ans*=pow(sq,2);
    }
    cout<<ans<<endl;
  }
}
