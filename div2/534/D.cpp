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
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	set<pii> students[3];
	for (int i = 0; i < n; i++){
		int x;
		cin >> x;
		students[x%3].insert(MP(x, i));
	}
	vi ans;
	
	int cur = 0; 	
	for (int i = 0; i < n; i++){
		auto it = students[cur%3].lower_bound({cur,-1});
		pii s;
		if(it != students[cur%3].end() and it->F == cur){
			s = *(it);
			ans.PB(it->S);
		}else{
			if(it != students[cur%3].begin()){
				it--;
				s = *(it);
				ans.PB(it->S);
			}else{
				cout << "Impossible" << endl;
				return 0;
			}
		}
		students[cur%3].erase(s);
		cur = s.F + 1;
	}
	cout << "Possible" << endl;
	for(auto c : ans){
		cout << c +1 << " ";
	}
	cout << endl;
	return 0;
}
