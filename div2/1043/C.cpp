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
	string s;
	cin >> s;
	vi ind(s.size());
	string aux = s;
	for (int i = 0; i < (int)s.size()-1; i++){
		if(s[i] == 'b' and s[i+1] == 'a'){
			ind[i] = 1;
			reverse(aux.begin(), aux.begin()+i+1);
		}else if(s[i] == 'a' and s[i+1] == 'b'){
			ind[i] = 1;
			reverse(aux.begin(), aux.begin()+i+1);
		}else{
			ind[i] = 0;
		}
	}
	if(s.back() == 'a'){
		ind[s.size() -1 ] = 1;
		reverse(all(aux));
	}
	for(int x : ind){
		cout << x << " ";
	}
	cout << endl;
	return 0;
}
