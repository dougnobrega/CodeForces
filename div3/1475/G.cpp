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
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define all(x) x.begin(),x.end()
#define MOD 1000000007ll
#define endl '\n'
#define mdc(a, b) (__gcd((a), (b)))
#define mmc(a, b) (((a)/__gcd(a, b)) * b)
#define W(x) cerr << "\033[31m"<<  #x << " = " << x << "\033[0m" << endl;
// fim da Prioridade

/*
}*/

int countt[202000];
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vi v(n);
		for (int i = 0; i < n; i++){
			cin >> v[i];
			countt[v[i]]++;
		}
		
		int answer = INF;
		vi dp(200100, 0);
		dp[1] = countt[1];
		for(int i = 2; i <= 200000; i++){
			for(int j = 1; j <= i/j; j++){
				if(i%j == 0){
					dp[i] = max(dp[i], dp[j]);
					if(i/j != i) dp[i] = max(dp[i], dp[i/j]);
				}
			}
			dp[i] += countt[i];
			answer = min(answer, n - dp[i]);
		}
		for (int i = 0; i < n; i++){
			countt[v[i]]--;
		}
		cout << answer << endl;
	}
	return 0;
}







