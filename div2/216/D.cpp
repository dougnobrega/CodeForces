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
	ios_base::sync_with_stdio(false); cin.tie(NULL); 
	int n;
	cin >> n;
	vi v[1001];
	for (int i = 0; i < n; i++){
		int k;
		cin >> k;
		while(k--){
			int x;
			cin >> x;
			v[i].PB(x);
		}
		sort(all(v[i]));
	}
	int ans = 0;
	for (int now = 0; now < n; now++){
		int prev = (now - 1 + n) % n;
		int next = (now + 1 + n) % n;
		for (int section = 0; section < (int)v[now].size()-1; section++){
			int s_p = lower_bound(all(v[prev]), v[now][section]) 	 - v[prev].begin();
			int e_p = lower_bound(all(v[prev]), v[now][section + 1]) - v[prev].begin();
			
			int s_n = lower_bound(all(v[next]), v[now][section]) 	 - v[next].begin();
			int e_n = lower_bound(all(v[next]), v[now][section + 1]) - v[next].begin();
			
			if(e_p - s_p != e_n - s_n) ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
 
