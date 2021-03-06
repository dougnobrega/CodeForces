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
		vll cnt(30,0);
		int n, m, k;
		cin >> n >> m >> k;
		string a, b;
		cin >> a >> b;
		ll ans = 0;
		vector<set<int> > count(30);
	
		for(int i = 0; i < n + 1 - k; i++){
			count[a[i+k-1] - 'a'].insert(a[i] - 'a');
		
		}
		
		for(auto x : b){
			cnt[x - 'a']++;
			for (auto &v : count[x-'a']){
				ans += cnt[v];
			}
		}
		cout << ans << endl;
	}
	return 0;
}


