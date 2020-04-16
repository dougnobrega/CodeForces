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
ll v[100010][6];
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++){
		for(int j = 0; j < m;j++){
			cin >> v[i][j];
		}
	}
	
	int i = 0, j = 0; ll acc = 0, best = 0, sz = 0;
	vll ans(m,0), atual(m,0);
	multiset<ll> elements[6];
	while(j < n){
		if(acc > k){
			for (int p = 0; p < m; p++){
				elements[p].erase(elements[p].find(v[i][p]));
				atual[p] = 0;
			}
			
			acc = 0;
			
			for (int p = 0; p < m; p++){
				if((int)elements[p].size() > 0){
					atual[p] = *elements[p].rbegin();
					acc += atual[p];
				}
			}
			i++;
			sz--;
		}else{
			if(sz > best){
				ans = atual;
				best = sz;
			}
			acc = 0;
			for (int p = 0; p < m; p++){
				elements[p].insert(v[j][p]);
				atual[p] = *elements[p].rbegin();
				acc += atual[p];
			}
			sz++;
			j++;
		}
	}
	if(acc <= k){
		if(sz > best){
			ans = atual;
			best = sz;
		}
	}
	for (int p = 0; p < m; p++){
		cout << ans[p] << " ";
	}
	cout << endl;
	
	return 0;
}
