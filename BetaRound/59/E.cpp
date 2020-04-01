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
vi g[3010];
int dist[3001][3001];
int vis[3001][3001];
pii p[3001][3001];
set<pii> forbidden[3001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		g[x].PB(y);
		g[y].PB(x);
	}
	for (int i = 0; i < k; i++){
		int x, y, z;
		cin >> x >> y >> z;
		forbidden[x].insert({y,z});
	}
	queue<pii> q;
	q.push(MP(1,0));
	p[1][0] = MP(-1, -1);
	vis[1][0] = 1;
	while(!q.empty()){
		auto front = q.front();
		q.pop();
		for(auto v : g[front.F]){
			if(vis[v][front.F]) continue;
			if(forbidden[front.S].count(MP(front.F, v))) continue;
			p[v][front.F] = front;
			dist[v][front.F] = dist[front.F][front.S] + 1;
			vis[v][front.F] = 1;
			q.push(MP(v,front.F));
		}
	}
	int ind = 0;
	dist[n][0] = INF;
	for(int i = 1; i <= n; i++){
		if(dist[n][i] > 0 && dist[n][i] < dist[n][ind]){
			ind = i;
		}
	}
	
	if(dist[n][ind] == INF){
		cout << -1 << endl;
	}else {
		cout << dist[n][ind] << endl;
		vi path;
		for(pii v = MP(n,ind); v != MP(-1,-1); v = p[v.F][v.S]){
			path.PB(v.F);
		}
		reverse(all(path));
		for(auto x : path){
			cout << x << " ";
		}
		cout << endl;
	}
	return 0;
}

