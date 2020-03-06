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
	int q;
	cin >> q;
	while(q--){
		ll n;
		cin >> n;
		int count = 0;
		int ok = 1;
		while(n != 1LL){
			if(n % 2 == 0){
				n /= 2;
			}else if(n % 3 == 0){
				n /= 3;
				n *= 2;
			}else if(n % 5 == 0){
				n /= 5;
				n *= 4;
			}else{
				ok = 0;
				break;
			}
			count ++;
		}
		if(ok == 1){
			cout << count << endl;
		}else{
			cout << -1 << endl;
		}
	}
	return 0;
}

