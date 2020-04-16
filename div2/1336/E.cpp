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
#define MOD 998244353
#define endl '\n'
#define mdc(a, b) (__gcd((a), (b)))
#define mmc(a, b) (((a)/__gcd(a, b)) * b)
#define W(x) cerr << "\033[31m"<<  #x << " = " << x << "\033[0m" << endl;
// fim da Prioridade
string s, t;
ll dp[3001][3001];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> s >> t;
	int start = t.size() - 1;
	int end	  = s.size() - 1;
	while(s.size() != t.size()) t += '-';
	
	for (int i = 0; i <= end; i++){
		if(s[0] == t[i] || t[i] == '-') dp[i][i] = 2;
	}
	
	for (int i = end-1; i >= 0; i--){
		for(int j = i+1; j <= end ; j++){
			int idx = j - i;
			ll ans = 0;
			if(t[i] == '-' || s[idx] == t[i])
				ans = (ans + dp[i+1][j]) % MOD;
			if(t[j] == '-' || s[idx] == t[j])
				ans = (ans + dp[i][j-1]) % MOD;
			dp[i][j] = ans;
		}
	}
	
	ll ans = 0;
	for(int i = start; i <= end; i++){
		ans = (ans + dp[0][i]) % MOD;
	}
	cout << ans << endl;
	return 0;
}

