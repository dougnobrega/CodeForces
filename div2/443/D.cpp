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
struct probability{
	double win = 0;
	double lose = 1;
	probability(){
	}
};

probability dp[110];


vector<double> p;
int n;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);	
	cin >> n;
	p.resize(n);

	for (int i = 0; i < n; i++){
		cin >> p[i];
	}

	sort(all(p));

	for(int idx = n-1; idx >= 0; idx--){
		double successWithFriend = dp[idx + 1].win * (1 - p[idx]) + dp[idx + 1].lose * p[idx];
		double successWithoutFriend = dp[idx + 1].win;
		if(successWithFriend - successWithoutFriend >= 1e-10){
			dp[idx].win = successWithFriend;
			dp[idx].lose = dp[idx + 1].lose * (1 - p[idx]);
		}else{
			dp[idx] = dp[idx + 1];
		}
	}
	
	cout << setprecision(9) << fixed << dp[0].win << endl;
	
	return 0;
}


