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

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	if(n == 1){
		cout << 1 << endl;
		return 0;
	}else if(n % 4 == 2 or n%4 == 3){
		cout << -1 << endl;
		return 0;
	}else{
		vi ans(n);
		for(int i = 0; i < n/2; i+= 2){
			ans[i] = i + 1;
			ans[i+1] = n - 1 - i;
			ans[n-2-i] = i;
			ans[n-1-i] = n - 2 - i;
		}
		if(n&1) ans[n/2] = n/2;
		for(int x : ans){
			cout << x + 1 << " ";
		}
		cout << endl;
	}
	
	return 0;
}


