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
#define MOD 1000003ll
#define endl '\n'
#define mdc(a, b) (__gcd((a), (b)))
#define mmc(a, b) (((a)/__gcd(a, b)) * b)
#define W(x) cerr << "\033[31m"<<  #x << " = " << x << "\033[0m" << endl;
// fim da Prioridade
ll legendreFormula(ll n, ll prime = 2){
	ll exp = 0;
	while(n){
		n /= prime;
		exp += n;
	}
	return exp;
}

ll fast_exp(ll base, ll exp){
	if(exp == 0) return 1;
	if(exp&1) return (base * fast_exp(base, exp - 1)) % MOD;
	ll x = fast_exp(base, exp >> 1);
	return (x * x) % MOD;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	ll n, k;
	
	cin >> n >> k;
	
	if(n <= 63 && k > (1ll << n)){
		cout << "1 1" << endl;
		return 0;
	}
	ll sumPot2 = legendreFormula(k - 1);

	ll ktmp = k % (MOD - 1);
	n %= (MOD - 1);	
	sumPot2 %= (MOD - 1);
	if(sumPot2 < 0 ) sumPot2 += MOD - 1;
	
	ll exponent = n * (ktmp - 1) - sumPot2;
	exponent %= (MOD - 1);
	if(exponent < 0) exponent += MOD - 1;
	
	ll denominator = fast_exp(2LL, exponent);
	
	ll value;
	
	if(k - 1 >= MOD){
		value = 0; //because the product is zero
	}else{
		ll product;
		ll pot2N = fast_exp(2LL, n);
		product = fast_exp(2ll, sumPot2);
		product = fast_exp(product, MOD - 2); // multiplicative inverse
		
		for (ll i = 1; i <= k - 1 ; i++){
			product = (product * (pot2N - i)) % MOD; 
		}
		
		value = product;
	}

	ll numerator = (denominator - value + MOD) % MOD;
	
	cout << numerator << " " << denominator << endl;
	  
	return 0;
}



