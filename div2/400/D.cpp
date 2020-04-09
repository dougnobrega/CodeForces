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
int dist[501][501];
int pai[200001];
int find(int x){
	if(x == pai[x]) return x;
	return pai[x] = find(pai[x]);
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	for (int i = 0; i < 200001; i++){
		pai[i] = i;
	}
	
	int n, m, k;
	cin >> n >> m >> k;
	vi index(n);
	int ini = 1;
	
	memset(dist, INF, sizeof dist);	

	for (int i = 0; i < k; i++){
		dist[i][i] = 0;
		int x;
		cin >> x;
		for (int j = ini; j < ini + x; j++){
			index[j] = i;
		}
		ini += x;
	}
	
	for (int i = 0; i < m; i++){
		int u, v, x;
		cin >> u >> v >> x;
		if(x == 0) pai[find(u)] = find(v);
		u = index[u];
		v = index[v];
		dist[u][v] = min(dist[u][v],x);
		dist[v][u] = min(dist[v][u],x);
	}
	int component[510];
	
	for(int i = 1; i <= n; i++){
		component[index[i]] = find(i); 
	}
	
	for(int i = 1; i <= n; i++){
		if(component[index[i]]!= find(i)){
			cout << "No" << endl;
			return 0;
		} 
	}
	n = k;

	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]); 
			}
		}
	}
	cout << "Yes" << endl;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n ; j++){
			cout << ((dist[i][j] < INF) ? dist[i][j] : -1) << " ";
		}
		cout << endl;
	}
	
	return 0;
}
