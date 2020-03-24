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
char mat[1000][1000];
char auxiliar[1000][1000];
int n;
void changeM(){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			mat[i][j] = auxiliar[i][j];
		}
	}
}

void changeRight(){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if(mat[i][j] == '^'){
				auxiliar[j][n-1-i] = '>';
			}else if(mat[i][j] == 'v'){
				auxiliar[j][n-1-i] = '<';
			}else if(mat[i][j] == '>'){
				auxiliar[j][n-1-i] = 'v';
			}else if(mat[i][j] == '<'){
				auxiliar[j][n-1-i] = '^';
			}else{
				auxiliar[j][n-1-i] = mat[i][j];
			}
		}
	}
	changeM();
}

void changeLeft(){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if(mat[i][j] == '^'){
				auxiliar[n-1-j][i] = '<';
			}else if(mat[i][j] == 'v'){
				auxiliar[n-1-j][i] = '>';
			}else if(mat[i][j] == '>'){
				auxiliar[n-1-j][i] = '^';
			}else if(mat[i][j] == '<'){
				auxiliar[n-1-j][i] = 'v';
			}else{
				auxiliar[n-1-j][i] = mat[i][j];
			}
		}
	}
	changeM();
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string commands;
	cin >> n >> commands;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> mat[i][j];
		}
	}
	int l = 0, r = 0;
	for(auto c : commands){
		if(c == 'L') l++;
		else r++;
	}
	int menor = min(l,r);
	l -= menor;
	r -= menor;
	while(r--){
		changeRight();
	}
	while(l--){
		changeLeft();
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cout << mat[i][j];
		}
		cout << endl;
	}
	
	return 0;
}

