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
char matrix[505][505];
int vis[505][505];
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};
vector<string> answer;
void dfs(int x, int y){
	if(matrix[x][y] != '.') return;
	answer.PB("B " + to_string(x) + " " + to_string(y));
	matrix[x][y] = 'B';
	for (int i = 0; i < 4; i++){
		dfs(x + dx[i], y + dy[i]);
	}
	answer.PB("D " + to_string(x) + " " + to_string(y));
	matrix[x][y] = 'R';
	answer.PB("R " + to_string(x) + " " + to_string(y));
	
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	memset(matrix, '#', sizeof matrix);
	memset(vis, -1, sizeof vis);
	
	int n, m;
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> matrix[i][j];
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(matrix[i][j] == '.'){
				answer.PB("B " + to_string(i) + " " + to_string(j));
				matrix[i][j] = 'B';
				for (int k = 0; k < 4; k++){
					dfs(i + dx[k], j + dy[k]);
				}
			}
		}
	}
	
	cout << answer.size() << endl;

	for(auto x : answer){
		cout << x << endl;
	}
	return 0;
}
