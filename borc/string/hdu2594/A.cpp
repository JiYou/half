#include <bits/stdc++.h>
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
#define F first
#define S second
#define lson (o<<1),l,mid
#define rson (o<<1|1),mid+1,r
#define MP make_pair
const double eps = 1e-9 ;
const int inf = 0x3f3f3f3f ;
const ll INF = (ll)1e18 ;

const int M = 50000+10 ;
char s[2*M] , t[M] ;
int lens , lent ;
int len ;
int nxt[2*M] ;

void get_nxt () {
	nxt[0] = -1 ;
	for (int i = 1 , j = -1 ; i < len ; i ++) {
		while (j!=-1 && s[i]!=s[j+1]) j=nxt[j] ;
		nxt[i] = s[i]==s[j+1]?++j:-1 ;
	}
}

int main () {
	while (~ scanf ("%s%s" , s , t)) {
		lens = strlen(s) ;
		lent = strlen(t) ;
		len = lens+lent ;
		strcat (s , t) ;
		get_nxt () ;
		int j = nxt[len-1] ;
		while (j != -1) {
			if (j+1<=lens&&j+1<=lent) {
				for (int i = 0 ; i <= j ; i ++) 
					printf ("%c" , s[i]) ;
				printf (" %d\n" , j+1) ;
				break ;
			}
			j = nxt[j] ;
		}
		if (j==-1) puts ("0") ;
	}
	return 0 ;
}
