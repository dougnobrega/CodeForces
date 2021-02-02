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

ll n, m, k;
bool check(ll mid){
	ll ans = 0;
	mid--;
	for (int i = 1; i <= n; i++){
		ans = ans + min(m, mid / i);
	}
	
	return ans < k;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	cin >> n >> m >> k;
	
	ll lo = 1, hi = n *1ll* m + 1, mid;
	while(lo <= hi){
		mid = (lo + hi)>> 1;
		if(check(mid)){
			lo = mid + 1;
		}else{
			hi = mid - 1;
		}		
	}
	
	cout << lo - 1 << endl;
		
	return 0;
}


