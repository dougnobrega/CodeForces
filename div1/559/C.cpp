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
ll fat[200001];
ll inv_fat[200001];
ll dp[2001];
ll fast_exp(ll base, ll exp){
	if(exp == 0) return 1LL;
	if(exp & 1) return (base * fast_exp(base,exp-1))%MOD;
	ll x = fast_exp(base,exp>>1ll);
	return (x*x)%MOD;
}
void init(){
	fat[0] = 1;
	inv_fat[0] = 1;
	for(ll i = 1; i < 200001; i++){
		fat[i] = (i * fat[i-1])%MOD;
		inv_fat[i] = fast_exp(fat[i], MOD-2);
	}
}
ll calc(ll x, ll y){
	ll ans = (fat[x + y] * inv_fat[x])%MOD;
	ans = (ans * inv_fat[y])%MOD;
	return ans;
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); init();
	int h, w, n;
	cin >> h >> w >> n;

	vpi blackCells(n);
	for (int i = 0; i < n; i++){
		cin >> blackCells[i].F >> blackCells[i].S; 
	}
	blackCells.emplace_back(h,w);
	sort(all(blackCells));
	for (int i = 0; i <= n; i++){
		dp[i] = calc(blackCells[i].F - 1, blackCells[i].S - 1);
	}
	for (int i = 0; i <= n; i++){
		for (int j = 0; j < i ; j++){
			if((blackCells[i].F < blackCells[j].F) || (blackCells[i].S < blackCells[j].S)) continue;
			dp[i] -= (dp[j] * calc(blackCells[i].F - blackCells[j].F, blackCells[i].S - blackCells[j].S)) % MOD;
			dp[i] = (dp[i] + MOD) % MOD;
		}
	}
	
	cout << dp[n] << endl;
	
	return 0;
}


