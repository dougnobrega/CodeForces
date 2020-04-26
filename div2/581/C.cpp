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
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	ll n, k;
	cin >> n >> k;
	vi count(110,0);
	
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		count[x]++;
	}
	int ok = 1;
	while(ok){
		ok = 0;
		for(int resto = 9; resto >= 0; resto--){
			for(int level = 0; level < 100; level++){
				if(level % 10 == resto){
					ll contribu = min((10LL-resto) * count[level], k);
					if(k  < (10 - resto)) continue;
					k -= contribu;
					contribu /= (10LL-resto);
					count[level + 10 - resto] += contribu;
					count[level] -= contribu;
					
					if(contribu > 0) ok = 1;
				}
			}
		}
	}
	ll ans = 0;
	for (int i = 0; i <= 100; i++){
		ans += (i/10)*count[i];
	}
	cout << ans << endl;
	return 0;
}



