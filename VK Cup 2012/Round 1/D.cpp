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
vi g[50001];
int dp[50001][510];
int sub[50001];
ll ans = 0;
int k;
void dfs(int v, int dad){
	dp[v][0] = 1;
	sub[v] = 1;
	for(auto u : g[v]){
		if(u == dad) continue;
		dfs(u, v);
		sub[v] += sub[u];
		for (int i = 0; i < min(k, sub[u]); i++){
			ans += dp[v][k-i-1]*dp[u][i];
		}
		for(int i = 1; i <= min(k, sub[u]);i++){
			dp[v][i] += dp[u][i-1]; 
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n;
	cin >> n >> k;
	for(int i = 1; i < n; i++){
		int x, y;
		cin >> x >> y;
		g[x].PB(y);
		g[y].PB(x);
	}
	dfs(1,0);
	cout << ans << endl;
	return 0;
}
