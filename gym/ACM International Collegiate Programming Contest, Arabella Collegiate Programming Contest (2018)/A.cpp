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

vll getSpecialNumbers(ll n){
	int negative = n < 0;
	if(negative) n = abs(n);
	string s = to_string(n);
	reverse(all(s));
	vll num;
	ll pot = 1;
	for (int i = 0; i < s.size(); i++){
		if(s[i] != '0')
			num.PB((s[i]-'0') * pot);
		pot *= 10LL;
	}
	for (int i = 0; i < num.size(); i++){
		if(negative) num[i] = -num[i];
	}
	return num;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		ll a, b;
		cin >> a >> b;
		vll A = getSpecialNumbers(a);
		vll B = getSpecialNumbers(b);
		for (int i = 0; i < A.size(); i++){
			for (int j = 0; j < B.size() ; j++){
				if(i != 0 || j != 0 ) cout << " + "; 
				cout << A[i] << " x " << B[j];
			}
		}
		cout << endl;
		
	}
	return 0;
}

