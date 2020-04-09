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
int dp[100020];
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	vi v(n);
	vpi index(n);
	for (int i = 0; i < n; i++){
		cin >> v[i];
		index[i] = {v[i],i};
	}
	sort(all(index));
	reverse(all(index));
	for(int i = 0; i < n; i++){
		int val = index[i].F; // (j - idx) %val == 0
		int idx = index[i].S;
		for (int j = idx + val; j < n; j += val){
			if(v[j] > val) dp[idx] |= !dp[j];
		}
		for (int j = idx - val; j >= 0 ; j -= val){
			if(v[j] > val) dp[idx] |= !dp[j];
		}
	}
	for (int i = 0; i < n; i++){
		cout << (dp[i] ? 'A': 'B');
	}
	cout << endl;
	
	return 0;
}
