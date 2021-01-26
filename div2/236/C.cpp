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

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	ll n;
	cin >> n;
	if(n <= 2){
		cout << n << endl;
		return 0;
	}
	ll ans = 0;
	
	for (ll i = 3; i <= n; i++){
		ans = max(ans, mmc(i, mmc(i-1, i-2)));
		if(i > 3) ans = max(ans, mmc(i, mmc(i-1, i-3)));
 	}
	cout << ans << endl;
	return 0;
}

