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
typedef double ld;
const ld DINF = 1e18;
const ld pi = acos(-1.0);
const ld eps = 1e-9;

#define sq(x) ((x)*(x))

bool eq(ld a, ld b) {
	return abs(a - b) <= eps;
}

struct pt { // ponto
	ld x, y;
	pt() {}
	pt(ld x_, ld y_) : x(x_), y(y_) {}
	bool operator < (const pt p) const {
		if (!eq(x, p.x)) return x < p.x;
		if (!eq(y, p.y)) return y < p.y;
		return 0;
	}
	bool operator == (const pt p) const {
		return eq(x, p.x) and eq(y, p.y);
	}
	pt operator + (const pt p) const { return pt(x+p.x, y+p.y); }
	pt operator - (const pt p) const { return pt(x-p.x, y-p.y); }
	pt operator * (const ld c) const { return pt(x*c  , y*c  ); }
	pt operator / (const ld c) const { return pt(x/c  , y/c  ); }
	ld operator * (const pt p) const { return x*p.x + y*p.y; }
	ld operator ^ (const pt p) const { return x*p.y - y*p.x; }
	friend istream& operator >> (istream& in, pt& p) {
		return in >> p.x >> p.y;
	}
};
ld dist(pt p, pt q) { // distancia
	return hypot(p.y - q.y, p.x - q.x);
}
pt rotate90(pt p) { // rotaciona 90 graus
	return pt(-p.y, p.x);
}

vector<pt> circ_inter(pt a, pt b, ld r, ld R) { // intersecao da circunf (a, r) e (b, R)
	vector<pt> ret;
	ld d = dist(a, b);
	if (d > r+R or d+min(r, R) < max(r, R)) return ret;
	ld x = (d*d-R*R+r*r)/(2*d);
	ld y = sqrt(r*r-x*x);
	pt v = (b-a)/d;
	ret.push_back(a+v*x + rotate90(v)*y);
	if (y > 0) ret.push_back(a+v*x - rotate90(v)*y);
	return ret;
}
vi g[2000];
int vis[2000];
void dfs(int v){
	if(vis[v]) return;
	vis[v] = 1;
	for(auto u : g[v]) dfs(u);
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n;
	cin >> n;
	vector<pair<pt, int> > v(n);
	
	for (int i = 0; i < n; i++){
		cin >> v[i].F.x >> v[i].F.y >> v[i].S;
	}
	
	ll vx = 0, e = 0, c = 0;
	
	vector<pt> vertex;
	
	for(int i = 0; i < n; i++){
		vector<pt> edges;
		for (int j = 0; j < n; j++){
			vector<pt> p = circ_inter(v[i].F, v[j].F, v[i].S, v[j].S);
			if(i != j and p.size() > 0){
				g[i].PB(j);
				g[j].PB(i);
				while(!p.empty()){
					edges.PB(p.back());
					vertex.PB(p.back());
					p.pop_back();
				}
			}
		}
		sort(all(edges));
		edges.erase(unique(all(edges)), edges.end());
		e += edges.size();
	}
	
	sort(all(vertex));
	vertex.erase(unique(all(vertex)), vertex.end());
	vx += vertex.size();
	for (int i = 0; i < n; i++){
		if(!vis[i]) dfs(i), c++;
	}

	
	ll f = e - vx + c + 1 ;
	cout << f << endl;
	return 0;
}

