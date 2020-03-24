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
int grau[5];
vi g[5];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s = "ABCDE";
	for (int i = 0; i < 5; i++){
		char a, op, b;
		cin >> a >> op >> b;
		if(op == '>') swap(a,b);
		g[a-'A'].PB(b - 'A');
		grau[b-'A']++;
	}
	queue<int> q;
	for (int i = 0; i < 5; i++){
		if(grau[i] == 0) q.push(i);
	}
	string ans ;
	while(!q.empty()){
		auto t = q.front();
		q.pop();
		ans += char(t + 'A');
		for(auto u : g[t]){
			if(--grau[u] == 0){
				q.push(u);
			}
		}
	}
	if(ans.size() == 5){
		cout << ans << endl;
	}else{
		cout << "impossible" << endl;
	}
	return 0;
}

