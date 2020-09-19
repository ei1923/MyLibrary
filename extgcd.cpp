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
lol extgcd(lol a,lol b,lol &x,lol &y){
  if(b==0){
    x=1;
    y=0;
    return a;
  }
  lol gcd=extgcd(b,a%b,x,y);
  lol oldX=x;
  x=y;
  y=oldX - a/b*y;
  return gcd;
}
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  lol a,b;
  cin >>a>>b;
  lol x,y;
  /* 与えられた２つの整数 a、b について
  ax+by=gcd(a,b) の整数解 (x,y) を求めてください。
  ここで、gcd(a,b) は a と b の最大公約数です。
  拡張ユークリッド
  */
  extgcd(a,b,x,y);
  cout <<x<<' '<<y<<'\n';

  return (0);
}