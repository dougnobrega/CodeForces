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
#define MOD 1000000009
#define endl '\n'
#define mdc(a, b) (__gcd((a), (b)))
#define mmc(a, b) (((a)/__gcd(a, b)) * b)
#define W(x) cerr << "\033[31m"<<  #x << " = " << x << "\033[0m" << endl;
// fim da Prioridade

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	vi p1(n);
	vi p2(n);
	
	for(int i = 0; i < n; i++){
		cin >> p1[i];
	}
	vi idx(n+1);
	for(int i = 0; i < n; i++){
		cin >> p2[i];
		idx[p2[i]] = i;
	}
	int ans = n-1;
	for (int i = 1; i < n; i++){
		if(idx[p1[i]] <= idx[p1[i-1]]){
			break;
		}
		ans--;	
	}
	cout << ans << endl;
	
	
	return 0;	
}

