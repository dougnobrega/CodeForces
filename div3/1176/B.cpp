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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vi v(3);
		for (int i = 0; i < n; i++){
			ll x;
			cin >> x;
			v[x%3]++;
		}
		int dois_um = min(v[1], v[2]);
		v[0] += dois_um;
		v[1] -= dois_um;
		v[2] -= dois_um;
		int ok = 1;
		while(ok){
			ok = 0;
			if(v[1] > 0 && v[2] > 0){
				dois_um = min(v[1], v[2]);
				v[0] += dois_um;
				v[1] -= dois_um;
				v[2] -= dois_um;
				ok = 1;
			}else if(v[1] == 0 && v[2] >= 2){
				v[2] -= 2;
				v[1]++;
				ok = 1;
			}else if(v[1] >= 3){
				v[1] -= 3;
				v[0] ++;
				ok = 1;
			}
		}
		cout << v[0] << endl;
	}
	return 0;
}

