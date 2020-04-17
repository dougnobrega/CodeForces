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
vpi g[100003];
pii dfs(int v, int dad, int w){
	pii ans = {w,v};
	for(auto u : g[v]){
		if(u.F == dad) continue;
		ans = max(ans, dfs(u.F, v, w + u.S));
	}
	return ans;
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	ll ans = 0;
	for (int i = 1; i < n; i++){
		int x, y, w;
		cin >> x >> y >> w;
		g[x].PB({y,w});
		g[y].PB({x,w});
		ans += 2 * w;
	}
	pii f = dfs(1, 0, 0);

	cout << ans - f.F << endl;
	return 0;
}

