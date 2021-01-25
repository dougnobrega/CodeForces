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
	
	int a, b;
	cin >> a >> b;
	string ans;
	int ones = 0;
	int ok = 0;
	while(a + b > 0){
		if(a < b){
			if(ones == 2){
				ans += '0';
				ones = 0;
				ok = 1;
				a--;
			}else{
				ans += '1';
				ones++;
				ok = 0;
				b--;
			}
		}else if(a > b){
			if(a - b > 1){
				cout << -1 << endl;
				return 0;
			}
			ok = 1;
			ones = 0;
			ans += '0';
			a--;
		}else{
			if(ok){
				while(a != 0){
					ans += '1';
					ans += '0';
					a--;
					b--;
				}
			}else{
				while(a != 0){
					ans += '0';
					ans += '1';
					a--;
					b--;
				}
			}
		}
	}
	if(a < 0 or b < 0){
			cout << -1 << endl;
			return 0;
		}
	cout << ans << endl;
	return 0;
}





