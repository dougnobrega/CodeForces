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
int n, m, w;
vll v(n);	

int check(ll x){
	vll accumulate(3*n);
	
	ll qtd = 0;
	
	for(int i = 0; i < n; i++){
		if(i) accumulate[i] += accumulate[i-1];
		if(v[i] + accumulate[i] < x){
			ll val = x - (accumulate[i] + v[i]);
			qtd += val;
			accumulate[i + w] -= val;
			accumulate[i] += val;
		}
	}
	return m >= qtd;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m >> w;
	v.resize(n);
	
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	
	ll lo = 0, hi = 5ll*INF, mid;
	
	while(lo <= hi){
		mid = (lo + hi)>>1;
		if(check(mid)){
			lo = mid + 1;
		}else{
			hi = mid - 1;
		}
	}
	
	cout << lo - 1 << endl;
	
	return 0;
}
