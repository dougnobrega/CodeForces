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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vi a(n);
	vi b(n);
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	for (int i = 0; i < n; i++){
		cin >> b[i];
	}
	int va = 0;
	int vb = 0;
	for (int i = 0; i < n; i++){
		if(a[i] == 1 && b[i] == 1){
			a[i] = 0;
			b[i] = 0;
		}
	}
	for (int i = 0; i < n; i++){
		if(b[i] == 1){
			vb++;
		}
		if(a[i] == 1){
			va++;
		}
	}
	vb++;
	if(va == 0){
		cout << -1 << endl;
	}else{
		cout << max(1,(vb+va-1)/va) << endl;
	}
	
	return 0;
}

