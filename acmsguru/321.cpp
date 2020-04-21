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
#define MOD 1000000009
#define endl '\n'
#define mdc(a, b) (__gcd((a), (b)))
#define mmc(a, b) (((a)/__gcd(a, b)) * b)
#define W(x) cerr << "\033[31m"<<  #x << " = " << x << "\033[0m" << endl;
// fim da Prioridade
int almost[200002];
int ans[200002];
vpi g[200002];
int dfs(int v, int dad, int dist, int distAlmost){
	int best = 0;
	if(distAlmost * 2 > best) best = ((dist+1)>>1) - dist + distAlmost; 
	for(auto u : g[v]){
		if(u.F == dad) continue;
		int x = dfs(u.F, v, dist + 1, distAlmost + almost[u.S]);
		if(x > distAlmost){
			ans[u.S] = 1;
			x--;
		}
		best = max(x, best);
	}
	return best;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i < n; i++){
		int x, y;
		cin >> x >> y;
		string s;
		cin >> s;
		if(s[0] == 'a'){
			cin >> s;
			almost[i] = 1;
		}
		
		g[x].emplace_back(y,i);
		g[y].emplace_back(x,i);
	}
	dfs(1, 0, 0, 0);
	vi answer;
	for (int i = 0; i < n; i++){
		if(ans[i]) answer.PB(i);
	}
	cout << answer.size() << endl;
	for(auto x : answer){
		cout << x << " ";
	}
	cout << endl;
	
	return 0;
}

