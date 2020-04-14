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
class Bit{
private:
	typedef long long t_bit;
	int nBit;
	int nLog;
	vector<t_bit> bit;
public:
	Bit(int n){
		nBit = n;
		nLog = 20;
		bit.resize(nBit + 1, 0);
	}
	//1-indexed
	t_bit get(int i){
		t_bit s = 0;
		for (; i > 0; i -= (i & -i))
			s += bit[i];
		return s;
	}
	//1-indexed
	void add(int i, t_bit value){
		for (; i <= nBit; i += (i & -i))
			bit[i] += value;
	}
};

vi sweepLine_out[400020];

Bit binaryIndexedTree(400020);

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	
	vll compression;
	vll v(n);
	
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	
	for (int i = 0; i < n; i++){
		if(v[i] <= n) sweepLine_out[v[i]].push_back(i + 1);		
		
		binaryIndexedTree.add(i+1, 1);
	}
	
	ll ans = 0;
	for (int i = 1; i <= n; i++){
		int to = min((ll)n, v[i-1]);

		ans += binaryIndexedTree.get(to);

		for(auto season : sweepLine_out[i]){
			binaryIndexedTree.add(season, -1);
		}
	}
	for (int i = 1; i <= n; i++){
		if(i <= v[i-1]) ans--;
	}
	
	cout << ans/2 << endl;
	return 0;
}

