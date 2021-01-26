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
#define mmc(a, b) (((a)/__gcd(a, b)) * b)
#define W(x) cerr << "\033[31m"<<  #x << " = " << x << "\033[0m" << endl;
// fim da Prioridade

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	ll n, d;
	cin >> n >> d;
	int a, b;
	cin >> a >> b;
	vpll v(n);
	for (int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		v[i] = {x*1ll*a + y*1ll*b, i+1}; 
	}
	sort(all(v));
	vi ans;
	for (int i = 0; i < n; i++){
		if(d >= v[i].F){
			d -= v[i].F;
			ans.PB(v[i].S);
		}
	}
	cout << ans.size() << endl;
	for(int x : ans) cout << x << " ";
	cout << endl;
	return 0;
}

