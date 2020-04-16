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
vi g[210000];
ll abaixo[210000];
ll acima[210000];
ll dfs(int v, int dad,int x){
	acima[v] = x;
	ll ans = 0;
	for(auto u : g[v]){
		if(u == dad) continue;
		ans += 1 + dfs(u, v, x + 1);
	}
	return abaixo[v] = ans;	
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i < n; i++){
		int x, y;
		cin >> x >> y;
		g[x].PB(y);
		g[y].PB(x);
	}
	dfs(1,0,0);
	priority_queue<ll> fila;
	for (int i = 1; i <= n ; i++){
		fila.push(acima[i]-abaixo[i]);
	}
	ll ans = 0;
	for(int i = 0; i < k; i++){
		auto top = fila.top();
		fila.pop();
		ans += top;
	}
	cout << ans << endl;
	
	
	return 0;
}

