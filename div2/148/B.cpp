#include <bits/stdc++.h>

using namespace std;

// Prioridade
typedef long long   ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpi;
typedef vector<pair<ll, ll > > vpll;

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
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	double vp, vd, t, f, c;
	cin >> vp >> vd >> t >> f >> c;
	double dist = t * vp;
	
	ll ans = 0;
	while(dist <= c){
		double tempo = dist/(vd-vp);
		if(tempo < 0)
			break;
		if((dist + tempo*vp) >=c){
			break;
		}
		dist += (tempo*vp + tempo*vp + vp*f);
		ans++;
	}
	cout << ans << endl;
	return 0;
}
