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
ll mat[510][510];
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	if(n == 1){
		cout << 1 << endl;
		return 0;
	}
	int x= 0 , y = 0;
	for (int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> mat[i][j];
			if(mat[i][j] == 0) x = i, y = j; 
		}
	}
	ll sumCorrect = 0;
	ll sumWithoutANumber = 0;
	for(int i = 0; i < n; i++){
		sumWithoutANumber += mat[x%n][i];
		sumCorrect += mat[(x + 1)%n][i];
	}
	mat[x][y] = sumCorrect - sumWithoutANumber;
	if(mat[x][y] < 1 ){
		cout << -1 << endl;
		return 0;
	}
	set<ll> sums;
	for (int i = 0; i < n; i++){
		ll acc = 0;
		for(int j = 0; j < n; j++){
			 acc += mat[i][j];
		}
		sums.insert(acc);
	}
	
	for (int i = 0; i < n; i++){
		ll acc = 0;
		for(int j = 0; j < n; j++){
			 acc += mat[j][i];
		}
		sums.insert(acc);
	}
	ll acc = 0;
	for (int i = 0; i < n; i++){
		acc += mat[i][i];
	}
	sums.insert(acc);
	
	acc = 0;
	for (int i = 0; i < n; i++){
		acc += mat[i][n-i-1];
	}
	sums.insert(acc);
	if(sums.size() == 1){
		cout << mat[x][y] << endl;
	}else{
		cout << -1 << endl;
	}
	return 0;
}



