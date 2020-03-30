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
//	dp[ind][se eu usei o ultimo pegando de cima pra baixo]
int dp[100001][2];
string s;
int main(){
	memset(dp,-1,sizeof dp);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> s;
	//pegando normal
	dp[0][0] = s[0] - '0';
	//pegando de cima pra baixo
	dp[0][1] = 10 - (s[0] - '0');
	for (int i = 1; i < s.size(); i++){
		//pegar normal
		dp[i][0] = min(dp[i-1][0], dp[i-1][1] + 1) + (s[i] - '0'); //esse +1 é devido eu pegar de um cara que veio de cima pra baixo
		dp[i][1] = min(dp[i-1][0], dp[i-1][1] - 1)+ 10 - (s[i] - '0');
	}
	int answer = min(dp[s.size()-1][0], dp[s.size()-1][1] + 1);
	cout << answer << endl;
	return 0;
}


