#include <bits/stdc++.h>
using namespace std;
#define lol long long
#define fixed(x) fixed<<setprecision(x)
#define fi first
#define se second
#define EPS (1e-10)
#define eq(a,b) (fabs((a) - (b)) < EPS)
#define COUNTER_CLOCKWISE 1
#define CLOCKWISE -1
#define ONLINE_BACK 2
#define ONLINE_FRONT -2
#define ON_SEGMENT 0
#define double long double

class Point{
  public:
  double x,y;

  Point(double x=0.0, double y=0.0):x(x),y(y){}

  Point operator + (const Point& p) const{return Point(x+p.x, y+p.y);}
  Point operator - (const Point& p) const{return Point(x-p.x,y-p.y);}
  Point operator * (double a) const{return Point(a*x,a*y);}
  Point operator * (const Point& p) const{return Point(x*p.x-y*p.y,x*p.y+y*p.x);}
  Point operator / (double a) const{return Point(x/a,y/a);}

  double abs(){return sqrt(norm());}
  double norm(){return x*x+y*y;}

  bool operator < (const Point &p) const{
    return (eq(x,p.x) ? y < p.y : x < p.x);
  }
  bool operator > (const Point &p) const{
    return (eq(x,p.x) ? y > p.y : x > p.x);
  }

  bool operator == (const Point &p) const{
    return (eq(x,p.x) && eq(y,p.y));
  }
  
  friend istream &operator>>(istream &stream,Point &v){
    double a,b;
    stream>>a>>b;
    v.x=a,v.y=b;
    return stream;
  }

  friend ostream &operator<<(ostream &stream,const Point &v){
    stream<<v.x<<' '<<v.y;
    return stream;
  }
};
// ベクトルを表す
typedef Point Vector;
// 線分を表す
struct Segment{
  Point p1,p2;
  Segment(Point p1=Point(),Point p2=Point()):p1(p1),p2(p2){}
  bool operator==(const Segment s)const{
    return (p1==s.p1) && (p2==s.p2);
  }
  bool operator!=(const Segment s)const{
    return !(*this==s);
  }
};
// 直線を表す
typedef Segment Line;
// 円を表す
class Circle{
  public:
  Point p;
  double r;
  Circle(Point c=Point(), double r=0.0): p(c),r(r){}
  bool operator==(const Circle c)const{
    return (eq(r,c.r)&&(p==c.p));
  }
  bool operator!=(const Circle c)const{
    return !(*this==c);
  }
};
// 多角形を表す
typedef vector<Point> Polygon;
// 複数の線を表す
typedef vector<Line> Lines;
const double PI=acos(-1);

