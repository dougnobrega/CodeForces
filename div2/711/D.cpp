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
const int MAXN = 200000 + 5;
vi g(MAXN, 0);
vi vis(MAXN, 0);
vll pot2(MAXN, 0LL);
vi cycles;
int cnt = 0;
void dfs2(int v){
	cycles[cnt]++;
	vis[v] = 3;
	if(vis[g[v]] == 3) return;
	dfs2(g[v]);
}
void dfs(int v){
	vis[v] = 2;
	if(vis[g[v]] == 0) dfs(g[v]);
	else if(vis[g[v]] == 2){
		cycles.PB(0);
		dfs2(g[v]);
		cnt++;
	}
	vis[v] = 1;	
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	pot2[0] = 1;
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> g[i];
		pot2[i] = (pot2[i-1] << 1)%MOD;
	}
	for (int i = 1; i <= n; i++){
		if(!vis[i]) dfs(i);
	}
	cnt = n;
	
	ll ans = 1;
	for (int i = 0; i < cycles.size(); i++){
		cnt -= cycles[i];
		ans = (ans *(pot2[cycles[i]] - 2ll + MOD))%MOD;
	}
	ans *= pot2[cnt];
	ans %= MOD;
	if(ans < 0) ans += MOD;
	ans %= MOD;
	cout << ans  << endl;
	return 0;
}



