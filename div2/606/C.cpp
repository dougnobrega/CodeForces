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
int pos[200000];
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	ll n;
	cin >> n;
	vll cars(n);
	
	int answer = 0;
	for (int i = 0; i < n; i++){
		cin >> cars[i];
		pos[cars[i]] = pos[cars[i] - 1] + 1;
		answer = max(answer,pos[cars[i]]);
	}
	cout << n - answer << endl;
	return 0;
}

