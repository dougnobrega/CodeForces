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
int dist[300001];
int vis[300001];
int res[300001];
vpi g[300051];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k, d;
	cin >> n >> k >> d;
	queue<pii> q;
	for (int i = 0; i < k; i++){
		int x;
		cin >> x;
		q.push(MP(x,0));
	}
	
	for (int i = 1; i < n; i++){
		int x, y;
		cin >> x >> y;
		g[x].PB(MP(y, i));
		g[y].PB(MP(x, i));
	}
	
	while(!q.empty()){
		auto front = q.front();
		q.pop();
		if(vis[front.F]) continue;
		vis[front.F] = 1;
		for(auto v : g[front.F]){
			if(v.F != front.S){
				if(vis[v.F]) res[v.S] = 1;
				else q.push(MP(v.F,front.F));	
			}
		}
	}
	int ans = 0;
	for (int i = 1; i < n; i++)
		if(res[i]) ans++;
	cout << ans << endl;
	for (int i = 1; i < n; i++)
		if(res[i]) cout << i << " ";
	return 0;
}

