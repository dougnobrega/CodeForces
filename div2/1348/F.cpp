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
#define endl '\n'
#define mdc(a, b) (__gcd((a), (b)))
#define mmc(a, b) (((a)/__gcd(a, b)) * b)
#define W(x) cerr << "\033[31m"<<  #x << " = " << x << "\033[0m" << endl;
// fim da Prioridade
vpll in[200010];
ll where[200010];
ll answer[200010];
class SegTreeIterative{
private:
	typedef pll Node;
	Node neutral = {INF, INF};
	vector<Node> st;
	int n;
	inline Node join(Node a, Node b){
		return min(a, b);
	}
public:
	template <class MyIterator>
	SegTreeIterative(MyIterator begin, MyIterator end){
		int sz = end - begin;
		for (n = 1; n < sz; n <<= 1);
		st.assign(n << 1, neutral);
		for (int i = 0; i < sz; i++, begin++)
			st[i + n] = (*begin);
		for (int i = n + sz - 1; i > 1; i--)
			st[i >> 1] = join(st[i >> 1], st[i]);
	}
	//0-indexed
	void update(int i, Node x){
		st[i += n] = x;
		for (i >>= 1; i; i >>= 1)
			st[i] = join(st[i << 1], st[1 + (i << 1)]);
	}
	//0-indexed [l, r]
	ll query(int l, int r){
		Node ans = neutral;
		for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1){
			if (l & 1)
				ans = join(ans, st[l++]);
			if (r & 1)
				ans = join(ans, st[--r]);
		}
		return ans.S;
	}
};

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	vpll segments(n + 1);
	for (int i = 1; i <= n; i++){
		cin >> segments[i].F >> segments[i].S;
		in[segments[i].F].emplace_back(segments[i].S, i );
	}
	set<pll> active; // right, idx;
	
	for (int i = 1; i <= n ; i++){
		active.insert(all(in[i]));
		answer[active.begin()->second] = i;
		where[i] = active.begin()->second;
		active.erase(active.begin());
	}
	
	vpll v;
	for (int i = 1; i <= n; i++){
		v.emplace_back(segments[where[i]].F, i);
	}
	SegTreeIterative segtree(all(v));
	
	for (int i = 1; i <= n; i++){
		int j = segtree.query(i, segments[where[i]].S - 1);
		if(j == INF) continue;
		if(segments[where[j]].F <= i){
			cout << "NO" << endl;
			for(int k = 1; k <= n; k++){
				cout << answer[k] << " ";
			}
			cout << endl;
			swap(answer[where[i]], answer[where[j]]);
			for(int k = 1; k <= n; k++){
				cout << answer[k] << " ";
			}
			cout << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	for(int j = 1; j <= n; j++){
		cout << answer[j] << " ";
	}
	cout << endl;
	return 0;
}

