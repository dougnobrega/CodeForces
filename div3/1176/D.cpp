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
vi primes;
bitset<2750133> b;
int ultimodiv[2750133];
inline void sieve(){
	b[1] = 1;
	for (int i = 2; i <= 2750131; i++){
		for (ll j = i+i; j <= 2750131L; j += i){
			b[j] = 1;
			ultimodiv[j] = max(ultimodiv[j], (int)j/i);
			ultimodiv[j] = max(ultimodiv[j], i); 
		}
	}
	for (int i = 1; i <= 2750131; i++){
		if(!b[i]) primes.PB(i);
	}
	
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	sieve();
	int n;
	cin >> n;
	map<int, int> mapa;
	for (int i = 0; i < 2*n; i++){
		int x;
		cin >> x;
		mapa[x]++;
	}
	
	vll ans;
	for(auto it = mapa.rbegin(); it != mapa.rend(); it++){	
		int aux = it -> second;
		while(aux > 0 && it->F <= 2750131 && b[it->F]){
			mapa[ultimodiv[it->F]] --;
			mapa[it->first] --;
			ans.PB(it->first);
			aux--;
		}
	}
	for(auto it = mapa.rbegin(); it != mapa.rend(); it++){
		if(it->second == 0) continue;
		int pos = lower_bound(all(primes), it->F) - primes.begin();
		int aux = it->second;
		while(aux > 0 && pos < primes.size() && primes[pos] == it->first && mapa[pos+1] > 0){
			mapa[pos+1]--;
			mapa[it->first]--;
			ans.PB(pos+1);
			aux --;
		}
	}
	for(auto x : ans){
		cout << x << " ";
	}
	cout << endl;
	return 0;
}

