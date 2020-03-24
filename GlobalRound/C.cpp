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
#define MOD 998244353LL
#define endl '\n'
#define mdc(a, b) (__gcd((a), (b)))
#define mmc(a, b) (((a)/__gcd(a, b)) * b)
#define W(x) cerr << "\033[31m"<<  #x << " = " << x << "\033[0m" << endl;
// fim da Prioridade

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vpi v(n);
	for (int i = 0; i < n; i++){
		cin >> v[i].F;
		v[i].S = i;
	}
	sort(all(v));
	reverse(all(v));
	ll ans1 = 0, ans2 = 1;
	vll pos;
	for (int i = 0; i < k; i++){
		ans1 += v[i].F;
		pos.PB(v[i].S+1);
	}
	sort(all(pos));
	for (int i = 1; i < pos.size(); i++){
		ans2 = (ans2 * (pos[i]- pos[i-1]))%MOD;
	}
	cout << ans1 << " " << ans2 << endl;
	
	return 0;
}
