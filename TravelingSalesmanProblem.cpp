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
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  // 巡回セールスマン問題
  int v,e;
  cin >>v>>e;
  vector<vector<pii> > lis(v+2);
  for(int i=0;i<e;i++){
    int s,t,d;
    cin >>s>>t>>d;
    lis[s].emplace_back(t,d);
  }
  // dp[n][m][p] nの頂点を回っていて、出発点m,現在pの最低コスト
  vector<vector<vector<lol>>> dp(1<<v,vector<vector<lol>>(v,vector<lol>(v,inf)));
  for(int i=0;i<v;i++) dp[0][i][i]=0;

    for(int bit=0;bit<(1<<v);bit++){
      for(int i=0;i<v;i++){
        for(int j=0;j<lis[i].size();j++){
          for(int q=0;q<v;q++){
            if(!(bit&(1<<lis[i][j].fi))) chmin(dp[bit|(1<<lis[i][j].fi)][lis[i][j].fi][q],dp[bit][i][q]+lis[i][j].se);
          }
        }
      }
    }

  lol ans=inf;
  for(int i=0;i<v;i++){
    chmin(ans,dp[(1<<v)-1][i][i]);
  }
  cout <<(ans>=inf?-1:ans)<<'\n';
  return (0);
}