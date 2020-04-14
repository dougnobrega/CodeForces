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
int n, m;
int clusters[32];
vll arrays;
int check(int x){
	if(x == 0) return true;
	vll pot2(32,0);
	for (int i = 0; i < x; i++){
		pot2[arrays[i]]++;
	}
	ll remainder = 0;
	for (int i = 30; i >= 0; i--){
		if(pot2[i] > remainder + clusters[i]) return false;
		remainder = (remainder + clusters[i] - pot2[i]) * 2LL;
 	}
	return true;
}

ll solve(){
	int lo = 0, hi = m, mid;
	while(lo <= hi){
		mid = (lo+hi)>>1;
		if(check(mid)){
			lo = mid + 1;
		}else{
			hi = mid - 1;
		}
	}
	return lo - 1;
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		ll x;
		cin >> x;
		for (int j = 0; j < 31 ; j++){
			clusters[j] += ((x>>j) & 1);
		}
	}
	arrays.resize(m);
	for (int i = 0; i < m; i++){
		cin >> arrays[i];
	}
	sort(all(arrays));
	cout << solve() << endl;
	return 0;
}

