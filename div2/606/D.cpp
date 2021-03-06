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
	int n, m;
	cin >> n >> m;
	vector<pair<pii, int> > edges;
	for(int i = 0; i < m; i++){
		int w, putted;
		cin >> w >> putted;
		edges.PB({{w, !putted}, i});
	}
	sort(all(edges));
	vpi ans(m);
	int from = 2, to = 3;
	int last = 2;
	for (int i = 0; i < m; i++){
		if(edges[i].F.S == 0){
			ans[edges[i].S] = {1, last};
			last++;
		}else{
			ans[edges[i].S] = {from, to};	
			from++;
			if(to >= last){
				cout << "-1" << endl;
				return 0;
			}
			if(from == to){
				from = 2;
				to++;
			}
		}
	}
	
	for(auto x : ans){
		cout << x.F << " " << x.S << endl;
	}
	
	return 0;
}

