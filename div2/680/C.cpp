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
//#define endl '\n'
#define mdc(a, b) (__gcd((a), (b)))
#define mmc(a, b) (((a)/__gcd(a, b)) * b)
#define W(x) cerr << "\033[31m"<<  #x << " = " << x << "\033[0m" << endl;
// fim da Prioridade

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	vi primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
	int count = 0;
	int num = INF;
	for(auto x : primes){
		cout << x << endl;
		string s;
		cin >> s;
		if(s == "yes"){
			count++;
			num = min(num, x);
		}
	}
	if(count >= 2){
		cout << "composite" << endl;
	}else if(count == 1 and num*num <= 100){
		cout << num*num << endl;
		string s;
		cin >> s;
		if(s == "yes"){
			cout << "composite" << endl;
		}else{
			cout << "prime" << endl;
		}
	}else{
		cout << "prime" << endl;
	}
		
	return 0;
}





