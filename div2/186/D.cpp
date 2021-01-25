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
double a, b, c;
double pot(double e, double p){
	if(p == 0) return 1.0;
	return pow(e, p);
}

struct point{
	double x, y, z;
	point(double x_, double y_, double z_){
		x = x_;
		y = y_;
		z = z_;
	}
	point(){
	}
	
	double ans(){
		//double sum;
		return a*log(x) + b*log(y) + c*log(z);
	}
};

double s;


point ternaryY(double x){
	double lo = 0, hi = s, m1, m2;
	for(int i = 0; i < 500; i++){
		m1 = (2.0*lo + hi)/3.0;
		m2 = (lo + 2.0*hi)/3.0;
		point p1 = point(x, m1, s - x - m1), p2 = point(x, m2, s - x - m2);
		if(p1.ans() < p2.ans()){
			lo = m1;
		}else{
			hi = m2;
		}
	}
	m1 = (lo + hi)/2.0;
	return point(x, m1, s - x - m1) ;
}

point getAnswer(){
	double lo = 0, hi = s, m1, m2;
	for(int i = 0; i < 500; i++){
		m1 = (2.0*lo + hi)/3.0;
		m2 = (lo + 2.0*hi)/3.0;
		point p1 = ternaryY(m1), p2 = ternaryY(m2);
		
		if(p1.ans() < p2.ans()){
			lo = m1;
		}else{
			hi = m2;
		}
	}
	m1 = (lo + hi) / 2.0;
	return ternaryY(m1);
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	cin >> s;
	cin >> a >> b >> c;
	
	point ans = getAnswer();
	cout << setprecision(12) << fixed << ans.x << " " << ans.y << " " << ans.z << endl;
	return 0;
}





