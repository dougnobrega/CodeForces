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
vll dp(200001);
int idx[200001];
vll primes;
void sieve(){
	bitset<200001> p;
	p.flip();
	for (ll i = 2; i <= 200001; i++){
		if(p[i]){
			primes.PB(i);
			for(ll j = i * i; j <= 200001; j += i){
				p[j] = 0;
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	vll v(n + 1);
	
	for(int i = 1; i <= n; i++){
		cin >> v[i];
	}

	ll ans = 0;
	for(int i = 1; i <= n; i++){
		dp[i] = 1;
		for(ll j = 1; j * j <= v[i]; j++){
			if(v[i] % j == 0){
				if(j != 1){
					dp[i] = max(dp[i], dp[idx[j]] + 1);
					idx[j] = i;
				}
				if(v[i] / j != j){
					dp[i] = max(dp[i], dp[idx[v[i]/j]] + 1);
					idx[v[i]/j] = i;
				}
			}
		}
		ans = max(ans, dp[i]);
	}
	
	cout << ans << endl;
	
	return 0;
}







