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
ll n, k;
double l, v1, v2;

int check(double t){
	double newDist = l - v1 * t;
	if(newDist <= 0.0) return 1;
	double busTime = newDist/(v2 - v1);
	double cover = newDist/(v2 + v1);
	double groups = (n + k - 1)/k;
	double timetaken = groups * busTime + (groups - 1) * cover;
	return (timetaken<=t);
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
		
	cin >> n >> l >> v1 >> v2 >> k;

	double lo = 0, hi = 1e18, mid;
	for (int i = 0; i <= 200; i++){
		mid = (lo + hi)/2.0;
		if(check(mid)) hi = mid;
		else lo = mid;
	}
	
	cout << setprecision(8) << fixed <<  lo << endl;
	
	return 0;
}
