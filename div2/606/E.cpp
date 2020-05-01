#include <bits/stdc++.h>
using namespace std;
// Prioridade
typedef long long   ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpi;
typedef vector<pll> vpll;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(int i = a; i < (int)(b); i++)
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define all(x) x.begin(),x.end()
#define MOD 1000000007ll
#define endl '\n'
#define mdc(a, b) (__gcd((a), (b)))
#define mmc(a, b) (((a)/__gcd(a, b)) * b)
#define W(x) cerr << "\033[31m"<<  #x << " = " << x << "\033[0m" << endl;
// fim da Prioridade
const double inf = 1e100, eps = 1e-9;
const double PI = acos(-1.0L);

int cmp (double a, double b = 0) {
  if (abs(a-b) < eps) return 0;
  return (a < b) ? -1 : +1;
}

struct PT {
  double x, y;
  PT(double _x = 0, double _y = 0) : x(_x), y(_y) {}
  PT operator + (const PT &p) const { return PT(x+p.x, y+p.y); }
  PT operator - (const PT &p) const { return PT(x-p.x, y-p.y); }
  PT operator * (double c) const { return PT(x*c, y*c); }
  PT operator / (double c) const { return PT(x/c, y/c); }
  
  bool operator <(const PT &p) const {
    if(cmp(x, p.x) != 0) return x < p.x;
    return cmp(y, p.y) < 0;
  }
  bool operator ==(const PT &p) const {
    return !cmp(x, p.x) && !cmp(y, p.y);
  }
  bool operator != (const PT &p) const {
    return !(p == *this);
  }
};
double dot (PT p, PT q) { return p.x * q.x + p.y*q.y; }
double cross (PT p, PT q) { return p.x * q.y - p.y*q.x; }
double dist2 (PT p, PT q = PT(0, 0)) { return dot(p-q, p-q); }
double dist (PT p, PT q) { return hypot(p.x-q.x, p.y-q.y); }
double norm (PT p) { return hypot(p.x, p.y); }
PT normalize (PT p) { return p/hypot(p.x, p.y); }
double angle (PT p, PT q) { return atan2(cross(p, q), dot(p, q)); }
double angle (PT p) { return atan2(p.y, p.x); }
double polarAngle (PT p) {
  double a = atan2(p.y,p.x);
  return a < 0 ? a + 2*PI : a;
}

bool ptInSegment (PT a, PT b, PT c) {
  if (a == b) return a == c;
  a = a-c, b = b-c;
  return cmp(cross(a, b)) == 0 && cmp(dot(a, b)) <= 0;
}

bool ptInsideTriangle(PT p, PT a, PT b, PT c) {
  if(cross(b-a, c-b) < 0) swap(a, b);
  if(ptInSegment(a,b,p)) return 1;
  if(ptInSegment(b,c,p)) return 1;
  if(ptInSegment(c,a,p)) return 1;
  bool x = cross(b-a, p-b) < 0;
  bool y = cross(c-b, p-c) < 0;
  bool z = cross(a-c, p-a) < 0;
  return x == y && y == z;
}

bool pointInConvexPolygon(const vector<PT> &p, PT q) {
  if (p.size() == 1) return p.front() == q;
  int l = 1, r = p.size()-1;
  while(abs(r-l) > 1) {
    int m = (r+l)/2;
    if(cross(p[m]-p[0] , q-p[0]) < 0) r = m;
    else l = m;
  }
  return ptInsideTriangle(q, p[0], p[l], p[r]);
}

void sortByAngle (vector<PT>::iterator first, vector<PT>::iterator last, const PT o) {
  first = partition(first, last, [&o] (const PT &a) { return a == o; });
  auto pivot = partition(first, last, [&o] (const PT &a) {
    return !(a < o || a == o); // PT(a.y, a.x) < PT(o.y, o.x)
  });
  auto acmp = [&o] (const PT &a, const PT &b) { // C++11 only
    if (cmp(cross(a-o, b-o)) != 0) return cross(a-o, b-o) > 0;
    else return cmp(norm(a-o), norm(b-o)) < 0;
  };
  sort(first, pivot, acmp);
  sort(pivot, last, acmp);
}

vector<PT> graham (vector<PT> v) {
  sort(v.begin(), v.end());
  sortByAngle(v.begin(), v.end(), v[0]);
  vector<PT> u (v.size());
  int top = 0;
  for (int i = 0; i < v.size(); i++) {
    while (top > 1 && cmp(cross(u[top-1] - u[top-2], v[i]-u[top-2])) <= 0) top--;
    u[top++] = v[i];
  }
  u.resize(top);
  return u;
}
vector<PT> points;
int check(long double days, PT f){
	vector <PT> aux;
	for(auto p : points) aux.PB(PT(p.x * days, p.y * days));
	return pointInConvexPolygon(aux, f);
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int sz;
	PT q;
	cin >> sz >> q.x >> q.y;
	points.resize(sz);
	for (int i = 0; i < sz; i++){
		cin >> points[i].x >> points[i].y;
	}
	double bestx = 0.0;
	double besty = 0.0;
	points.PB(PT(0.0,0.0));
	for(int i = 0; i < points.size(); i++){
		bestx = max(bestx, points[i].x);
		besty = max(besty, points[i].y);
	}
	points.PB(PT(0.0, besty));
	points.PB(PT(bestx, 00));
	points = graham(points);

	long double lo = 0, hi = 1e10, mid;
	for (int i = 0; i < 200; i++){
		mid = (lo + hi)/2.0;
		if(check(mid, q)){
			hi = mid;
		}else{
			lo = mid;
		}
	}
	cout << setprecision(10) << fixed << lo << endl;
	return 0;
}

