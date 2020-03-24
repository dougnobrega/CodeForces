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
int n, m;
int mat[510][510];
int leftSuperior[510][510];	
int leftInferior[510][510];
int rightSuperior[510][510];
int rightInferior[510][510];

void preCompute(){
	for (int i = 0; i <= n+1; i++){
		for (int j = 0; j <= m+1 ; j++){
			leftInferior[i][j] = leftSuperior[i][j] = rightInferior[i][j] = rightSuperior[i][j] = 0;
		}
	}
	
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			leftSuperior[i][j] = max(mat[i][j],max(leftSuperior[i][j-1],leftSuperior[i-1][j]));
		}
	}
	for (int i = 1; i <= n; i++){
		for (int j = m; j >= 1; j--){
			rightSuperior[i][j] = max(mat[i][j],max(rightSuperior[i][j+1],rightSuperior[i-1][j]));
		}
	}
	
	for (int i = n; i >= 1; i--){
		for (int j = 1; j <= m; j++){
			leftInferior[i][j] = max(mat[i][j],max(leftInferior[i][j-1],leftInferior[i+1][j]));
		}
	}
	for (int i = n; i >= 1; i--){
		for (int j = m; j >= 1; j--){
			rightInferior[i][j] = max(mat[i][j],max(rightInferior[i][j+1],rightInferior[i+1][j]));
		}
	}
}

ll getAnswer(int i, int j){
	int best = -1, worst = INF;
	
	best = max(best, leftSuperior[i-1][j-1]);
	best = max(best, leftInferior[i+1][j-1]);
	best = max(best, rightSuperior[i-1][j+1]);
	best = max(best, rightInferior[i+1][j+1]);
	
	worst = min(worst, leftSuperior[i-1][j-1]);
	worst = min(worst, leftInferior[i+1][j-1]);
	worst = min(worst, rightSuperior[i-1][j+1]);
	worst = min(worst, rightInferior[i+1][j+1]);
	return best - worst;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		cin >> n >> m;
		
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m;j++){
				cin >> mat[i][j];
			}
		}
		
		preCompute();
		ll ans = INFLL;
		for (int i = 2; i < n ; i++){
			for (int j = 2; j < m; j++){
				ans = min(ans, getAnswer(i,j));
			}
		}
		cout << ans << endl;
		
	}
	return 0;
}
