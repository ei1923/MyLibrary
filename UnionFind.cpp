//うどん狂とタマネギ発見
#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
  vector < int > par;
  vector < int > siz;
  
  UnionFind(int n): par(n), siz(n, 1) {
    for(int i = 0; i < n; i++) par[i] = i;
  }
  int root(int x){
    if(par[x] == x) return x;
    else return par[x] = root(par[x]);
  }
  int size(int x){ return siz[root(x)];}
  bool same(int x, int y){ return root(x) == root(y); }//判定
  bool unite(int x, int y){//連結
    if((x=root(x))==(y=root(y))) return false;
    if( siz[y] > siz[x] ) swap(x,y);
    siz[x] += siz[y];
    par[y] = x;
    return true;
  }
};


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >>n;
  UnionFind uf(n);
  int a,b,c,d;
  cin >>a;
  for(int i=0;i<a;i++){
      cin >>n>>c>>d;
      if(n==0) uf.unite(c,d);
      else{
	  if(uf.same(c,d)) cout <<"Same\n";
	  else cout <<"Different\n";
      }
  }
  return 0;
}
