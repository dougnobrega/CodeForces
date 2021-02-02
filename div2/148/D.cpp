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
#define mmc(a, b) (((a)/__gcd(a, b)) * (b))
#define W(x) cerr << "\033[31m"<<  #x << " = " << x << "\033[0m" << endl;
// fim da Prioridade

double dp[1001][1001][2];
int  seen[1001][1001][2];
double solve(int w, int b, bool dragon){
	if(b < 0 or w <= 0) return 0;
	if(w == 1 and b == 0) return 1.0;
	if(seen[w][b][dragon]) return dp[w][b][dragon];
	seen[w][b][dragon] = 1;
	
	double ans = 0.0;
	if(dragon){
		double black = (b-1)/double(w + b - 1);
		double white = w/double(w + b - 1);
		W(black);
		W(white);
		ans = w/double(w + b) + b/double(w + b) * white * (1.0 - solve(w-1, b-1, false)) + b/double(w + b) * black * (1.0 - solve(w, b-2, false));
	}else{
		ans = w/double(w + b) + b/double(w + b) * (1.0 - solve(w, b-1, true));
	}
	
	
	return dp[w][b][dragon] = ans;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int w, b;
	cin >> w >> b;
	
	cout << setprecision(12) << fixed << solve(w, b, false) << endl;
	return 0;
}


