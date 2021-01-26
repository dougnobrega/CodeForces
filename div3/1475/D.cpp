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
		ll n, m;
		cin >> n >> m;
		
		vpll v(n);	
		ll sum = 0;
		for (int i = 0; i < n; i++){
			cin >> v[i].F;
			sum += v[i].F;
		}
		vll a;
		vll b;
		for (int i = 0; i < n; i++){
			cin >> v[i].S;
			if(v[i].S == 1){
				a.PB(v[i].F);
			}else{
				b.PB(v[i].F);
			}
		}
		if(m >	 sum){
			cout << "-1" << endl;
			continue;
		}
		sort(all(a)); reverse(all(a));
		sort(all(b)); reverse(all(b));
		for (int i = 1; i < a.size(); i++){
			a[i] += a[i-1];
		}
		for (int i = 1; i < b.size(); i++){
			b[i] += b[i-1];
		}
		int ans = INF;
		
		for(int i = 0; i < a.size(); i++){
			int pos = lower_bound(all(b), m - a[i]) - b.begin();
			if(a[i] < m){
				if(pos < b.size() and a[i] + b[pos] >= m) ans = min(i + 1 + 2*(pos + 1), ans); 
			}else {
				ans = min(i+1, ans);
			}
		}
		for(int i = 0; i < b.size(); i++){
			int pos = lower_bound(all(a), m - b[i]) - a.begin();
			if(b[i] < m){
				if(pos < a.size() and b[i] + a[pos] >= m) ans = min(2*(i + 1) + (pos + 1), ans); 
			}else{
				ans = min(2*(i+1), ans);
			}
		}

		cout << ans << endl;
		
		
	}
	return 0;
}







