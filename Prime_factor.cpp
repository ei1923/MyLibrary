#include <bits/stdc++.h>
#define lol long long
#define fixed(x) fixed<<setprecioson
#define fi first
#define se second
using namespace std;
std::vector<int> sieve(int n) {
  std::vector<int> res(n);
  std::iota(res.begin(), res.end(), 0);
  for (int i = 2; i*i < n; ++i) {
    if (res[i] < i) continue;
    for (int j = i*i; j < n; j += i)
      if (res[j] == j) res[j] = i;
  }
  return res;
}
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;cin >>n;
  vector<int> ans(n+1,0);
  auto tmp=sieve(n+1);
  for(int i=2;i<=n;i++){
    int p=i;
    while(p!=1){
      ans[tmp[p]]++;
      p/=tmp[p];
    }
  }
  for(int i=2;i<=n;i++){
    if(ans[i]) cout <<i<<' '<<ans[i]<<'\n';
  }
  return (0);
}