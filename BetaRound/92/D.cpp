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
#include <bits/stdc++.h>
using namespace std;

class SegTree{
private:
	typedef long long Node;
	Node neutral = -INF;
	vector<Node> st;
	vector<int> v;
	int n;
	Node join(Node a, Node b){
		return max(a, b);
	}
	void build(int node, int i, int j){
		if (i == j){
			st[node] = v[i];
			return;
		}
		int m = (i + j) / 2;
		int l = (node << 1);
		int r = l + 1;
		build(l, i, m);
		build(r, m + 1, j);
		st[node] = join(st[l], st[r]);
	}
	Node query(int node, int i, int j, int a, int b){
		if ((i > b) or (j < a))
			return neutral;
		if ((a <= i) and (j <= b))
			return st[node];
		int m = (i + j) / 2;
		int l = (node << 1);
		int r = l + 1;
		return join(query(l, i, m, a, b), query(r, m + 1, j, a, b));
	}
	void update(int node, int i, int j, int idx, Node value){
		if (i == j){
			st[node] = max(st[node], value);
			return;
		}
		int m = (i + j) / 2;
		int l = (node << 1);
		int r = l + 1;
		if (idx <= m)
			update(l, i, m, idx, value);
		else
			update(r, m + 1, j, idx, value);
		st[node] = join(st[l], st[r]);
	}
public:
	template <class MyIterator>
	SegTree(MyIterator begin, MyIterator end){
		n = end - begin;
		v = vector<int>(begin, end);
		st.resize(4 * n + 5);
		build(1, 0, n - 1);
	}
	//0-indexed [a, b]
	Node query(int a, int b){
		return query(1, 0, n - 1, a, b);
	}
	//0-indexed
	void update(int idx, int value){
		update(1, 0, n - 1, idx, value);
	}
};

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	vi v(n);
	vi compression;
	compression.PB(-1);
	compression.PB(0);
	for (int i = 0; i < n; i++){
		cin >> v[i];
		compression.PB(v[i]);
	}
	
	sort(all(compression));
	compression.erase(unique(all(compression)), compression.end());
	
	vi ans;
	vi aux = vi (compression.size()+1, -INF);
	SegTree seg(all(aux));
 	for(int i = n-1; i >= 0; i--){
		int pos = lower_bound(all(compression), v[i]) - compression.begin();
		int q = seg.query(0, pos - 1);
		if(q == -INF){
			ans.PB(-1);
		}else{
			ans.PB(q - i - 1);
		}
		seg.update(pos, i);
	}
	
	reverse(all(ans));
	for(auto x : ans){
		cout << x << " ";
	}
	cout << endl;
	return 0;
}

