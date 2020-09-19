#include<bits/stdc++.h>
 
#define lol long long
#define gcd(x,y) __gcd(x,y)
#define mt make_tuple
#define mp make_pair
#define fi first
#define se second
#define fixed(x) fixed<<setprecision(x)
using namespace std;
using pii=pair<int,int>;
template <class A, class B> inline bool chmax(A &a, const B &b) { return b > a && (a = b, true); }
template <class A, class B> inline bool chmin(A &a, const B &b) { return b < a && (a = b, true); }
template <class A> inline lol abs(A &a) { return (a < 0 ? -a : a); }
bool inLine(int x,int y,int mx,int my){return (x>=0&&y>=0&&x<mx&&y<my);}
const lol inf=(1LL<<62);
const int MOD=(1e9)+7;
const int mod=998244353;
const int dx[]={1,0,-1,0,1,1,-1,-1};
const int dy[]={0,1,0,-1,1,-1,1,-1};
using namespace std;
struct Dice{
  vector<int> masu;
  Dice(){}
  Dice(vector<int> a):masu(a){}
  Dice operator=(Dice p){masu=p.masu;return(p);}

  int top(){
    return masu[1];
  }
  void rota(char E){
    if(E=='N'){
      int tmp=masu[1];
      masu[1]=masu[2];
      masu[2]=masu[6];
      masu[6]=masu[5];
      masu[5]=tmp;
    }else if(E=='S'){
      int tmp=masu[1];
      masu[1]=masu[5];
      masu[5]=masu[6];
      masu[6]=masu[2];
      masu[2]=tmp;
    }else if(E=='W'){
      int tmp=masu[1];
      masu[1]=masu[3];
      masu[3]=masu[6];
      masu[6]=masu[4];
      masu[4]=tmp;
    }else if(E=='E'){
      int tmp=masu[1];
      masu[1]=masu[4];
      masu[4]=masu[6];
      masu[6]=masu[3];
      masu[3]=tmp;
    }
    return;
  }
  int rigt(int a,int b){
    int ans=-1;
    if(a==masu[1]){
      if(b==masu[2]) ans=masu[3];
      if(b==masu[4]) ans=masu[2];
      if(b==masu[3]) ans=masu[5];
      if(b==masu[5]) ans=masu[4];
    }else if(a==masu[2]){
      if(b==masu[1]) ans=masu[4];
      if(b==masu[4]) ans=masu[6];
      if(b==masu[6]) ans=masu[3];
      if(b==masu[3]) ans=masu[1];
    }else if(a==masu[3]){
      if(b==masu[1]) ans=masu[2];
      if(b==masu[2]) ans=masu[6];
      if(b==masu[6]) ans=masu[5];
      if(b==masu[5]) ans=masu[1];
    }else if(a==masu[4]){
      if(b==masu[1]) ans=masu[5];
      if(b==masu[5]) ans=masu[6];
      if(b==masu[6]) ans=masu[2];
      if(b==masu[2]) ans=masu[1];
    }else if(a==masu[4]){
      if(b==masu[2]) ans=masu[1];
      if(b==masu[1]) ans=masu[5];
      if(b==masu[5]) ans=masu[6];
      if(b==masu[6]) ans=masu[2];
    }else if(a==masu[5]){
      if(b==masu[3]) ans=masu[6];
      if(b==masu[6]) ans=masu[4];
      if(b==masu[4]) ans=masu[1];
      if(b==masu[1]) ans=masu[3];
    }else if(a==masu[6]){
      if(b==masu[2]) ans=masu[4];
      if(b==masu[4]) ans=masu[5];
      if(b==masu[5]) ans=masu[3];
      if(b==masu[3]) ans=masu[2];
    }
    return ans;
  }
  void spen(int n){
    // 1で右回転,2で左回転
    if(n==1){
      int tmp=masu[2];
      masu[2]=masu[3];
      masu[3]=masu[5];
      masu[5]=masu[4];
      masu[4]=tmp;
    }else if(n==2){
      int tmp=masu[2];
      masu[2]=masu[4];
      masu[4]=masu[5];
      masu[5]=masu[3];
      masu[3]=tmp;
    }
    return;
  }
  bool same_sub(Dice p){
    for(int j=0;j<4;j++){
      bool ans=true;
      for(int i=1;i<=6;i++){
        if(masu[i]!=p.masu[i]) ans=false;
      }
      if(ans) return true;
      p.spen(1);
    }
    return false;
  }
};
bool same(Dice e,Dice p){
    bool ans=false;
    Dice d(p.masu);
    ans|=e.same_sub(d);
    for(int i=0;i<3;i++){
      d.rota('S');
      ans|=e.same_sub(d);
    }
    d.rota('W');
    ans|=e.same_sub(d);
    d.rota('W');
    d.rota('W');
    ans|=e.same_sub(d);
    return ans;
  }
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >>n;
  vector<Dice> d(n);
  for(int i=0;i<n;i++){
    vector<int> a(7);
    for(int j=1;j<=6;j++) cin >>a[j];
    d[i]=a;
  }
  for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
      if(same(d[i],d[j])){
        cout <<"No\n";
        return 0;
      }
    }
  }
  cout <<"Yes\n";
  return (0);
}