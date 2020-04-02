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
	string s;
	int n;
	cin >> n;
	cin >> s;
	int ans = 0;
	while(true){
		int letter = 'a' - 1;
		int idx = -1;
		for (int i = 0; i < (int)s.size(); i++){
			int a1 = i - 1 , a2 = i + 1;
			if(a1 >= 0){
				if(s[i] == s[a1] + 1){
					if(s[i] > letter){
						idx  = i;
						letter = s[i];
					}
				}
			}
			if(a2 < (int)s.size()){
				if(s[i] == s[a2] + 1){
					if(s[i] > letter){
						idx  = i;
						letter = s[i];
					}
				}
			}
		}
		if(idx == -1) break;
		string aux;
		for (int i = 0; i < (int)s.size(); i++){
			if(i == idx) continue;
			aux += s[i];
		}
		swap(s, aux);
		ans++;
	}
	cout << ans << endl;
	
	return 0;
}

