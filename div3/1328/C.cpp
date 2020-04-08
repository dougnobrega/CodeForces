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
	int t;
	cin >> t;
	while(t--){
		int n;
		string s;
		cin >> n >> s;
		string a, b;
		int ok = 0;
		for(auto x : s){
			if(ok == 0){
				if(x == '0'){
					if(a.size() > 0){
						a += '0';
						b += '0';
						continue;
					}
					a += '1';
					b += '2';
					ok = 1;
				}else if(x == '1'){
					if(a.size() > 0){
						a += '0';
						b += '1';
						ok = 1;
					}else{
						a += '2';
						b += '2';
					}
				}else{
					a += '1';
					b += '1';
				}
			}else{
				a += x;
				b += '0';
			}
		}
		cout << a << endl;
		cout << b << endl;
	}
	return 0;
}


