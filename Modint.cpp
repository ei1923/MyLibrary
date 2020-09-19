#include<bits/stdc++.h>
#define lol long long
using namespace std;

class Modint{
  public:
  lol x;
  Modint():x(0){}
  Modint(lol y):x(y>=0?y%mod():y%mod()+mod()){}
  
  static lol &mod(){
    static lol mod=inf;
    return mod;
  }
  void set(lol y){
    mod()=y;
    return;
  }
  Modint &operator+=(const Modint &p){
    if((x+=p.x)>=mod()) x-=mod();
    return *this;
  }
  Modint &operator-=(const Modint &p){
    if((x-=p.x)<0) x+=mod();
    return *this;
  }
  Modint &operator*=(const Modint &p){
    x=(lol)x*(p.x%mod())%mod();
    return *this;
    /*
    unsigned lol a=(unsigned lol)x*p.x;
    unsigned xh = (unsigned) (a >> 32);
    unsigned xl = (unsigned) a;
    unsigned d, m;
    asm("divl %4; \n\t" : "=a" (d), "=d" (m) : "d" (xh), "a" (xl), "r" (mod()));
    x = m;
    return *this;
    */
  }
  Modint &operator/=(const Modint &p){
    *this *= p.inverse();
    return *this;
  }
  Modint operator-() const{return(Modint(-x));}
  Modint operator+(const Modint &p)const{return(Modint(*this)+=p);}
  Modint operator-(const Modint &p)const{return(Modint(*this)-=p);}
  Modint operator*(const Modint &p)const{return(Modint(*this)*=p);}
  Modint operator/(const Modint &p)const{return(Modint(*this)/=p);}

  bool operator==(const Modint &p)const{return(x==p.x);}
  bool operator!=(const Modint &p)const{return(x!=p.x);}
  
  Modint inverse()const{
    lol a,b,u,v,t;
    a=x,b=mod(),u=1,v=0;
    while(b>0){
      t=a/b;
      swap(a-=t*b,b);
      swap(u-=t*v,v);
    }
    return Modint(u);
  }

  Modint pow(lol n)const{
    Modint ret(1),mul(x);
    while(n>0){
      if(n&1) ret*=mul;
      mul*=mul;
      n>>=1;
    }
    return ret;
  }
};
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >>n;
  Modint ans;
  ans.set(998244353);
  while(n--){
    char o;
    lol a;
    cin >>o>>a;
    if(o=='+') ans+=a;
    else if(o=='-') ans-=a;
    else ans*=a;
  }
  cout <<ans.x<<'\n';
  return (0);
}