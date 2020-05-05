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
#define MOD 1000000007
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
vector<pair<int, pt> > circles;
vi g[2000];
ld dp[2000][2][2];
ld solve(int v, int l, int r){
	if(dp[v][l][r] > -1e5) return dp[v][l][r];
	ld left, right;
	if(l){
		left = -acos(-1) * circles[v].F * circles[v].F;
	}else{
		left = acos(-1) * circles[v].F * circles[v].F;
	}
	if(r){
		right = -acos(-1) * circles[v].F * circles[v].F;
	}else{
		right = acos(-1) * circles[v].F * circles[v].F;
	}
	for(auto u : g[v]){
		left += solve(u, !l ,r);
		right += solve(u, l ,!r);
	}
	
	return dp[v][l][r] = max(left, right);
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	for (int i = 0; i < 2000; i++){
		for (int j = 0; j <= 1; j++){
			dp[i][j][0] = -1e5;
			dp[i][j][1] = -1e5;
		}
	}
	
	int n;
	cin >> n;
	circles.resize(n); 
	for (int i = 0; i < n; i++){
		cin >> circles[i].S.x >> circles[i].S.y >> circles[i].F;
	}
	sort(all(circles));
	
	vi vis(n,0);
	vi degree(n,0);
	for (int i = 0; i < n; i++){
		for (int j = i + 1; j < n; j++){
			if(dist(circles[i].S, circles[j].S) + circles[i].F <= circles[j].F){
				g[j].PB(i);
				degree[i]++;
				break;
			}
		}
	}
	ld answer = 0;
	for (int i = 0; i < n; i++){
		if(degree[i] == 0){
			answer += solve(i,0,0);
		}
	}
	cout << setprecision(8) << fixed <<  answer << endl;
	return 0;
}


