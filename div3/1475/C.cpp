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
	int t;
	cin >> t;
	while(t--){
		int n, m, k;
		cin >> n >> m >> k;
		
		vi a(k), b(k);
		map <pii, int> mapa; 
		map <int, int> count[2];
		
		for (int i = 0; i < k; i++){
			cin >> a[i];
			count[0][a[i]]++;
		}
		
		for (int i = 0; i < k; i++){
			cin >> b[i];
			count[1][b[i]]++;
			mapa[{a[i],b[i]}]++;
		}
		ll answer = 0;
		for(int i = 0; i < k;i++){
			ll ans = k - (count[0][a[i]] + count[1][b[i]] - mapa[{a[i], b[i]}]);
			answer += ans;  
		}
		cout << answer / 2 << endl;
		
	}
	return 0;
}







