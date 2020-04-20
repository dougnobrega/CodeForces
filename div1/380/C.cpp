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
struct no{
	int open = 0;
	int close = 0;
	int answer = 0;
	no(){
	}
	no(int o, int c, int a){
		open = o;
		close = c;
		answer = a;
	}
};
class SegTree{
private:
	typedef no Node;
	Node neutral = no();
	vector<Node> st;
	vector<int> v;
	int n;
	Node join(Node a, Node b){
		no c = no(a.open, b.close, a.answer + b.answer);
		int val = b.open - a.close;
		c.answer += 2*min(b.open, a.close);
		if(val > 0){
			c.open += val;
		}else{
			c.close -= val;
		}
		return c;
	}
	void build(int node, int i, int j){
		if (i == j){
			no c = no();
			if(v[i] == 1){
				c.close = 1;
			}else{
				c.open = 1;
			}
			st[node] = c;
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
			st[node] = value;
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
		no c = no();
		if(value == 1){
			c.close = 1;
		}else{
			c.open = 1;
		}
		update(1, 0, n - 1, idx, c);
	}
};
int main(){
	string s;
	cin >> s;
	vi v;
	for(auto c : s){
		v.PB(c == '(');
	}
	SegTree seg(all(v));
	int m;
	cin >> m;
	for (int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		x--, y--;
		cout << seg.query(x, y).answer << endl;
	}
	
}
	
