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

int counter[100100];
vi g[100100];
int now = 0;
int vis[100100];
int t;
void dfs(int i){
	if(i == t) return;
	if(vis[i] == now) return;
	if(counter[i] > 2) return;
	vis[i] = now;
	counter[i]++;
	for(auto u : g[i]) dfs(u);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m >> t;
	for (int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		g[y].PB(x);
	}
	vi ans;
	for(auto v : g[t]){
		now++;
		dfs(v);
	}
	
	for(auto v : g[t]){
		if(counter[v] == 1) ans.PB(v);
	}
	sort(all(ans));
	cout << ans.size() << endl;
	for(auto x : ans){
		cout << x << endl;
	}
	return 0;
}

