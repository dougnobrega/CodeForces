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
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define all(x) x.begin(),x.end()
#define MOD 1000000007ll
#define endl '\n'
#define mdc(a, b) (__gcd((a), (b)))
#define mmc(a, b) (((a)/__gcd(a, b)) * (b))
#define W(x) cerr << "\033[31m"<<  #x << " = " << x << "\033[0m" << endl;
// fim da Prioridade
int dp2[10010];
int dp3[10010];
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	string s;
	cin >> s;
	dp2[s.size()] = 1;
	dp3[s.size()] = 1;
	if(s.size() - 5 >= 3){
		dp3[s.size() - 3] = 1;
	}
	if(s.size() - 5 >= 2){
		dp2[s.size() - 2] = 1;
	}

	
	set<string> st;
	for(int i = s.size() - 1; i >= 5; i--){
		if((dp2[i + 2] and s.substr(i, 2) != s.substr(i+2, 2)) or dp3[i + 2]){
			dp2[i] = 1;
			st.insert(s.substr(i, 2));
		}
		if(dp2[i + 3] or (dp3[i + 3] and s.substr(i, 3) != s.substr(i+3, 3))){
			dp3[i] = 1;
			st.insert(s.substr(i, 3));
		}
	}
	cout << st.size() << endl;
	for(auto x : st){
		cout << x << endl;
	}
	
	
	
	return 0;
}


