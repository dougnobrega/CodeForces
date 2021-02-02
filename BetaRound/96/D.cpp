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
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define all(x) x.begin(),x.end()
#define MOD 1000000007ll
#define endl '\n'
#define mdc(a, b) (__gcd((a), (b)))
#define mmc(a, b) (((a)/__gcd(a, b)) * (b))
#define W(x) cerr << "\033[31m"<<  #x << " = " << x << "\033[0m" << endl;
// fim da Prioridade
ll dist[1002];
vpll g[1002];
vpll g2[1002];
void djikstra(int i){
	priority_queue <pii> pq;
	pq.push({0,i});
	memset(dist, 0x3f, sizeof dist);
	dist[i] = 0;
	
	while(!pq.empty()){
		int v = pq.top().S;
		pq.pop();
		for(auto u : g[v]){
			if(dist[v] + u.S < dist[u.F]){
				dist[u.F] = dist[v] + u.S;
				pq.push({-dist[u.F], u.F});
			}
		}
	}
}
void djikstra2(int i){
	priority_queue <pll> pq;
	pq.push({0,i});
	memset(dist, 0x3f, sizeof dist);
	dist[i] = 0;
	
	while(!pq.empty()){
		int v = pq.top().S;
		pq.pop();
		for(auto u : g2[v]){
			if(dist[v] + u.S < dist[u.F]){
				dist[u.F] = dist[v] + u.S;
				pq.push({-dist[u.F], u.F});
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	int s, f;
	cin >> s >> f;
	for (int i = 0; i < m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		g[u].PB({v,w});
		g[v].PB({u,w});
	}
	
	vpll v(n + 1);
	for (int i = 1; i <= n; i++){
		cin >> v[i].F >> v[i].S;
	}
	
	
	for(int i = 1; i <= n; i++){
		djikstra(i);
		for(int j = 1; j <= n; j++){
			if(dist[j] <= v[i].F){
				g2[i].PB({j, v[i].S});
			}
		}
	}
	
	djikstra2(s);
	
	cout << (dist[f] >= INFLL ? -1 : dist[f]) << endl;
	
	
	return 0;
}


