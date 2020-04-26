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
ll dpLeft[500002][2];
ll dpRight[500002][2];
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	
	vll v(n+1);
	
	for (int i = 1; i <= n; i++){
		cin >> v[i];
	}
	dpLeft[0][0] = 0;
	dpLeft[0][1] = -INFLL;
	for(int idx = 1; idx <= n; idx++){
		for(int sign = 0; sign <= 1; sign++){
			ll ans = v[idx] + dpLeft[idx - 1][sign];
			ans = max(ans, -v[idx] + dpLeft[idx - 1][max(sign - 1, 0)]);
			dpLeft[idx][sign] = ans;
		}
	}
	
	dpRight[n+1][0] = 0;
	dpRight[n+1][1] = -INFLL;
	for(int idx = n ; idx >= 0; idx--){
		for(int sign = 0; sign <= 1; sign++){
			ll ans = v[idx] + dpRight[idx + 1][sign];
			ans = max(ans, -v[idx] + dpRight[idx + 1][max(sign - 1, 0)]);
			dpRight[idx][sign] = ans;
		}
	}
	
	dpLeft[0][1] = dpRight[n+1][1] = 0;
	
	ll best = -INFLL;
	for (int idx = 1; idx <= n; idx++){
		ll ans = dpLeft[idx - 1][1] + v[idx] + dpRight[idx + 1][1]; 
		best = max(best, ans);
	}
	
	cout << best << endl;
	return 0;
}

