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
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	int ok = 0;
	vector<string> v(n);
	for (int i = 0; i < n; i++){
		cin >> v[i];
		if(ok) continue;
		if(v[i][0] == 'O' && v[i][1] == 'O'){
			ok = 1;
			v[i][0] = '+';
			v[i][1] = '+';
			continue;
		}
		if(v[i][3] == 'O' && v[i][4] == 'O'){
			ok = 1;
			v[i][3] = '+';
			v[i][4] = '+';
			continue;
		}
	}
	if(ok){
		cout << "YES" << endl;
		for(auto x : v){
			cout << x << endl;
		}
		return 0;
	}
	cout << "NO" << endl;
		
	return 0;
}



