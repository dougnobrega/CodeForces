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
vi number[100002];
vi dp[100002];
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n;
	cin >> n;
	vll v(n);
	for (int i = 0; i < n; i++){
		cin >> v[i];
		for (ll j = 1; j * j <= v[i] ; j++){
			if(v[i]%j == 0){
				if(j <= n) number[j].PB(i+1);
				if(v[i]/j != j){
					if(v[i]/j <= n) number[v[i]/j].PB(i+1);
				}
			}
		}
	}
	
	for(int curr_idx = n; curr_idx >= 1; curr_idx--){
		dp[curr_idx].resize(number[curr_idx].size(), 1);
		for(int selected_idx = 0; selected_idx < (int)number[curr_idx].size(); selected_idx++){
			int hi = number[curr_idx+1].size() - 1;
			if(hi == -1) break;
			int lo = lower_bound(all(number[curr_idx + 1]), number[curr_idx][selected_idx]+1) - number[curr_idx + 1].begin();
			dp[curr_idx][selected_idx] += dp[curr_idx+1][hi];
			if(lo > 0){
				dp[curr_idx][selected_idx] -= dp[curr_idx+1][lo-1];
			}
			dp[curr_idx][selected_idx] %= MOD;
			if(dp[curr_idx][selected_idx] < 0){
				dp[curr_idx][selected_idx] += MOD;
				dp[curr_idx][selected_idx] %= MOD;
			}
		}
		dp[curr_idx+1].resize(0);
		for(int selected_idx = 1; selected_idx < (int)number[curr_idx].size(); selected_idx++){
			dp[curr_idx][selected_idx] += dp[curr_idx][selected_idx-1];		
			if(dp[curr_idx][selected_idx] >= MOD) dp[curr_idx][selected_idx] -= MOD;
		}
	}
	cout << dp[1][number[1].size() - 1] << endl;
	return 0;
}


