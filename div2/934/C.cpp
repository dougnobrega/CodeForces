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

int dp[2004][2004];
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	vi v(n + 2);
	vi one(n+2);
	vi two(n+2);
	for (int i = 1; i <= n; i++){
		cin >> v[i];
	}
	for (int i = 1; i <= n; i++){
		one[i] += one[i-1] + (v[i] == 1);
	}
	
	for(int i = n; i >= 1; i--){
		two[i] += two[i+1] + (v[i] == 2);
	}
	
	for (int i = 1; i <= n; i++){
		for (int j = i; j <= n; j++){
			dp[i][j] = max({dp[i][j], one[j] - one[i-1], two[i] - two[j+1]});
		}
	}
	int ans = 1;
	
	for(int len = 1; len < n; len++){
		for(int start = 1; start <= n - len; start++){
			dp[start][start + len] = max({dp[start][start+len], dp[start+1][start+len-1] + (v[start] == 2) + (v[start+len] == 1)});
		}
	}
	
	for(int start = 1;start <= n; start++){
		for(int end = start; end <= n ; end++){
			ans = max(ans, one[start-1] + dp[start][end] + two[end+1]);
		}
	}
	cout << ans << endl;
	return 0;
}

