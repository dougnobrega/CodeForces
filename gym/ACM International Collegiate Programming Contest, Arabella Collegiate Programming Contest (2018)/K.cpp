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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	
	deque <int> cyclic;
	while(t--){
		int n;
		cin >> n;
		string a, b;
		cin >> a >> b;
		vi ind(n,-1);
		cyclic.clear();
		for (int i = 0; i < n; i++){
			if(a[i] != b[i]){
				cyclic.PB(i);
				continue;
			}
			ind[i] = i;
		}
		cyclic.push_front(cyclic.back());
		cyclic.pop_back();
		for (int i = 0; i < n; i++){
			if(ind[i] == -1){
				ind[i] = cyclic.front();
				cyclic.pop_front();
			}
		}
		int ok = 1;
		for (int i = 0; i < n; i++){
			if(a[i] != b[ind[i]]) ok = 0;
		}
		if(ok){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
		
	}
	return 0;
}

