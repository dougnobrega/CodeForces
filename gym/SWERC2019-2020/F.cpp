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

ll cross(pii a, pii b){
	return (a.F*1ll*b.S) - (a.S*1ll*b.F);
}
pii getNewPair(pii a, pii b){
	return MP(a.F - b.F, a.S - b.S);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	ll ans = 0;
	for (int i = 0; i < n; i++){
		int p;
		cin >> p;
		pii first;
		cin >> first.F >> first.S;
		ll acc = 0;
		vpi v(p);
		
		for (int j = 1; j < p; j++){
			cin >> v[j].F >> v[j].S;
		}
		
		for (int j = 2; j < p; j++){
			acc += cross(getNewPair(v[j], first), getNewPair(v[j-1], first));
		}
		ans += abs(acc);
	}
	cout << ans/2 << endl;
	
	
	return 0;
}

