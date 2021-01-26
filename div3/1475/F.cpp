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
#define mmc(a, b) (((a)/__gcd(a, b)) * b)
#define W(x) cerr << "\033[31m"<<  #x << " = " << x << "\033[0m" << endl;
// fim da Prioridade

char a[1010][1010];
char b[1010][1010];
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				cin >> a[i][j];
			}
		}
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				cin >> b[i][j];
			}
		}
		
		for(int i = 0; i < n; i++){
			if(a[0][i] != b[0][i]){
				for(int j = 0; j < n; j++) a[j][i] = (a[j][i] == '1' ? '0' : '1');
			}
		}
		
		for(int i = 0; i < n; i++){
			if(a[i][0] != b[i][0]){
				for(int j = 0; j < n; j++) a[i][j] = (a[i][j] == '1' ? '0' : '1');
			}
		}
		
		int count = 0;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				count += (a[i][j] != b[i][j]);
			}
		}
		if(count){
			cout << "NO" << endl;
		}else{
			cout << "YES" << endl;
		}
		
	}
	return 0;
}

