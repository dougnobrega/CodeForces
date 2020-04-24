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
inline pll operator -(const pll &a, const pll &b) {
	return {a.F - b.F, a.S - b.S};
}

inline ll cross(pll a, pll b){
	return a.F * 1LL * b.S - a.S * 1LL * b.F;
}

inline int colinear(pll p1, pll p2, pll p3){
	if(cross(p2 - p1, p3 - p1) == 0) return 1;
	return 0;
} 
inline int challengeAngle(pll p1, pll p2, pll p3){
	
	if(p1.F == p2.F and not(min(p1.S, p2.S) < p3.S and  p3.S < max(p1.S, p2.S))) return 1;
	
	if(p1.S == p2.S and not(min(p1.F, p2.F) < p3.F and  p3.F < max(p1.F, p2.F))) return 1;
	
	return 0;
}
int solve(pll p1, pll p2, pll p3){
	if(colinear(p1, p2, p3)) return 1;
	if(challengeAngle(p1, p2, p3)) return 2;
	return 3;
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	pll p1, p2, p3;
	cin >> p1.F >> p1.S;
	cin >> p2.F >> p2.S;
	cin >> p3.F >> p3.S;
	int ans = 3;
	
	ans = min(ans, solve(p1, p2, p3));
	ans = min(ans, solve(p1, p3, p2));
	ans = min(ans, solve(p2, p1, p3));
	ans = min(ans, solve(p2, p3, p1));
	ans = min(ans, solve(p3, p1, p2));
	ans = min(ans, solve(p3, p2, p1));
	
	cout << ans << endl;
	return 0;
}


