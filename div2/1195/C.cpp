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
// dp[idx][I can't pick in first array][i can't pick in second array]
ll dp[100010][2][2];
vll v[2];
int n;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;
	v[0].resize(n);
	v[1].resize(n);
	for(int i = 0; i < n; i++){
		cin >> v[0][i];
	}
	for(int i = 0; i < n; i++){
		cin >> v[1][i];
	}
	for(int idx = n-1; idx >= 0; idx--){
		for(int lastFromFirst = 0; lastFromFirst <= 1; lastFromFirst++){
			for (int lastFromSecond = 0; lastFromSecond <= 1; lastFromSecond++){
				ll answer = 0;
				if(lastFromFirst){
					answer = max(answer, dp[idx + 1][0][1] + v[1][idx]);
				}else if(lastFromSecond){
					answer = max(answer, dp[idx + 1][1][0] + v[0][idx]);
				}else{
					answer = max(answer, dp[idx + 1][0][1] + v[1][idx]);
					answer = max(answer, dp[idx + 1][1][0] + v[0][idx]);
				}
				answer = max(answer, dp[idx + 1][0][0]);
				dp[idx][lastFromFirst][lastFromSecond] = answer;
			}
		}
	}
	cout << dp[0][0][0] << endl;
	return 0;
}


