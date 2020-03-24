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
	int t;
	cin >> t;
	while(t--){
		vi f(26);
		for (int i = 0; i < 26; i++){
			cin >> f[i];

		}
		int best = 0, ans = INF;		
		for (int i = 0; i < 26; i++){
			if(f[i] >= 2){
				best += 2;
				ans = min(ans,f[i]/2);
			}
		}
		for (int i = 0; i < 26; i++){
			if(f[i] == 1){
				best++;
				int ans2 = 0;
				for (int j = 0; j < 26 ; j++){
					if(f[j] == 1) ans2++;
				}
				ans = min(ans,ans2);
				break;
			}
		}
		if(best == 0) ans = 0;
		cout << best << " " << ans << endl;
		
		
	}
	return 0;
}

