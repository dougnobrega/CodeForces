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
vi tv_in[2*100010];
vi tv_out[2*100010];
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n;
	ll x, y;
	cin >> n >> x >> y;
	vll compression;
	vpll tvShows(n);
	for(int i = 0; i < n; i++){
		cin >> tvShows[i].F >> tvShows[i].S;
		compression.PB(tvShows[i].F);
		compression.PB(tvShows[i].S);
	}
	sort(all(compression));
	compression.erase(unique(all(compression)), compression.end());
	
	for (int i = 0; i < n; i++){
		int start = lower_bound(all(compression), tvShows[i].F) - compression.begin();
		int end   = lower_bound(all(compression), tvShows[i].S) - compression.begin();
		tv_in[start].PB(i);
		tv_out[end].PB(i);
	}
	ll ans = 0;
	priority_queue<ll> televisor;
	
	for(int idx = 0; idx <(int) compression.size();idx++){
		for(auto i : tv_in[idx]){
			pii ref = tvShows[i];
			if(!televisor.empty() and (ref.F - televisor.top())*y < x	){
				ans += ((ref.F - televisor.top())*y)%MOD;
				televisor.pop();
				ans %= MOD;
			}else{
				ans += x;
				ans %= MOD;
			}
			ans += ((ref.S - ref.F)*y)%MOD;
			ans %= MOD;
		}
		for(auto i : tv_out[idx]){
			televisor.push(compression[idx]);
		}
	}
	cout << ans << endl;
	return 0;
}


