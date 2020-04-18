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
vi g[100002];
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, k, s;
	cin >> n >> m >> k >> s;
	vi vertex(n);
	for(int i = 0; i < n; i++){
		cin >> vertex[i];
		vertex[i]--;
	}
	for (int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		x--, y--;
		g[x].PB(y);
		g[y].PB(x);
	}
	vector<vi> dist(k, vi(n,-1));
	for(int type = 0; type < k; type++){
		queue<int> q;
		for (int i = 0; i < n; i++){
			if(vertex[i] == type){
				dist[type][i] = 0;
				q.push(i);
			}
		}
		while(!q.empty()){
			int v = q.front();
			q.pop();
			for(int u : g[v]){
				if(dist[type][u] == -1){
					dist[type][u] = dist[type][v] + 1;
					q.push(u);
 				}
			}
		}
	}
	for (int i = 0; i < n; i++){
		vi v;
		for (int type = 0; type < k; type++){
			v.PB(dist[type][i]);
		}
		sort(all(v));
		int ans = 0;
		for (int j = 0; j < s; j++){
			ans += v[j];
		}
		cout << ans << " ";
	}
	cout << endl;
	
	return 0;
}

