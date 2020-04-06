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
ll rules[20][20];
ll dp[2][18][1<<18];
int main(){
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	memset(dp, -INF, sizeof dp);	
	vll v(n);
	for(int ptr = 0; ptr < n; ptr++){
		cin >> v[ptr];
		dp[0][ptr][1<<ptr] = v[ptr];
	}
	for (int i = 0; i < k; i++){
		ll a, b, c;
		cin >> a >> b >> c;
		rules[--a][--b] = c;
	}
	int now = 0;
	for (int i = 1; i < m; i++){
		now = !now;
		
		for(int mask = 0; mask < (1<<n); mask++){
			if(__builtin_popcount(mask) != i){
				continue;
			}
			for(int ptr = 0; ptr < n; ptr++){
				if(!(mask & (1 << ptr))) continue;
				for(int j = 0; j < n; j++){
					if(mask & (1 << j)) continue;
					dp[now][j][mask | (1 << j)] = max(dp[now][j][mask | (1 << j)], dp[!now][ptr][mask] + v[j] + rules[ptr][j]);
				}
			}
		}
		memset(dp[!now], -INF, sizeof dp[!now]);
	}
	ll ans = 0;
	for(int mask = 0; mask < (1<<n); mask++){
		if(__builtin_popcount(mask) != m){
			continue;
		}
		for(int ptr = 0; ptr < n; ptr++){
			if(!(mask & (1 << ptr))) continue;
				ans = max(ans, dp[now][ptr][mask]);
		}
	}
	cout << ans << endl;
	return 0;
}

