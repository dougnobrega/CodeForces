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

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, k ;
	cin >> n >> m >> k;
	if(k == 1 or k > n){
		ll ans = m;
		for (int i = 1; i < n; i++){
			ans = (ans * m)%MOD;
		}
		cout << ans << endl;
	}else if(n == k){
		ll ans = m;
		for (int i = 1; i < (n+1)/2; i++){
			ans = (ans * m)%MOD;
		}
		cout << ans << endl;
	}else if(k%2 == 0){
		cout << m << endl;
	}else{
		cout << m*m << endl;
	}
	return 0;
}

