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
	int a, b, c;
	cin >> a >> b >> c;
	int x, y, z;
	cin >> x >> y >> z;
	int ra = a - x, rb = b - y, rc = c - z;
	while(rb < 0){
		if(ra >= 2){
			ra -= 2;
			rb++;
		}else if(rc >= 2){
			rc -= 2;
			rb++;
		}else{
			cout << "NO" << endl;
			return 0;
		}
	}
	while(ra < 0){
		if(rb >= 2){
			rb -= 2;
			ra++;
		}else if(rc >= 2){
			rc -= 2;
			ra++;
		}else{
			cout << "NO" << endl;
			return 0;
		}
	}
	while(rc < 0){
		if(ra >= 2){
			ra -= 2;
			rc++;
		}else if(rb >= 2){
			rb -= 2;
			rc++;
		}else{
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}

