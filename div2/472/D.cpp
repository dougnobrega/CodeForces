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
int dist[2001][2001];
vi g[2001];
int pai[2001];
int ini;
void dfs(int v, int dad, int d){
	if(dist[ini][v] != d || dist[v][ini] != d){cout << "NO " << endl; exit(0);}
	for(auto u : g[v]){
		if(u == dad) continue;
		dfs(u, v, d + dist[v][u]);
	}
}
int find(int x){
	if(x == pai[x]) return x;
	return pai[x] = find(pai[x]);
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	priority_queue<pair<int, pii> > q;
	for(int i = 0; i < n; i++){
		pai[i] = i;
		for(int j = 0; j < n; j++){	
			cin >> dist[i][j];
			if(dist[i][i] > 0  || (dist[i][j] == 0 and i != j)) {cout << "NO " << endl; exit(0);}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){	
			q.push({-dist[i][j], {i, j}});
		}
	}
	
	//MST
	while(!q.empty()){
		auto top = q.top();
		q.pop();
		if(find(top.S.F) == find(top.S.S)) continue;
		pai[find(top.S.F)] = find(top.S.S);
		g[top.S.F].PB(top.S.S);
		g[top.S.S].PB(top.S.F);
	}	
	for (int i = 0; i < n; i++){
		ini = i;
		dfs(i, -1, 0);
	}
	
	cout << "YES" << endl;
	return 0;
}





