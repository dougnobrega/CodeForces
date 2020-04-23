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
int row[1002];
int collumn[1002];
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); 
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		row[x]++;
		collumn[y]++;
	}
	if(n == 2){
		cout << 0 << endl;
		return 0;
	}else if(n == 3){
		cout << ((row[2] == 0) & (collumn[2] == 0)) << endl;
		return 0;
	}
	ll ans = 0;
	
	for(int i = 2; i < n + 1 - i ; i++){
		ans += (row[i] == 0) + (collumn[i] == 0);
		ans += (row[n + 1 - i] == 0) + (collumn[n + 1 - i] == 0);
	}
	ans += (n&1)*((row[(n+1)/2] == 0) || (collumn[(n+1)/2] == 0));
	cout << ans << endl;
	
	return 0;
}
 

