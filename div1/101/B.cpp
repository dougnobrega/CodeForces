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
ll dp[200020];
ll acc_dp[200020];
vi bus[200020];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	
	vi compression;
	compression.PB(-1);
	compression.PB(0);
	compression.PB(n);
	
	vpi edges(m);
	for (int i = 0; i < m; i++){
		cin >> edges[i].F >> edges[i].S;
		compression.PB(edges[i].F);
		compression.PB(edges[i].S);
	}
	sort(all(compression));
	compression.erase(unique(all(compression)),compression.end());
	
	for (int i = 0; i < m; i++){
		int start = lower_bound(all(compression), edges[i].F) - compression.begin(); 
		int end   = lower_bound(all(compression), edges[i].S) - compression.begin();
		bus[end].PB(start);
	}
	int home   = lower_bound(all(compression), 0) - compression.begin();
	int school = lower_bound(all(compression), n) - compression.begin(); 
		
	dp[home] = 1;
	acc_dp[home] = 1;
	for(int pos = home+1; pos <= school; pos++){
		for(auto prev : bus[pos]){
			dp[pos] = dp[pos] + acc_dp[pos-1] - acc_dp[prev-1];
			dp[pos] = (dp[pos] % MOD + MOD) % MOD;
		}
		acc_dp[pos] = (dp[pos] + acc_dp[pos-1])%MOD;
	}
	
	cout << dp[school] << endl;
	return 0;
}

