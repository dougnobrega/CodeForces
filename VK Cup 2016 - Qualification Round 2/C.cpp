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
vpi g[200001];
vi ans[200001];
int max_d = 0;
void dfs(int v, int dad, int day){
	int d = 0;
	for(auto u : g[v]){
		if(u.F == dad) continue;
		++d;
		if(d == day) ++d;
		dfs(u.F, v, d);
		ans[d].PB(u.S);
		max_d = max(max_d, d);
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i < n; i++){
		int x, y;
		cin >> x >> y;
		g[x].PB(MP(y,i));
		g[y].PB(MP(x,i));
	}
	dfs(1,0,0);
	cout << max_d << endl;
	for (int i = 0; i <= max_d; i++){
		if(ans[i].size() == 0) continue;
		cout << ans[i].size();
		for(auto x : ans[i]){
			cout <<" " <<  x ;
		}
		cout << endl;
		
	}
	
	return 0;
}

