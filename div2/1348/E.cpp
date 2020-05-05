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

bool dp[505][505];
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vi a(n+1);
	vi b(n+1);
	ll sum[2] = {0,0};
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		cin >> b[i];
		
		sum[0] += a[i];
		sum[1] += b[i];
	}
	dp[0][0] = 1;
	for(int idx = 1; idx <= n; idx++){
		for (int red = 0; red < k; red++){
			dp[idx][red] |= dp[idx - 1][((red - a[idx])%k + k)%k];
			for (int extra = 0; extra <= min(k-1, a[idx]); extra++){
				if((a[idx] - extra)%k + b[idx] >= k){
					dp[idx][red] |= dp[idx - 1][(red - extra + k)%k];
				}
			}
		}
	}
	ll ans = 0;
	for (int i = 0; i < k; i++){
		ans = max(ans, dp[n][i] * ((sum[0] + sum[1] - i)/k)	);
	}
	cout << ans << endl;
	
	return 0;
}

