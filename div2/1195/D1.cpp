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
	ll sum = 0;
	ll n;
	cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; i++){
		cin >> v[i];
		ll b = 0;
		for(auto c : v[i]){
			b *= 100;
			b += c - '0';
			b %= MOD;
		}
		sum += b;
	}
	
	ll answer = 0;
	for (int i = 0; i < n; i++){
		answer += sum;
		answer %= MOD;
		ll a = 0;
		int cont = 1;
		for(auto c : v[i]){
			a += c - '0';
			if(cont != (int)v[i].size())
				a *= 100;
			else a *= 10;
			cont++;
			a %= MOD;
		}
		answer += n * a;
		answer %= MOD;
	}
	
	cout << answer << endl;
	return 0;
}


