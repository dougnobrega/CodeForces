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
int matrix[505][505];
int aux[505][505];
int n, m;	
int valid(int x, int y){
	if(x < 1 || x > n || y < 1 || y > m) return 0;
	return 1;
}
vi answer(100050); 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int x, y;
	cin >> n >> m >> x >> y;
	string s;
	cin >> s;
	int i = x, j = y;
	
	int cnt = 1;
	aux[i][j] = 1;
	answer[0] = 1;
	for(auto c : s){
		int ni = i, nj = j;
		if(c == 'L'){
			nj--;
		}else if(c == 'R'){
			nj++;
		}else if(c == 'U'){
			ni--;
		}else{
			ni++;
		}
		if(cnt == s.size()) continue;
		if(valid(ni, nj)){
			i = ni, j = nj;
			if(aux[ni][nj] == 0)
				answer[cnt]++;
			aux[ni][nj] = 1;
		}
		cnt++;
	}
	
	answer[cnt] = n * m;
	
	for (i = 1; i <= n; i++){
		for(j = 1; j <= m; j++){
			answer[cnt] -= aux[i][j];
		}
	}
	for(i = 0; i <= s.size();i++){
		cout << answer[i] << " ";
	}
	cout << endl;
 	
	return 0;
}

