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
double probability[20][20];
double dp[1<<18];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); 
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> probability[i][j];
		}
	}
	
	dp[0] = 1;
	for (int mask = 1; mask < (1<<n); mask++){
		dp[mask] = 0;
		
		double p = n - __builtin_popcount(mask);
		p *= (p+1);
		
		for(int killer = 0; killer < n; killer++){
			if(mask & (1 << killer)) continue;	
			
			for(int dead = 0; dead < n; dead++){
				if(!(mask & (1 << dead))) continue;
				
				dp[mask]  += (2.0 / p) * probability[killer][dead] * dp[mask ^ (1 << dead)];
			}
		}
	}
	
	for(int i = 0; i < n; i++){
		cout << setprecision(6) << fixed << dp[((1 << n) - 1) ^ (1 << i)] << " ";
	}
	
	cout << endl;
	return 0;
}
 

