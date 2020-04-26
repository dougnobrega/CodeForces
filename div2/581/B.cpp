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
#define MOD 998244353ll
#define endl '\n'
#define mdc(a, b) (__gcd((a), (b)))
#define mmc(a, b) (((a)/__gcd(a, b)) * b)
#define W(x) cerr << "\033[31m"<<  #x << " = " << x << "\033[0m" << endl;
// fim da Prioridade
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	vll v(n);
	for (int i = 0; i < n; i++){
		cin >> v[i];
	}
	stack<int> s;
	for(int i = n-1; i >= 0;i--){
		if(s.empty()){
			s.push(i);
		}else if(v[s.top()] >= v[i]){
			s.push(s.top());
		}else{
			s.push(i);
		}
	}
	for(int i = 0; i < n; i++){
		if(s.top() == i){
			cout << 0 << " ";
		}else{
			cout <<  1 + v[s.top()] - v[i] << " ";
		}
		s.pop();
	}
	cout << endl;
	
	return 0;
}