// ベクトルaとbの内積
double dot(const Point& a, const Point& b);
// ベクトルaとbの外積
double cross(const Point& a, const Point& b);
// ベクトルの角度
double arg(const Vector& p);
// 極座標を直交座標に
Vector polar(double a, double r);
// ベクトルaとbの直交判定
bool isOrthogonal(const Vector& a, const Vector& b);
bool isOrthogonal(const Point& a1, const Point& a2, const Point& b1, const Point& b2);
bool isOrthogonal(const Segment& s1, const Segment& s2);
// ベクトルaとbの平行判定
bool isParallel(const Vector& a, const Vector& b);
bool isParallel(const Point& a1, const Point& a2, const Point& b1, const Point& b2);
bool isParallel(const Segment& s1, const Segment& s2);
// 線分sに対する点pの射影
Point projection(const Segment& s, const Point& p);
// 線分sを軸とした点pの線対称の点
Point reflect(const Segment& s, const Point& p);
// 点aと点bの距離
double getDistancePP(const Point& a, const Point& b);
// 直線lと点pの距離
double getDistaneceLP(const Line& l, const Point& p);
// 線分sと点pの距離
double getDistaneceSP(const Segment& s, const Point& p);
// 座標p0からp1を見た時、p2がどの位置にあるか
int ccw(const Point& p0, const Point& p1, const Point& p2);
int ccw(const Segment& s,const Point& p);
// 線分(p1,p2)と線分(p3,p4)の交差判定
bool intersect(const Point& p1, const Point& p2, const Point& p3, const Point& p4);
bool intersect(const Segment& s1, const Segment& s2);
// 線分s1と線分s2の交点を求める
Point getCrossPoint(const Point& p1, const Point& p2, const Point& p3, const Point& p4);
Point getCrossPoint(const Segment& s1, const Segment& s2);
// 線分s1と線分s2の距離
double getDistanece(const Point& p1, const Point& p2, const Point& p3, const Point& p4);
double getDistanece(const Segment& s1, const Segment& s2);
// 円cと線分lの交点
pair<Point,Point> getCrossPoints(const Circle& c, const Point& p1, const Point& p2);
pair<Point,Point> getCrossPoints(const Circle& c, const Segment& l);
// 円c1と円c2の交点
pair<Point,Point> getCrossPoints(const Circle& c1, const Circle& c2);
//点の内包・・・内側:2・線上:1・外側:0
int contains(const Polygon& g, const Point& p);
// 多角形の面積
double getArea(const Polygon& g);
// 凸性判定
bool Convexity(const Polygon& g);
// 凸包
Polygon andrewScan(const Polygon& tmp);
// 凸多角形の直径
double PolyDiam(const Polygon& g);
// 最近点対 最も近い２点の距離
double ClosetPair(Polygon& ps);
// 凸多角形の切断
Polygon PolyCut(const Polygon &p,const Point& p1,const Point& p2);
Polygon PolyCut(const Polygon &p,const Line& l);
// 円の交差判定
int intersect(Circle& c1, Circle& c2);
// 点pを通る円の接線
pair<Point,Point> tangent(const Circle& c,const Point& p);
// 点pを反時計回りに回転
Point rotate(double theta, const Point& p);
// 二つの円の共通接線
Lines tangent(Circle c1, Circle c2);
// (0,0)と点x,yの図形の面積(三角形と扇形(半径r))
double calc_element(const Point& x,const Point& y,double r,bool triangle);
// 多角形と円の共通面積
double area(const Polygon &p, const Circle &c);
// 円と円の共通面積
double area(const Circle& c1, const Circle& c2);
// 三角形の内接円
Circle Inscribed(const Point& a, const Point& b, const Point& c);
// 三角形の外接円の座標
Circle Circum(const Point& a, const Point& b, const Point& c);
// 円と点の内外判定
bool included(const Circle& c,const Point p){
  double dis=(c.p-p).norm();
  if(c.r*c.r>=dis) return true;
  return false;
}

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  return (0);
}

