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
		int n, k;
		cin >> n >> k;
		vi v(n);
		
		set<int> c;
		for (int i = 0; i < n; i++){
			cin >> v[i];
			c.insert(v[i]);
		}
		if(n == k){
			cout << n << endl;
			for (int i = 0; i < n; i++){
				cout << v[i] << " ";
			}
			cout << endl;
		}else{
			if(c.size() > k){
				cout << -1 << endl;
				continue;
			}
			vi ans;
			vi seq;
			for(auto x : c){
				seq.PB(x);
			}
			while(seq.size() < k) seq.PB(seq.back());
			int from = 0;
			int i = 0;
			for(i = 0; i < n and ans.size() < 10000;){
				int last = seq[from];
				from++;
				from %= k;
				if(last == v[i]){
					ans.PB(last);
					i++;
				}else{
					ans.PB(last);
				}
			}
			cout << ans.size() << endl;
			for (i = 0; i < ans.size(); i++){
				cout << ans[i] << " ";
			}
			cout << endl;
			
		}
		
	}
	return 0;
}

