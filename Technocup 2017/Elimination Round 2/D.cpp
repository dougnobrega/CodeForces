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
int n, a, b, k;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> a >> b >> k;
	string s;
	cin >> s;
	s += '1';
	int ini = 0;
	vpi segments;
	for (int i = 0; i < (int)s.size(); i++){
		if(s[i] == '1'){
			if(ini != i) segments.emplace_back(ini,i);
			ini = i + 1;
		}
	}
	int ships = 0;
	for(auto seg : segments){
		ships += (seg.S - seg.F)/b;
	}
	
	vi ans;
	for(auto seg : segments){
		while(ships >= a and seg.F + b <= seg.S){
			ships--;
			seg.F += b;
			ans.PB(seg.F-1);
		}
	}
	cout << ans.size() << endl;
	for(auto x : ans) cout << x+1 << " ";
	cout << endl;
	return 0;
}
