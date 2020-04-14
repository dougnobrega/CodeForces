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

vll values;

ll my_sqrt(ll x){
	ll sqr = sqrt(x)+2;
	while(sqr * sqr > x){
		sqr--;
	}
	return sqr;
}

void generate(){
	ll limit = 1e18 + 9;
	for(ll i = 2; i <= 1000000 ; i++){
		ll val = i*i;
		while(true){
			if(val > limit/i){
				break;
			}
			val *= i;
			ll x = my_sqrt(val);
			if(x * x != val) values.PB(val);
		}
	}
	sort(all(values));
	values.erase(unique(all(values)), values.end());
}

ll solve(ll l, ll r){
	ll pot = lower_bound(all(values), r+1) - lower_bound(all(values), l);
	ll pot2 = my_sqrt(r) - my_sqrt(l-1);
	return pot + pot2;
}
	
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	generate();
	int q;
	cin >> q;
	while(q--){
		ll l, r;
		cin >> l >> r;
		cout << solve(l, r) << endl;
	}
	return 0;
}

