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
		int n, m, k;
		cin >> n >> m >> k;
		vector<char> cases(n);
		for (int i = 0; i < n; i++){
			cin >> cases[i];
		}
		vi vis(n);
		vi deu_merda(n,0);
		int ans = 0;
		for (int i = 0; i < k; i++){
			vis[i] = 1;
			deu_merda[i] = 1;
		}
		for (int i = 0; i < m; i++){
			char op;
			int ind;
			cin >> op;
			if(op == 'W'){
				cin >> ind;
				ind--;
				if(vis[ind]){
					ans += deu_merda[ind];
				}else{
					for (int j = ind; j >= k ; j--){
						if(vis[j]) break;
						vis[j] = 1;
						deu_merda[j] = (cases[j] == 'S');
					}					
				}
			}else{
				for (int j = n-1; j >= k; j--){
					if(vis[j]) break;
					vis[j] = 1;
					deu_merda[j] = (cases[j] == 'S');
				}
			}
		}
		cout << ans << endl;
		
	}
	return 0;
}