// ベクトルaとbの内積
double dot(const Point& a, const Point& b){
  return (a.x*b.x + a.y*b.y);
}
// ベクトルaとbの外積
double cross(const Point& a, const Point& b){
  return (a.x*b.y - a.y*b.x);
}
// ベクトルの角度
double arg(const Vector& p){return(atan2(p.y,p.x));}
// 極座標を直交座標に
Vector polar(double a, double r){return(Point(cos(r)*a,sin(r)*a));}
// ベクトルaとbの直交判定
bool isOrthogonal(const Vector& a, const Vector& b){
  return eq(dot(a,b),0.0);
}
bool isOrthogonal(const Point& a1, const Point& a2, const Point& b1, const Point& b2){
  return (isOrthogonal(a1 - a2, b1 - b2));
}
bool isOrthogonal(const Segment& s1, const Segment& s2){
  return (eq(dot(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0));
}
// ベクトルaとbの平行判定
bool isParallel(const Vector& a, const Vector& b){
  return eq(cross(a,b),0.0);
}
bool isParallel(const Point& a1, const Point& a2, const Point& b1, const Point& b2){
  return (isParallel(a1 - a2, b1 - b2));
}
bool isParallel(const Segment& s1, const Segment& s2){
  return (eq(cross(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0));
}
// 線分sに対する点pの射影
Point projection(const Segment& s, const Point& p){
  Vector base = s.p2 - s.p1;
  double r = dot(p - s.p1, base)/(base.norm());
  return (s.p1 + base*r);
}
// 線分sを軸とした点pの線対称の点
Point reflect(const Segment& s, const Point& p){
  return (p + (projection(s,p) - p) *2.0);
}
// 点aと点bの距離
double getDistancePP(const Point& a, const Point& b){
  return (a-b).abs();
}
// 直線lと点pの距離
double getDistaneceLP(const Line& l, const Point& p){
  return fabs(cross(l.p2-l.p1,p-l.p1)/((l.p2-l.p1).abs()));
}
// 線分sと点pの距離
double getDistaneceSP(const Segment& s, const Point& p){
  if(dot(s.p2-s.p1,p-s.p1)<0.0) return (p-s.p1).abs();
  if(dot(s.p1-s.p2,p-s.p2)<0.0) return (p-s.p2).abs();
  return getDistaneceLP(s, p);
}
// 座標p0からp1を見た時、p2がどの位置にあるか
int ccw(const Point& p0, const Point& p1, const Point& p2){
  Point a = p1 - p0;
  Point b = p2 - p0;
  // 反時計回り
  if(cross(a,b) > EPS) return 1;
  // 時計回り
  if(cross(a,b) < -EPS) return -1;
  // 直線(p0,p1)上にあり、p2,p0,p1と並んでいる
  if(dot(a,b) < -EPS) return 2;
  // 直線(p0,p1)上にあり、p0,p1,p2と並んでいる
  if(a.norm() < b.norm()) return -2;
  // 線分(p0,p1)上にp2がある
  return 0;
}
int ccw(const Segment& s,const Point& p){
  return ccw(s.p1, s.p2, p);
}
// 線分(p1,p2)と線分(p3,p4)の交差判定
bool intersect(const Point& p1, const Point& p2, const Point& p3, const Point& p4){
  return ((ccw(p1, p2, p3)*ccw(p1, p2, p4) <= 0) &&
          (ccw(p3, p4, p1)*ccw(p3, p4, p2) <= 0));
}
bool intersect(const Segment& s1, const Segment& s2){return (intersect(s1.p1,s1.p2,s2.p1,s2.p2));}
// 線分s1と線分s2の交点を求める
Point getCrossPoint(const Point& p1, const Point& p2, const Point& p3, const Point& p4){
  return getCrossPoint(Segment(p1,p2),Segment(p3,p4));
}
Point getCrossPoint(const Segment& s1, const Segment& s2){
  double A = cross(s1.p2-s1.p1, s2.p2-s2.p1);
  double B = cross(s1.p2-s1.p1, s1.p2-s2.p1);
  if(eq(fabs(A),0.0)&&eq(fabs(B),0.0)) return s2.p1;
  return s2.p1+(s2.p2-s2.p1)*B/A;
}
// 線分s1と線分s2の距離
double getDistanece(const Point& p1, const Point& p2, const Point& p3, const Point& p4){
  return getDistanece(Segment(p1,p2),Segment(p3,p4));
}
double getDistanece(const Segment& s1, const Segment& s2){
  if( intersect(s1, s2) ) return (0.0);
  return min(min(getDistaneceSP(s1, s2.p1),getDistaneceSP(s1, s2.p2)),
             min(getDistaneceSP(s2, s1.p1), getDistaneceSP(s2, s1.p2)));

}
// 円cと線分lの交点
pair<Point,Point> getCrossPoints(const Circle& c, const Point& p1, const Point& p2){
  return getCrossPoints(c,Segment(p1,p2));
}
pair<Point,Point> getCrossPoints(const Circle& c, const Segment& l){
  //assert(intersect(c,l));
  Point pr = projection(l, c.p);
  Point e = (l.p2 - l.p1) / ((l.p2 - l.p1).abs());
  if(eq(getDistaneceSP(l,c.p), c.r)) return {pr,pr};
  double base = sqrt(c.r*c.r - ((pr-c.p).norm()));
  return {pr - (e*base), pr + (e*base)};
}
// 円c1と円c2の交点
pair<Point,Point> getCrossPoints(const Circle& c1, const Circle& c2){
  //assert(intersect(c1,c2));
  double d = (c1.p - c2.p).abs();
  double a = acos((c1.r*c1.r + d*d - c2.r*c2.r) / (2*c1.r*d));
  double t = arg(c2.p - c1.p);
  return make_pair(c1.p + polar(c1.r, t+a), c1.p + polar(c1.r, t-a));
}
//点の内包・・・内側:2・線上:1・外側:0
int contains(const Polygon& g, const Point& p){
  int n = g.size();
  bool x = false;
  for(int i=0;i<n;i++){
    Point a = g[i] - p;
    Point b = g[(i+1)%n] - p;
    if(fabs(cross(a, b)) < EPS && dot(a, b) < EPS) return (1);
    if(a.y > b.y) swap(a,b);
    if(a.y < EPS && EPS < b.y && cross(a,b) > EPS) x = !x;
  }
  return (x ? 2 : 0);
}
// 多角形の面積
double getArea(const Polygon& g){
  int n = g.size();
  if(n<=2) return (0.0);
  double ans = 0.0;
  for(int i=0;i<n;i++){
    ans += cross(g[i],g[(i+1)%n]);
  }
  return (ans*0.5);
}
// 凸性判定
bool Convexity(const Polygon& g){
  Polygon P=g;
  int n = g.size();
  if(n == 3) return true;
  reverse(P.begin(),P.end());
  for(int i=0;i<n;i++){
    if(ccw(P[(i+n-1)%n],P[i],P[(i+1)%n]) > 0) return false;
  }
  return true;
}
// 凸包
Polygon andrewScan(const Polygon& tmp){
  Polygon u, l, s=tmp;
  if(s.size() < 3) return s;
  sort(s.begin(),s.end());// x,yを基準に昇順ソート
  // xが小さいものから２つ uに追加
  u.push_back(s[0]);
  u.push_back(s[1]);
  // xが大きいものから２つ lに追加
  l.push_back(s[s.size()-1]);
  l.push_back(s[s.size()-2]);
  // 上部を作成
  for(int i=2;i<s.size();i++){
    for(int n=u.size(); (n>=2) && (ccw(u[n-2], u[n-1], s[i]) == COUNTER_CLOCKWISE); n--){
                                                          // != CLOCKWISE;で線上の点をカウントしない
                                                          // == COUNTER_CLOCKWISE;で線上の点をカウントする
      u.pop_back();
    }
    u.push_back(s[i]);
  }
  // 下部を作成
  for(int i=s.size()-3;i>=0;i--){
    for(int n=l.size(); (n>=2) && (ccw(l[n-2],l[n-1],s[i]) == COUNTER_CLOCKWISE); n--){
                                                          // != CLOCKWISE;で線上の点をカウントしない
                                                          // == COUNTER_CLOCKWISE;で線上の点をカウントする
      l.pop_back();
    }
    l.push_back(s[i]);
  }
  // 時計回りになるように点の列を生成
  reverse(l.begin(),l.end());
  for(int i=u.size()-2;i>=1;i--) l.push_back(u[i]);

  // Y座標が小さいところから
  Polygon t;
  double w=l[0].y;
  for(int i=1;i<l.size();i++){
    if(l[i].y>=w) break;
    t.push_back(l[i-1]);
    w=l[i].y;
  }
  l.erase(l.begin(),l.begin()+t.size());
  for(int i=0;i<t.size();i++) l.push_back(t[i]);

  return (l);
}
// 凸多角形の直径
double PolyDiam(const Polygon& g){
  int n = g.size();
  int is, js;
  is = js = 0;
  for(int i=1;i<n;i++){
    if(g[i].y > g[is].y) is=i;
    if(g[i].y < g[js].y) js=i;
  }
  double maxdis = (g[is]-g[js]).norm();

  int maxi, maxj, i, j;
  i = maxi = is;
  j = maxj = js;
  do{
    if(cross(g[(i+1)%n]-g[i], g[(j+1)%n]-g[j]) >= 0){
      j = (j+1)%n;
    }else{
      i = (i+1)%n;
    }
    if((g[i]-g[j]).norm() > maxdis){
      maxdis = (g[i]-g[j]).norm();
      maxi = i;
      maxj = j;
    }
  }while((i != is)||(j != js));
  return sqrt(maxdis);
}
// 最近点対 最も近い２点の距離
double ClosetPair(Polygon& ps){
  if(ps.size() <= 1) throw (0);
  sort(begin(ps), end(ps));

  auto compare_y = [&](const Point &a, const Point &b) {
    return a.y < b.y;
  };
  Polygon beet(ps.size());
  const double INF = 1e18;

  function< double(int, int) > rec = [&](int left, int right) {
    if(right - left <= 1) return INF;
    int mid = (left + right) >> 1;
    auto x = ps[mid].x;
    auto ret = min(rec(left, mid), rec(mid, right));
    inplace_merge(begin(ps) + left, begin(ps) + mid, begin(ps) + right, compare_y);
    int ptr = 0;
    for(int i = left; i < right; i++) {
      if(fabs((ps[i].x) - x) >= ret) continue;
      for(int j = 0; j < ptr; j++) {
        auto luz = ps[i] - beet[ptr - j - 1];
        if(luz.y >= ret) break;
        ret = min(ret, (luz).abs());
      }
      beet[ptr++] = ps[i];
    }
    return ret;
  };
  return rec(0, (int) ps.size());
}
// 凸多角形の切断
Polygon PolyCut(const Polygon &p,const Point& p1,const Point& p2){
  return PolyCut(p,Line(p1,p2));
}
Polygon PolyCut(const Polygon &p,const Line& l){
  Polygon ret;
  for(int i = 0; i < p.size(); i++) {
    Point now = p[i], nxt = p[(i + 1) % p.size()];
    if(ccw(l.p1, l.p2, now) != -1) ret.push_back(now);
    if(ccw(l.p1, l.p2, now) * ccw(l.p1, l.p2, nxt) < 0) {
      ret.push_back(getCrossPoint(Line{now,nxt}, l));
    }
  }
  return (ret);
}
// 円の交差判定
int intersect(Circle& c1, Circle& c2){
  if(c1.r < c2.r) swap(c1,c2);
  double d = (c1.p - c2.p).abs();
  // 交わっていない 4
  if(c1.r+c2.r < d) return 4;
  // 外接している 3
  if(eq(c1.r+c2.r, d)) return 3;
  // 交わっている 2
  if(c1.r-c2.r < d) return 2;
  // 内接している 1
  if(eq(c1.r-c2.r, d)) return 1;
  // 内包している 0
  return 0;
}
// 点pを通る円の接線
pair<Point,Point> tangent(const Circle& c,const Point& p){
  return getCrossPoints(c,Circle(p,sqrt((c.p-p).norm()-c.r*c.r)));
}
// 点pを反時計回りに回転
Point rotate(double theta, const Point& p){
  return Point(cos(theta)*p.x - sin(theta)*p.y, sin(theta)*p.x + cos(theta)*p.y);
}
// 二つの円の共通接線
Lines tangent(Circle c1, Circle c2){
  Lines ret;
  if(c1.r < c2.r) swap(c1,c2);
  double g = (c1.p-c2.p).norm();
  if(eq(g,0.0)) return ret;
  Point u = (c2.p-c1.p)/sqrt(g);
  Point v = rotate(PI*0.5, u);
  for(int s:{-1,1}){
    double h = (c1.r+ s*c2.r)/sqrt(g);
    if(eq(1- h*h, 0)){
      ret.emplace_back(c1.p+u*c1.r, c1.p+(u+v)*c1.r);
    }else if(1-h*h > 0){
      Point uu = u*h, vv = v*sqrt(1-h*h);
      ret.emplace_back(c1.p+(uu+vv)*c1.r, c2.p-(uu+vv)*c2.r*s);
      ret.emplace_back(c1.p+(uu-vv)*c1.r, c2.p-(uu-vv)*c2.r*s);
    }
  }
  return ret;
}
// (0,0)と点x,yの図形の面積(三角形と扇形(半径r))
double calc_element(const Point& x,const Point& y,double r,bool triangle){
  if(triangle) return cross(x,y)/2.0;
  Point tmp = y*Point(x.x,-x.y);
  double ang = atan2(tmp.y,tmp.x);
  return r*r*ang/2.0;
}
// 多角形と円の共通面積
double area(const Polygon &p, const Circle &c){
  if(p.size() < 3) return 0.0;
  function< double(Circle, Point, Point) > cross_area = [&](Circle c, Point a, Point b) {
    Point va = c.p - a, vb = c.p - b;
    double f = cross(va, vb), ret = 0.0;
    if(eq(f, 0.0)) return ret;
    if(max(va.abs(), vb.abs()) < c.r + EPS) return f;
    if(getDistaneceSP(Segment(a, b), c.p) > c.r - EPS) return c.r * c.r * arg(vb * Point(va.x,-va.y));
    auto u = getCrossPoints(c, Segment(a, b));
    vector< Point > tot{a, u.fi, u.se, b};
    for(int i = 0; i + 1 < tot.size(); i++) {
      ret += cross_area(c, tot[i], tot[i + 1]);
    }
    return ret;
  };
  double A = 0;
  for(int i = 0; i < p.size(); i++) {
    A += cross_area(c, p[i], p[(i + 1) % p.size()]);
  }
  return A*0.5;
}
// 円と円の共通面積
double area(const Circle& c1, const Circle& c2){
  double d = (c1.p-c2.p).abs();
  if(c1.r+c2.r <= d+EPS) return 0.0;
  if(d <= fabs(c1.r-c2.r)+EPS){
    double r=min(c1.r,c2.r);
    return r*r*PI;
  }
  double rc = (d*d + c1.r*c1.r - c2.r*c2.r)/(2*d);
  double theta = acos(rc/c1.r);
  double phi = acos((d-rc) / c2.r);
  return (c1.r*c1.r*theta + c2.r*c2.r*phi - d*c1.r*sin(theta));
}
// 三角形の内接円
Circle Inscribed(const Point& a, const Point& b, const Point& c){
  double A = (b-c).abs(), B = (c-a).abs(), C = (a-b).abs();
  Point x((a*A + b*B + c*C)/(A+B+C));
  double r = getDistaneceSP(Segment(a,b),x);
  return Circle(x, r);
}
// 三角形の外接円の座標
Circle Circum(const Point& a, const Point& b, const Point& c){
  Point m1((a+b)/2.0), m2((b+c)/2.0);
  Point v((b-a).y, (a-b).x), w((b-c).y, (c-b).x);
  Line s(m1, Point(m1+v)), t(m2, Point(m2+w));

  const Point x = getCrossPoint(s, t);
  return Circle(x, (a-x).abs());
}