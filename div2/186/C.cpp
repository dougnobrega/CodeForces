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
struct m{
	pll x = {3, 1};
	pll y = {1, 3};
	m(){
		
	}
	m(string i){
		x = {1, 0};
		y = {0, 1};
	}
	
    inline m operator*(m a) {
        m res;
        res.x = {x.F * a.x.F + x.S * a.y.F, x.F * a.x.S + x.S * a.y.S};
        res.y = {y.F * a.x.F + y.S * a.y.F, y.F * a.x.S + y.S * a.y.S};
        res.x.F %= MOD;
        res.x.S %= MOD;
        res.y.F %= MOD;
        res.y.S %= MOD; 
        return res;
    }
};
m fast_exp(ll exp){
	if(exp == 0) return m("Identity");
	if(exp & 1) return m() * (fast_exp(exp - 1));
	m x = fast_exp(exp / 2);
	return x * x;
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	ll n;
	cin >> n;
	m res = fast_exp(n);
	cout << res.x.F << endl;
	return 0;
}





