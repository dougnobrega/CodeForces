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
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		sort(all(s));
		if(s[0] != s[k-1]){
			cout << s[k-1] << endl;
			continue;
		}
		cout << s[0];
		if(s[k] != s[n-1]){
			for (int i = k; i < n ; i++){
				cout << s[i];
			}
			cout << endl;
			continue;
		}
		for(int i = k; i < n ; i++){
			if(i%k == 0){
				cout << s[i];
			}
		}
		cout << endl;
		
	}
	return 0;
}

