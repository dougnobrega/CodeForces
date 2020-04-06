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
int dp[101][1 << 18];
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
int elements[61];
int pos[61];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	for (int i = 0; i < 17; i++){
		pos[primes[i]] = (1 << (i+1));
	}
	
	for(int i = 2; i <= 60; i++){
		int j = 2;
		int aux = i;
		while(aux != 1){
			while(aux%j == 0){
				aux /= j;
				elements[i] |= pos[j];
			}
			j++;
		}
	}
	
	int n;
	cin >> n;
	
	vi v(n+1);
	for (int i = 1; i <= n; i++){
		cin >> v[i];
	}
	memset(dp,INF,sizeof dp);
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++){
		for(int mask = 0; mask < (1 << 17); mask++){
			dp[i][mask] = min(dp[i][mask], dp[i-1][mask] + abs(v[i] - 1));
			for (int num = 2; num <= 60 ; num++){
				if((mask & elements[num]) == elements[num]) dp[i][mask] = min(dp[i][mask], dp[i-1][mask ^ elements[num]] + abs(v[i] - num));	
			}
		}
	}
	int mask = 0;
	for(int i = 0; i < (1 << 17); i++){
		if(dp[n][mask] > dp[n][i]) mask = i;
	}
	int i = n;
	vi ans;
	while(i){
		if(dp[i][mask] == dp[i-1][mask] + abs(v[i] - 1)){
			i--;
			ans.PB(1);
			continue;
		}
		for (int num = 2; num <= 60 ; num++){
			if((mask & elements[num]) == elements[num] && dp[i][mask] == dp[i-1][mask ^ elements[num]] + abs(v[i] - num)){
				i--;
				mask ^= elements[num];
				ans.PB(num);
				break;
			}
		}
	}
	reverse(all(ans));
	for(auto x : ans) cout << x << " ";
	cout << endl;
	return 0;
}

