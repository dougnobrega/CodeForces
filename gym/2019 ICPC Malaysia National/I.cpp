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
string getAnswer(string a){
	int p = -1;
	for (int i = 0; i < a.size(); i++){
		if(a[i] == '=') p = i;
	}
	if(p == -1) return "";
	for (int i = p+1; i < a.size() ; i++){
		if(a[i] != '.') return a.substr(i,1);
	}
	
	return "You shall pass!!!";
	
}
	
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	while(cin >> s && getAnswer(s) == "");
	cout << getAnswer(s) << endl;
	return 0;
}

