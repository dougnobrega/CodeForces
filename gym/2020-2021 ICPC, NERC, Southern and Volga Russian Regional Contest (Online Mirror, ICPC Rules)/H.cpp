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

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n, k, m;
		cin >> n >> k >> m;
		int sz = n-m;
		vi b(m);
		for (int i = 0; i < m; i++){
			cin >> b[i];
		}
		
		if(sz % (k - 1)){
			cout << "NO" << endl;
			continue;
		}
		int ans = false;
		vi a(n + 1);
		
		for (int i = 1; i <= n; i++){
			a[i] = 1;
		}
		
		for (int i = 0; i < m; i++){
			a[b[i]] = 0;
		}
		
		vi prefix(n+1);
		vi suffix(n+2);
		
		for (int i = 1; i <= n; i++){
			prefix[i] = prefix[i-1] + a[i];
		}
		
		for (int i = n; i >= 1; i--){
			suffix[i] = suffix[i+1] + a[i];
		}
		
		for (int i = 0; i < m; i++){
			if(prefix[b[i]] >= k/2 and suffix[b[i]] >= k/2) ans = true;
		}
		
		
		if(ans){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
	}
	return 0;
}


