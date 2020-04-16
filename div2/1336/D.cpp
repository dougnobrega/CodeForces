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
vll r, g, b;
ll calc(ll x, ll y, ll z){
	ll f = x-y;
	f*=f;
	ll s = y-z;
	s*=s;
	ll t = z-x;
	t*=t;
	return f+s+t;
}

ll solve(){
	sort(all(r));
	sort(all(g));
	sort(all(b));
	ll ans = INFLL;
	int i=0,j=0,k=0; 
	while(1) { 
		vll tmp;
		ans = min(ans, calc(r[i], g[j], b[k]));
		if(i+1 < (int)r.size()) tmp.PB(calc(r[i+1],g[j],b[k]));
		if(j+1 < (int)g.size()) tmp.PB(calc(r[i],g[j+1],b[k]));
		if(k+1 < (int)b.size()) tmp.PB(calc(r[i],g[j],b[k+1]));
		ll best = INFLL;
		for(auto x : tmp) best = min(best,x);
		if(best == INFLL) break;
		if(i+1 < (int)r.size() and best == calc(r[i+1],g[j],b[k])) i++;
		else if(j+1 < (int)g.size() and best == calc(r[i],g[j+1],b[k])) j++;
		else if(k+1 < (int)b.size() and best == calc(r[i],g[j],b[k+1])) k++;
		 
		ans = min(ans, calc(r[i], g[j], b[k])); 
	} 
   

	return ans;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		ll nr, ng, nb;
		cin >> nr >> ng >> nb;
		r.resize(nr);
		for (int i = 0; i < nr; i++){
			cin >> r[i];
		}
		g.resize(ng);
		for (int i = 0; i < ng; i++){
			cin >> g[i];
		}
		b.resize(nb);
		for (int i = 0; i < nb; i++){
			cin >> b[i];
		}
		
		cout << solve()<< endl;
	}
	return 0;
}

