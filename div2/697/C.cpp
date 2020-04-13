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
map<ll,ll> rules;
int level(ll x){
	int ans = 0;
	while(x != 0){
		ans++;
		x >>= 1;
	}
	return ans;
}

ll climb(ll x){
	return x >> 1;
}

void updateRules(ll x, ll y, ll fee){
	int lx = level(x);
	int ly = level(y);
	while(x != y){
		if(lx == ly){
			rules[x] += fee;
			rules[y] += fee;
			x = climb(x), lx--;
			y = climb(y), ly--;
		}else if(lx > ly){
			rules[x] += fee;
			x = climb(x), lx--;
		}else{
			rules[y] += fee;
			y = climb(y), ly--;
		}
	}
}

ll getAnswer(ll x, ll y){
	int lx = level(x);
	int ly = level(y);
	ll ans = 0;
	while(x != y){
		if(lx == ly){
			ans += rules[x];
			ans += rules[y];
			x = climb(x), lx--;
			y = climb(y), ly--;
		}else if(lx > ly){
			ans += rules[x];
			x = climb(x), lx--;
		}else{
			ans += rules[y];
			y = climb(y), ly--;
		}
	}
	return ans;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int q;
	cin >> q;
	
	while(q--){
		int op;
		cin >> op;
		if(op == 1){
			ll x, y, c;
			cin >> x >> y >> c;
			updateRules(x, y, c);
		}else{
			ll x, y;
			cin >> x >> y;
			cout << getAnswer(x, y) << endl;
		}
	}
	return 0;
}

