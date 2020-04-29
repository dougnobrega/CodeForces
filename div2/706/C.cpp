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
	int n;
	cin >> n;
	map<string, int> conj;
	vll cost(n);
	for (int i = 0; i < n; i++){
		cin >> cost[i];
	}
	vector< vector<string> > words(2, vector<string> (n));
	for (int i = 0; i < n; i++){
		cin >> words[0][i];
		words[1][i] = words[0][i];
		reverse(all(words[1][i]));
		conj[words[0][i]] = 0;
		conj[words[1][i]] = 0;
	}
	
	vector<vi> order(2, vi(n+1));
	order[0][0] = 0;
	order[1][0] = 0;
	int i = 0;
	for(auto &x : conj){
		x.S = i++;
	}
	
	for (i = 0; i < n; i++){
		order[0][i+1] = conj[words[0][i]];
		order[1][i+1] = conj[words[1][i]];
	}
	
	vector< vll > dp(2, vll (n + 1,INFLL));
	dp[0][0] = 0;
	dp[1][0] = 0;
	for (int idx = 1; idx <= n; idx++){
		for (int rev = 0; rev <= 1 ; rev++){
			ll c = 0;
			if(rev == 1) c = cost[idx - 1];
			if(order[rev][idx] >= order[1][idx - 1]){
				dp[rev][idx] = min(dp[rev][idx], dp[1][idx - 1] + c);
			}
			if(order[rev][idx] >= order[0][idx - 1]){
				dp[rev][idx] = min(dp[rev][idx], dp[0][idx - 1] + c);
			}
		}
	}
	ll answer = min(dp[0][n], dp[1][n]);
	if(answer == INFLL) answer = -1;
	cout << answer << endl;
	
	return 0;
}

