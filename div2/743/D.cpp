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
vll payment(200001+1);
vi g[200001];
ll dp[200001][2];
ll answer = -INFLL;
void dfs(int v, int dad){
	dp[v][0] = payment[v];
	dp[v][1] = -INF;
	for(auto u : g[v]){
		if(dad == u) continue;
		dfs(u, v);
		dp[v][0] += dp[u][0];
		dp[v][1] = max(dp[v][1], dp[u][1]);
	}
	dp[v][1] = max(dp[v][1], dp[v][0]);
	vll ans;
	for(auto u : g[v])if(dad != u) ans.PB(dp[u][1]);
	sort(all(ans));
	if(ans.size() > 1) answer = max(answer, ans.back() + ans[ans.size() -2]);
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> payment[i];
	}
	for (int i = 1; i < n; i++){
		int x, y;
		cin >> x >> y;
		g[x].PB(y);
		g[y].PB(x);
	}
	dfs(1, 0);
	if(answer == -INFLL) cout << "Impossible" << endl;
	else 			   cout << answer << endl;
	return 0;
}


