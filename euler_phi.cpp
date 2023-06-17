#include<bits/stdc++.h>
 
#define lol long long
#define gcd(x,y) __gcd(x,y)
#define mt make_tuple
#define mp make_pair
#define fi first
#define se second
#define fixed(x) fixed<<setprecision(x)
using namespace std;
template <class A, class B> inline bool chmax(A &a, const B &b) { return b > a && (a = b, true); }
template <class A, class B> inline bool chmin(A &a, const B &b) { return b < a && (a = b, true); }
template <class A> inline lol abs(A &a) { return (a < 0 ? -a : a); }
bool inLine(int x,int y,int mx,int my){return (x>=0&&y>=0&&x<mx&&y<my);}
const lol inf=(1LL<<62);
const int MOD=(1e9)+7;
const int mod=998244353;
const int dx[]={1,0,-1,0,1,1,-1,-1};
const int dy[]={0,1,0,-1,1,-1,1,-1};
lol euler_phi(lol n){
  lol ret=n;
  for(lol i=2;i*i<=n;i++){
    if(n%i==0){
      ret -= ret/i;
      while(n%i == 0) n/=i;
    }
  }
  if(n>1) ret-=ret/n;
  return ret;
}
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  lol n;
  cin >>n;
  cout <<euler_phi(n)<<'\n';
  /*N以下の整数でNと互いに素な数*/
  return (0);
}