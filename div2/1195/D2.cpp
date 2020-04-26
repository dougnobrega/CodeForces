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
#define MOD 998244353ll
#define endl '\n'
#define mdc(a, b) (__gcd((a), (b)))
#define mmc(a, b) (((a)/__gcd(a, b)) * b)
#define W(x) cerr << "\033[31m"<<  #x << " = " << x << "\033[0m" << endl;
// fim da Prioridade
ll getValue(ll x, ll left, ll pw){
	ll val = 0;
	while(x > 0LL){
		ll dig = x % 10;
		val += (pw * dig) % MOD;
		val %= MOD;
		if(left > 0)
			pw *= 100;
		else
			pw *= 10;
		pw %= MOD;
		left--;
		x /= 10;
	}
	val %= MOD;
	return val;
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	ll n;
	cin >> n;
	vll numberPerSize[12];
	for (int i = 0; i < n; i++){
		ll x;
		cin >> x;
		numberPerSize[to_string(x).size()].PB(x);
	}
	
	ll ans = 0;
	for(int len1 = 1; len1 <= 11; len1++){
		for(int len2 = 1; len2 <= 11; len2++){
			ll sz1 = numberPerSize[len1].size(), sz2 = numberPerSize[len2].size();
			if(len1 == len2){
				for(auto val : numberPerSize[len1]){
					ans += sz2 * getValue(val, len1, 1);
					ans %= MOD;
				}
				for(auto val : numberPerSize[len2]){
					ans += sz1 * getValue(val, len2, 10);
					ans %= MOD;
				}
			}else if(len1 < len2){
				for(auto val : numberPerSize[len1]){
					ans += sz2 * getValue(val, len1, 10);
					ans %= MOD;
				}
				for(auto val : numberPerSize[len2]){
					ans += sz1 * getValue(val, len1, 1);
					ans %= MOD;
				}
			}else{
				for(auto val : numberPerSize[len1]){
					ans += sz2 * getValue(val, len2 - 1, 10);
					ans %= MOD;
				}
				for(auto val : numberPerSize[len2]){
					ans += sz1 * getValue(val, len2, 1);
					ans %= MOD;
				}
			}
		}
	}
	
	cout << ans << endl;
	
	
	return 0;
}


