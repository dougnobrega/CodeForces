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
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	ll n;
	cin >> n;
	for (ll x = 1; x <= 1000000; x++){
		ll f = x-n;
		ll s = x*n;
		ll gcd = mdc(f,s);
		f /= gcd;
		s /= gcd;
		if(f == 1 and s > 0 && s != n && s != x and s <= 1000000000){
			cout << n << " " <<  x  << " " << s << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}








