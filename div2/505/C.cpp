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
int gems[30001];
int dp[30001][501];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, d;
	cin >> n >> d;
	
	for (int i = 1; i <= n; i++){
		int x;
		cin >> x;
		gems[x]++;
	}
	memset(dp, -INF, sizeof dp);
	int ans = gems[d];
	dp[d][250] = gems[d];
	int shift = 250;
	for (int island = d + 1; island <= 30000; island++){
		for (int diff = 0; diff <= 500; diff++){
			int jump = d + (diff - shift);
			
			if(jump <= 0) continue;
			if(island - jump > 0){
				dp[island][diff] = max(dp[island][diff], gems[island] + dp[island - jump][diff-1]);
				dp[island][diff] = max(dp[island][diff], gems[island] + dp[island - jump][diff]);
				dp[island][diff] = max(dp[island][diff], gems[island] + dp[island - jump][diff+1]);
			}
			ans = max(ans, dp[island][diff]);
		}
	}
	cout << ans << endl;
	return 0;
}

