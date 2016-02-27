#include<stdio.h>
#include<string.h>
#include<algorithm>
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

char s[10][66] ;
int nxt[66] ;
int m ;
char t[66] ;
char key[66] ;
int lens , lent ;

void get_nxt (int l , int r) {
	t[r-l] = '\0' ;
	lent = r-l ;
	for (int i = 0 ; l < r ; l ++ , i ++) {
		t[i] = s[0][l] ;
	} 
	nxt[0] = -1 ;
	for (int i = 1 , j = -1 ; i < lent ; i ++) {
		while (j!=-1 && t[i]!=t[j+1]) j=nxt[j] ;
		nxt[i] = s[i]==s[j+1]?++j:-1 ;
	}
}

bool kmp (char *s) {
	for (int i = 0 , j = -1 ; i < 60 ; i ++) {
		while (j!=-1 && s[i]!=t[j+1]) j=nxt[j] ;
		if (s[i]==t[j+1]) {
			j ++ ;
			if (j == lent-1)
				return true ;
		}
	}
	return false ;
}

bool solve () {
		key[0] = '#' ;
		bool flag ;
		for (int i = 60 ; i >= 3 ; i --) {
			for (int j = 0 ; j + i <= 60 ; j ++) {
				get_nxt (j,j+i) ;
				flag = 1 ;
				for (int i = 1 ; i < m ; i ++) {
					flag = kmp (s[i]) ;
					if (!flag) break ;
				}
				if (flag && (key[0]=='#'||strcmp(t,key)<0)) strcpy(key,t) ;
			}
			if (key[0]!='#') return true ;
		}
		return false ;
}

int main () {
	int T ;
	scanf ("%d" , &T) ;
	while (T --) {
		scanf ("%d" , &m) ;
		for (int i = 0 ; i < m ; i ++) {
			scanf ("%s" , s[i]) ;
		}
		if (solve()) puts (key) ;
		else puts ("no significant commonalities") ;
	}
	return 0 ;
}
