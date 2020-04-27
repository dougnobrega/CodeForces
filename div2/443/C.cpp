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

int mapper[1000];
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> cards;
	for (int i = 0; i < n; i++){
		string s;
		cin >> s;
		if(s[0] == 'R') s[0] = '1';
		if(s[0] == 'G') s[0] = '2';
		if(s[0] == 'B') s[0] = '3';
		if(s[0] == 'Y') s[0] = '4';
		if(s[0] == 'W') s[0] = '5';
		cards.PB((1 << 5 << (s[0] - '1')) | (1 << (s[1] - '1')));
	}
	
	int answer = 10;
	for(int maskValue = 0; maskValue < (1 << 5); maskValue++){		
		for(int maskColor = 0; maskColor < (1 << 5); maskColor++){
			map<int,set<int> > groups; 
			
			int possible = 1;
			for (int i = 0; i < n; i++){
				groups[cards[i] & ((maskColor << 5) | maskValue)].insert(cards[i]);
				if(groups[cards[i] & ((maskColor << 5) | maskValue)].size() > 1) possible = 0;
			}
			
			if(possible) answer = min(answer, __builtin_popcount(maskColor) + __builtin_popcount(maskValue));
		}
	}
	
	cout << answer << endl;
	return 0;
}






