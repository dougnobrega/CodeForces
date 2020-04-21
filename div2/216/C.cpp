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

int days_in[1000000];
int days_out[1000000];
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	vi ans;
	for (int i = 0; i < k; i++){
		ans.PB(1);
	}
	for (int i = 0; i*m + i*n <= 10010; i++){
		days_in[1 + i*m + i*n]     += k;
		days_out[1 + i*m + (i+1)*n] += k;
	}
	ll atual = k;
	for (int i = 2; i <= 10010; i++){
		if(atual == days_out[i]){
			atual++;
			ans.PB(i-1);
			for(int j = 0; j*m + j*n <= 10010; j++){
				days_in[i - 1 + j*m + j*n]     += 1;
				days_out[i - 1 + j*m + (j+1)*n] += 1;
			}
		}
		atual += days_in[i];
		atual -= days_out[i];
		if(atual < k){
			int x = k - atual;
			for (int j = 0; j < x; j++){
				ans.PB(i);
			}
			atual+=x;
			for (int j = 0; j*m + j*n  <= 10010; j++){
				days_in[i + j*m + j*n]         += x;
				days_out[i + j*m + (j+1)*n]     -= x;
			}
		}
	}
	cout << ans.size() << endl;
	for(auto c : ans){
		cout << c << " ";
	}
	cout << endl;

	return 0;
}

