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
int cost[100][101];
	// idx  k   last_color  
ll dp[100][100][101];
vi color;
int n, m;
ll solve(int idx, int k, int last){
	if(idx == (int)color.size() and k == 0) return 0;
	if(k < 0) return INFLL;
	if(idx == (int)color.size()) return INFLL;
	if(dp[idx][k][last] != -1) return dp[idx][k][last];

	ll answer = INFLL;
	
	if(color[idx] == 0){
		for (int c = 1; c <= m; c++){
			answer = min(answer, cost[idx][c] + solve(idx + 1, k - (last != c) , c));
		}
		
	}else{
		answer = solve(idx + 1, k - (last != color[idx]) , color[idx]);
	}	
	
	return dp[idx][k][last] = answer;
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int k;
	cin >> n >> m >> k;
	color.resize(n);
	
	for (int i = 0; i < n; i++){
		cin >> color[i];
	}
	
	for (int i = 0; i < n; i++){
		for (int j = 1; j <= m; j++){
			cin >> cost[i][j];
		}
	}
	
	memset(dp, -1, sizeof dp);
	
	ll answer = solve(0,k,0);
	if(answer == INFLL) cout << -1 << endl;
	else  			  cout << answer << endl;
	return 0;
}



