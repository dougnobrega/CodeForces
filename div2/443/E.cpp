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

int MAXN = 500005;
vi v(MAXN);
vi prv(MAXN);
vi nxt(MAXN);
vi add(500005);

queue<int> q;

void check(int idx){
	if(add[idx]) return;
	if(v[prv[idx]] >= v[idx] and v[idx] <= v[nxt[idx]]){
		add[idx] = 1;
		q.push(idx);
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);	
	
	int n;
	cin >> n;
	nxt[0] 	= 1;
	prv[n + 1] = n;
	for(int i = 1; i <= n; i++){
		cin >> v[i];
		prv[i] = i - 1;
		nxt[i] = i + 1;
	}
	
	for(int i = 1; i <= n; i++) check(i);
	
	ll ans = 0;
	
	while(!q.empty()){
		int idx = q.front();
		q.pop();
		nxt[prv[idx]] = nxt[idx];
		prv[nxt[idx]] = prv[idx];
		
		ans += min(v[prv[idx]], v[nxt[idx]]);
		
		check(prv[idx]);
		check(nxt[idx]);
	}
	
	int idx = nxt[0];
	
	while(idx != n + 1){
		ans += min(v[prv[idx]], v[nxt[idx]]);
		idx = nxt[idx];
	}
	
	cout << ans << endl;
	return 0;
}


