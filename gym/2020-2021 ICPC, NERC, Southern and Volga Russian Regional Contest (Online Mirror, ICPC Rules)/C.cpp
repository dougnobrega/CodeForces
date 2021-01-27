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
#include <bits/stdc++.h>
using namespace std;
class SegTreeIterative{
private:
  typedef pii Node;
  Node neutral = {-1, -1};
  vector<Node> st;
  int n;
  inline Node join(Node a, Node b){
    if(a.F == b.F) return (a.S < b.S) ? a : b;
    return (a.F < b.F) ? b : a;
  }
public:
  template <class MyIterator>
  SegTreeIterative(MyIterator begin, MyIterator end){
    int sz = end - begin;
    for (n = 1; n < sz; n <<= 1);
    st.assign(n << 1, neutral);
    for (int i = 0; i < sz; i++, begin++)
      st[i + n] = (*begin);
    for (int i = n - 1; i; i--){
      st[i] = join(st[(i << 1)], st[(i << 1) + 1]);
    }
  }
  //0-indexed
  void update(int i, Node x){
    st[i += n] = x;
    for (i >>= 1; i; i >>= 1)
      st[i] = join(st[i << 1], st[(i << 1) + 1]);
  }
  //0-indexed [l, r]
  Node query(int l, int r){
    Node ansL = neutral, ansR = neutral;
    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1){
      if (l & 1)
        ansL = join(ansL, st[l++]);
      if (r & 1)
        ansR = join(st[--r], ansR);
    }
    return join(ansL, ansR);
  }
};
int vis[500100];
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int q;
	cin >> q;
	
	vi v;
	vpi hehe(q + 2, {-1,-1});
	SegTreeIterative st(all(hehe));
	int sz = 0;
	int i = 0;
	vi ans;
	while(q--){
		int op;
		cin >> op;
		if(op == 1){
			int m;
			cin >> m;
			v.PB(m);
			st.update(sz, {m, sz});
			sz++;
		}else if(op == 2){
			while(i < sz and vis[i]){
				i++;
			}
			vis[i] = 1;
			ans.PB(i);
			st.update(i, {-1,-1});
		}else if(op == 3){
			pii x = st.query(0, sz);
			st.update(x.S, {-1,-1});
			ans.PB(x.S);
			vis[x.S] = 1;
		}
	}	
	for(auto x : ans){
		cout << x + 1 << " ";
	}
	cout << endl;
	return 0;
}


