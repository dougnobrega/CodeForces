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
int countt[10];
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string s;
	cin >> s;
	
	vi v = {1,6,8,9};
	
	string aux;
	for(auto c : s){
		int ok = 1;

		for(auto x : v){
			if(x == c - '0' and countt[x] == 0){
				countt[x] = 1;
				ok = 0;
				break;
			}
		}
		if(ok) aux += c;
	}
	
	sort(all(aux));
	reverse(all(aux));
	
	ll r = 0;
	
	for(auto c : aux){
		r = (10*r + (c - '0'))%7;
	}
	
	r = (r * 10 *10 *10 *10)%7;
	
	do{
		ll acc = 0;
		
		for(auto x : v){
			acc = (acc*10 + x)%7;
		}
		
		if((r + acc)%7 == 0){

			if(aux.size() > 0 and aux[0] != '0') cout << aux;
			
			for(auto x : v) cout << x;
			
			if(aux.size() > 0 and aux[0] == '0') cout << aux;
			
			cout << endl;
		
			return 0;
		}
		
	}while(next_permutation(all(v)));
	
	cout << 0 << endl;
	return 0;
}


