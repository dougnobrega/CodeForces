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
#define mmc(a, b) (((a)/__gcd(a, b)) * b)
#define W(x) cerr << "\033[31m"<<  #x << " = " << x << "\033[0m" << endl;
// fim da Prioridade

/**/
vll fat(1010);
vll inv_fat(1010);

ll fast_exp(ll b, ll exp){
	if(exp == 0) return 1;
	if(exp & 1)  return (b * 1ll * fast_exp(b, exp - 1))%MOD;
	ll x = fast_exp(b, exp / 2);
	return (x*x)%MOD;
}

ll getAns(ll n, ll r){
	ll ans = fat[n] * fast_exp((fat[r] * 1ll * fat[n - r]) % MOD, MOD-2);
	return ans % MOD;
}
	
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	fat[0] = fat[1] = 1;
	for (int i = 1; i <=  1000;i++){
		fat[i] = (fat[i-1] *1ll* i)%MOD;
	}
	
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		vi v(n);
		map<int,int> mapa;
		
		for (int i = 0; i < n; i++){
			cin >> v[i];
			mapa[v[i]]++;
		}
		sort(all(v));
		v.erase(unique(all(v)), v.end());
		reverse(all(v));
		ll answer = 0;
		for(int i = 0; i < v.size(); i++){
			if(k <= mapa[v[i]]){
				answer = getAns(mapa[v[i]], k);
				break;
			}else{
				k -= mapa[v[i]];
			}
		}
		cout << answer << endl;
	}
	return 0;
}







