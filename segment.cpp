#include<bits/stdc++.h>
 
#define lol long long

using namespace std;
/*
  Segment<x>(n,fx,ex): モノイド(集合X,二項演算fx,単位元ex)についてサイズnで構築
  set(int i,X x),build(): i番目の要素をxにセット。まとめてセグ木を構築する0(n)
  update(i,x): i番目の要素をxに更新。O(log(n))
  get(a,b): [a,b] 全てにfxを作用させた値を取得。O(log(n))
  operator[k] := k番目の要素を返す。
  find_rightest : [a,b) で x以下の要素を持つ最右位置はどこか
  find_leftest : [a,b) で x以下の要素を持つ最左位置はどこか
  */
template <typename X>
struct Segment{
  using FX=function<X(X,X)>; //X●X -> X となる関数の型
  int n;
  FX fx;
  const X ex;
  vector<X> dat;
  Segment(int size,FX fx_,X ex_) : fx(fx_),ex(ex_){
    n=1;
    while(size>n){
      n*=2;
    }
    dat.resize(n*2,ex_);
    return;
  }
  
  void set(int i,X x){ dat[i+n-1]=x;}
  void build(){
    for(int k=n-2;k>=0;k--) dat[k]=fx(dat[2*k+1],dat[2*k+2]);
    return;
  }
  
  void update(int i,X x){
    i+=n-1;
    dat[i]=x;
    while(i>0){
      i=(i-1)/2;
      dat[i]=fx(dat[i*2+1],dat[i*2+2]);
    }      
    return;  
  }
  
  X get(int a,int b){ return (get_sub(a,b+1,0,0,n));}
  X get_sub(int a,int b,int k,int l,int r){
    if(r<=a || b<=l) return ex;
    if(a<=l && r<=b) return dat[k];
    X vl=get_sub(a,b,k*2+1,l,(l+r)/2);
    X vr=get_sub(a,b,k*2+2,(l+r)/2,r);
    return fx(vl,vr);
  }
  
  X operator[](const int &k) const{
    return dat[k+n-1];
  }
  
    X find_rightest(int a, int b, X x) { return find_rightest_sub(a, b, x, 0, 0, n); }
    X find_leftest(int a, int b, X x) { return find_leftest_sub(a, b, x, 0, 0, n); }
    X find_rightest_sub(int a, int b, X x, int k, int l, int r) {
        if (dat[k] > x || r <= a || b <= l) {  // 自分の値がxより大きい or [a,b)が[l,r)の範囲外
            return a - 1;
        } else if (k >= n - 1) {  // 自分が葉ならその位置をreturn
            return (k - (n - 1));
        } else {
            int vr = find_rightest_sub(a, b, x, 2 * k + 2, (l + r) / 2, r);
            if (vr != a - 1) {  // 右の部分木を見て a-1 以外ならreturn
                return vr;
            } else {  // 左の部分木を見て値をreturn
                return find_rightest_sub(a, b, x, 2 * k + 1, l, (l + r) / 2);
            }
        }
    }
    X find_leftest_sub(int a, int b, X x, int k, int l, int r) {
        if (dat[k] > x || r <= a || b <= l) {  // 自分の値がxより大きい or [a,b)が[l,r)の範囲外
            return b;
        } else if (k >= n - 1) {  // 自分が葉ならその位置をreturn
            return (k - (n - 1));
        } else {
            int vl = find_leftest_sub(a, b, x, 2 * k + 1, l, (l + r) / 2);
            if (vl != b) {  // 左の部分木を見て b 以外ならreturn
                return vl;
            } else {  // 右の部分木を見て値をreturn
                return find_leftest_sub(a, b, x, 2 * k + 2, (l + r) / 2, r);
            }
        }
    }
};
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  auto fx1=[](int x1,int x2) -> int {return min(x1,x2);};
  auto fx2=[](int x1,int x2) -> int {return max(x1,x2);};
  auto fx3=[](int x1,int x2) -> int {return x1+x2;};
  int n,m;
  cin >>n>>m;
  Segment<int> minst(n,fx1,(1LL<<31)-1);
  Segment<int> maxst(n,fx2,-(1LL<<31)+1);
  Segment<int> sumst(n,fx3,0);
  for(int i=0;i<n;i++){
    minst.update(i,0);
    maxst.update(i,0);
    sumst.update(i,0);
  }
  for(int i=0;i<m;i++){
    string s;
    int a,b;
    cin >>s>>a>>b;
    if(s=="update"){
      minst.update(a,b);
      maxst.update(a,b);
      sumst.update(a,b);
    }else if(s=="add"){
      minst.update(a,minst[a]+b);
      maxst.update(a,maxst[a]+b);
      sumst.update(a,sumst[a]+b);
    }else if(s=="getMin") cout <<minst.get(a,b-1)<<'\n';
    else if(s=="getMax") cout <<maxst.get(a,b-1)<<'\n';
    else if(s=="getSum") cout <<sumst.get(a,b-1)<<'\n';
  }
  return (0);
}