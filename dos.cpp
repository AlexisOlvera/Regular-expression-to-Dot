#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (lli i = 0; i < lli(n); i++)
#define FOR(i,a,n) for(lli i =a; i < n; i++)
#define FORd(i,a) for (lli i = (a)-1; i >= 0; i--)
#define pb push_back
#define fi first
#define se second
#define __ ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long int unsigned lli;
typedef long long int llim;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<lli> vlli;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
 
vector<int> primes;
vector<bool> isPrime;
void primesSieve(int n){
	isPrime.resize(n + 1, true);
	isPrime[0] = isPrime[1] = false;
	primes.push_back(2);
	for(int i = 4; i <= n; i += 2) isPrime[i] = false;
	int limit = sqrt(n);
	for(int i = 3; i <= n; i += 2){
		if(isPrime[i]){
			primes.push_back(i);
			if(i <= limit)
				for(int j = i * i; j <= n; j += 2 * i)
					isPrime[j] = false;
		}
	}
}

vi a; 

lli count(llim m){ 
    llim res=0;
    lli counter, i, j, p = 1; 
    lli pow_set_size = (1 << a.size()); 
    for (counter = 1; counter < pow_set_size; counter++){ 
        p = 1; 
        for (j = 0; j < a.size(); j++){  
            if (counter & (1 << j)){ 
                p *= a[j]; 
            } 
        } 
        if (__builtin_popcount(counter) & 1) 
            res += ( m / p ); 
        else
            res -= ( m / p ); 
    } 
  
    return res;
} 
 
int main() {
	int t, k;
	cin>>t;
	primesSieve(1000005);
	forn(i, t){
	    lli m;
	    int aux;
	    cin>>m;
	    cin>>k;
	    forn(j, k){
	    	cin>>aux;
	    	a.pb(aux);
	    }
		int l=0;
		while(primes[l]<=m)
			l++;
		if(l>0)
			l++;
		cout << m - count(m) - l + k<<endl;
		a.clear();	
	} 
    return 0; 
} 