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
	//1-indexed [l, r]
	t_bit get(int l, int r){
		return get(r) - get(l - 1);
	}
	//1-indexed
	void add(int i, t_bit value){
		for (; i <= nBit; i += (i & -i))
			bit[i] += value;
	}
	t_bit position(t_bit value){
		t_bit sum = 0;
		int pos = 0;
		for (int i = nLog; i >= 0; i--){
			if ((pos + (1 << i) <= nBit) and (sum + bit[pos + (1 << i)] < value)){
				sum += bit[pos + (1 << i)];
				pos += (1 << i);
			}
		}
		return pos + 1;
	}
};
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	Bit smaller(1000003);
	Bit greater(1000003);
	vi compression;
	int n;
	cin >> n;
	vi v(n);
	for (int i = 0; i < n; i++){
		cin >> v[i];
	}
	compression = v;
	compression.PB(-2);
	compression.PB(-1);
	sort(all(compression));
	for(int i = 0; i < n; i++){
		int idx = lower_bound(all(compression), v[i]) - compression.begin();
		v[i] = idx;
	}
	for(int i = n-1; i >= 0; i--){
		smaller.add(v[i], 1); 
	}
	ll ans = 0;
	for (int i = 0; i < n; i++){
		smaller.add(v[i], -1);
		ans += greater.get(v[i], 1000002) * smaller.get(v[i]) ;
		greater.add(v[i], 1);
	}
	cout << ans << endl;
	return 0;
}
