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
#define MOD 1000000007ll
#define endl '\n'
#define mdc(a, b) (__gcd((a), (b)))
#define mmc(a, b) (((a)/__gcd(a, b)) * b)
#define W(x) cerr << "\033[31m"<<  #x << " = " << x << "\033[0m" << endl;
// fim da Prioridade

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t;
	cin >> t;
	
	while(t--){
		ll n;
		cin >> n;
		vi ans;
		for(ll i = 1; i <= n; i *= 2){
			n -= i;
			ans.PB(i);
		}
		if(n > 0) ans.PB(n);
		sort(all(ans));
		cout << ans.size() - 1 << endl;
		for (int i = 0; i < ans.size()-1 ; i++){
			cout << ans[i+1] - ans[i] << " ";
		}
		cout << endl;
	}
	
	return 0;	
}








