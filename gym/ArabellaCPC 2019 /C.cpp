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
	int n;
	cin >> n;
	string ori;
	cin.ignore();
	getline(cin, ori);
	int m;
	cin >> m;
	int caps = 0;
	string ans;
	for(int i = 0; i < m; i++){
		string c;
		cin >> c;
		if(c == "Space"){
			ans += " ";
		}else if(c == "CapsLock"){
			caps = !caps;
		}else if(c == "Backspace"){
			if(ans.size() != 0) ans.pop_back();
		}else{
			if(caps){
				c[0] = toupper(c[0]);
			}
			ans += c;	
		}
	}
	if(ans == ori){
		cout << "Correct" << endl;
	}else{
		cout << "Incorrect" << endl;
	}
	return 0;
}


