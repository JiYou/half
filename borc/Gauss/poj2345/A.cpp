#include <stdio.h>
#include <numeric>
#include <time.h>
#include <bitset>
#include <string.h>
#include <stack>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <math.h>
#include <queue>
#include <complex>
#include <functional>
#include <limits.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef unsigned long long ull ;
#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#define pi (acos(-1.0))
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define lson (o<<1),l,mid
#define rson (o<<1|1),mid+1,r
#define MP make_pair
#define sqr(x) ((x)*(x))
#define ALL(v) (v).begin(),(v).end()
#define showtime fprintf(stderr,"time = %.15f\n",clock() / (double)CLOCKS_PER_SEC)
const double eps = 1e-9 ;
const int inf = 0x3f3f3f3f ;
const ll INF = (ll)4e18 ;
const int MOD=(int)1e9+7,BAS=233;
inline int sign(double x){return x<-eps?-1:x>eps;}
inline int clz(int x){return __builtin_clz(x);}
inline int clz(ll x){return __builtin_clzll(x);}
inline int lg2(int x){return !x ? -1 : 31-clz(x);}
inline int lg2(ll x){return !x ? -1 : 63-clz(x);}
int AP (char *s) {
	unsigned hash=0;
	for(int i=0; s[i]; i++){
		if (i & 1) hash ^= (~((hash<<11)^s[i]^(hash>>5)));
		else hash ^= ((hash<<7)^s[i]^(hash>>3));
   } return hash & 0x7FFFFFFF;
}
 
const int M = 255;
bitset<M> a[M];
int n;

int Gauss (int equ,int var) {
	int i,j,k,col,max_r;
	//beg
	//for (i=0; i<equ; i++) {
	//	for (j=0; j<var+1; j++) {
	//		printf ("%d ", a[i].test(j));
	//	} puts("");
	//} puts("");
	//end;

	for (k=col=0; k<equ && col<var; k++, col++) {
		for (max_r=k,i=k; i<equ; i++) if (a[i].test(col)) {
			max_r=i; break;
		}
		if (max_r!=k) swap(a[max_r], a[k]);
		if (a[k].test(col)==false) {
			k--; continue;
		}
		for (i=k+1; i<equ; i++) if (a[i].test(col)) {
			a[i] = a[i]^a[k];
		}
	}

	for (i=k; i<equ; i++) if (a[i].test(col)) {
		return -1;
	}

	//beg
	//for (i=0; i<equ; i++) {
	//	for (j=0; j<var+1; j++) {
	//		printf ("%d ", a[i].test(j));
	//	} puts("");
	//} puts("");
	//end;

	while (var!=k);
	bitset<M> x;
	x.reset();
	int lst=-1;
	for (i=k-1; i>=0; i--) {
		for (j=i+1; j<var; j++) if (a[i].test(j) && x[j]) {
			a[i].flip(n);
		}
		x[i] = a[i][n];
		if (x.test(i) && lst==-1) lst=i;
	}
	for (i=0; i<n; i++) if (x.test(i)) {
		printf ("%d%c", i+1, " \n"[i==lst]);
	} 
	return var-k;
}

int main () {
	while (~scanf ("%d", &n)) {
		for (int i=0; i<n; i++) a[i].reset();
		for (int i=0,x; i<n; i++) {
			a[i].set(n);
			while (~scanf("%d",&x) && x!=-1) {
				a[--x].set(i);
			}
		}
		int ans = Gauss (n, n);
		if (ans==-1) puts ("No solution");
	}
	return 0;
}