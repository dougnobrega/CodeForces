#include <bits/stdc++.h>

using namespace std;

// Prioridade
typedef long long   ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpi;

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
string s,t;
int dp[110][110];
int lcs(int i,int j){
	if(i == 0 || j == 0){
		return 0;
	}
	if(dp[i][j] != -1){
		return dp[i][j];
	}
	int inc = (s[i-1] == t[j-1]);
	return dp[i][j] = max(lcs(i-1,j),max(lcs(i,j-1),inc + lcs(i-1,j-1)));
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> s >> t;
	vi count(27,0);
	REP(i,0,s.size()){
		count[s[i] - 'a']++;
	}
	REP(i,0,t.size()){
		count[t[i] - 'a']--;
	}
	int ok = 0;
	int ok2 = 0;
	memset(dp,-1,sizeof dp);
	REP(i,0,26){
		if(count[i] != 0)
			ok = 1;
		if(count[i] < 0){
			ok2 = 1;
		}
	}
	if(lcs(s.size(),t.size()) == t.size()){
		cout << "automaton" << endl;
		return 0;
	}
	if(s.size() == t.size() && ok == 0 && ok2 == 0){
		cout << "array" << endl;
	}else if(ok2 == 0){
		cout << "both" << endl;
	}else{
		cout << "need tree" << endl;
	}
	return 0;
}
