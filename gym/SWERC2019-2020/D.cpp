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
map<pii,int> piiToIndex;
map<int,pii> indexToPii;
int getIndex(int left, int right){
	if(!piiToIndex.count({left,right})){
		piiToIndex[{left,right}] = piiToIndex.size() + 1e5;
		indexToPii[piiToIndex[{left,right}]] = {left,right};
	}
	return piiToIndex[{left, right}];
}

pii getPii(int index){
	if(!indexToPii.count(index)){
		return {-1,-1};
	}
	return indexToPii[index];
}

inline vi getDNA(string & s){
	vi ans; 
	for(int i = 0; i < 10000; i++){
		ans.PB(i);
	}
	pii pair;
	int left, right, front;
	for(char c : s){
		switch (c){
			case 'C':
				front = ans.back();
				ans.push_back(front);
				break;
			case 'D':
				ans.pop_back();
				break;
			case 'P':
				left = ans.back();
				ans.pop_back();
				right = ans.back();
				ans.pop_back();
				ans.push_back(getIndex(left, right));
				break;
			case 'S':
				swap(ans[ans.size()-1],ans[ans.size()-2]);
				break;
			case 'U':
				front = ans.back();
				ans.pop_back();
				pair = getPii(front);
				
				if(pair == MP(-1,-1)){
					return vi();
				}
				ans.push_back(pair.S);
				ans.push_back(pair.F);
				break;
			case 'L':
				front = ans.back();
				pair = getPii(front);
				ans.pop_back();
				if(pair == MP(-1,-1)){
					return vi();
				}
				ans.push_back(pair.F);
				break;
			case  'R':
				front = ans.back();
				pair = getPii(front);
				ans.pop_back();
				if(pair == MP(-1,-1)){
					return vi();
				}
	
				ans.push_back(pair.S);
				break;
		}
	}
	return ans;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string a, b;
	cin >> a >> b;
	vi DNA[2];
	DNA[0] = getDNA(a);
	DNA[1] = getDNA(b);
	int ok = (DNA[0].size() == DNA[1].size());

	if(ok == 1){
		for (int i = 0; i < (int)DNA[0].size(); i++){
			ok &= (DNA[0][i] == DNA[1][i]);
		}
	}
	if(ok){
		cout << "True" << endl;
	}else{
		cout << "False" << endl;
	}
	return 0;
}
