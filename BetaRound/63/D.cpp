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
char mat[101][101];
vector<pair<int,char> > v;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int a, b, c, d, n;
	cin >> a >> b >> c >> d >> n;
	memset(mat, '.', sizeof mat);
	v.resize(n);

	for(int i = 1; i <= a; i++){	
		for(int j = 1; j <= b; j++){
			mat[j][i] = '-';
		}
	}
	
	for(int i = a+1; i <= a + c; i++){
		for(int j = 1; j <= d; j++){
			mat[j][i] = '-';
		}
	}
	
	for (int i = 0; i < n; i++){
		cin >> v[i].F;
		v[i].S = 'a' + i;
	}

	int now = 0;
	for(int i = b; i >= 1; i--){	
		if(!(i & 1)){
			for(int j = a; j >= 1; j--){
				if(v[now].F == 0) now++;
					v[now].F--;
				mat[i][j] = v[now].S;
			}
		}else{
			for(int j = 1; j <= a; j++){
				if(v[now].F == 0) now++;
					v[now].F--;
				mat[i][j] = v[now].S;
			}
		}	
	}
	for(int i = 1; i <= d; i++){	
		if(!(i & 1)){
			for(int j = a+c; j > a; j--){
				if(v[now].F == 0) now++;
					v[now].F--;
				mat[i][j] = v[now].S;
			}
		}else{
			for(int j = a+1; j <= a+c; j++){
				if(v[now].F == 0) now++;
					v[now].F--;
				mat[i][j] = v[now].S;
			}
		}	
	}
	cout << "YES" << endl;
	for(int i = 1; i <= max(b,d); i++){
		for(int j = 1; j <= a+c;j++){
			cout << mat[i][j];
		}
		cout << endl;
	}
	
	return 0;
}


