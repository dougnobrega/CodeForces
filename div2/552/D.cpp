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
#define MOD 998244353ll
#define endl '\n'
#define mdc(a, b) (__gcd((a), (b)))
#define mmc(a, b) (((a)/__gcd(a, b)) * b)
#define W(x) cerr << "\033[31m"<<  #x << " = " << x << "\033[0m" << endl;
// fim da Prioridade
vpi pts;
ll n;
double PI = acos(-1);

ll calculateCollinear(int idx){
	map<pii, int> counting;
	for(int i = 0; i < n; i++){
		if(i == idx) continue;
		pii p = {pts[i].F - pts[idx].F, pts[i].S - pts[idx].S};
		ll gcd = mdc(p.F, p.S);
		p.F /= gcd;
		p.S /= gcd;
		if(p.F < 0) p.F *= -1, p.S *= -1;
		counting[p]++;
	}
	ll ans = 0;
	for(auto x : counting){
		ans += (x.S*(x.S-1))/2;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;
	pts.resize(n);
	ll ans = (n * (n-1) * (n-2))/6;
	
	for (int i = 0; i < n; i++){
		cin >> pts[i].F >> pts[i].S;
	}
	ll collineares = 0;
	for (int i = 0; i < n; i++){
		collineares += calculateCollinear(i);
	}
	collineares /= 3;
	cout << ans - collineares << endl;
	return 0;
}




