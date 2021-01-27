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
class SegTreeIterative{
private:
  typedef pii Node;
  Node neutral = {-1, -1};
  vector<Node> st;
  int n;
  inline Node join(Node a, Node b){
	return max(a, b);
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

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vi v(n+1);
		v[n] = -1;
		vpi sweep;
		for (int i = 0; i < n; i++){
			cin >> v[i];
			sweep.PB({v[i],i});
		}
		vpi hehe(n+1, {0,n});
		SegTreeIterative st(all(hehe));
		SegTreeIterative st2(all(sweep));

		sort(all(sweep));
		reverse(all(sweep));
		
		
		vi dp(n+1, 0);
		int ans = 0;
		for(auto [value, i] : sweep){
			pii p = st.query(i+1, n);
			dp[i] = 1 + p.F;
			if(st2.query(i+1, p.S - 1).F >= value) dp[i]++;
			ans = max(ans, dp[i] + (st2.query(0, i-1).F >= value));
			st.update(i, {dp[i], i});
		}
		
		cout << ans << endl;
	}
	return 0;
}


