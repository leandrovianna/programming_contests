#include<bits/stdc++.h>

using namespace std;

template<typename T>
bool read( T &n ) { 
    n = 0; 
    register bool neg = false; 
    register char c = getchar_unlocked(); 
    if( c == EOF) { n = -1; return false; } 
    while (!('0' <= c && c <= '9')) { 
        if( c == '-' ) neg = true; 
        c = getchar_unlocked(); 
    } 
    while ('0' <= c && c <= '9') { 
        n = n * 10 + c - '0'; 
        c = getchar_unlocked(); 
    } 
    n = (neg ? (-n) : (n)); 
    return true; 
} 
 
template<typename T>
inline void writeInt(T n){ 
    register int idx = 20; 
    if( n < 0 ) putchar_unlocked('-'); 
    n = abs(n); 
    char out[21]; 
    out[20] = ' '; 
    do{ 
        idx--; 
        out[idx] = n % 10 + '0'; 
        n/= 10; 
    }while(n); 
    do{ putchar_unlocked(out[idx++]); } while (out[idx] != ' '); 
} 

// vendo se passa com uint64_t
typedef uint64_t lint; 

lint x[100005],y[100005];
lint x1[100005],y2[100005], r[105];

bool vis[100005];

int main()
{
	//ios_base::sync_with_stdio(0);
	lint n,m;
	lint a,b,c;

	read(n);

	for(size_t i = 0 ; i < n; i++)
	{
		read(x[i]);
		read(y[i]);
	}

	read(m);

	lint k = 0;
	for(size_t i = 0; i < m; i++)
	{
		read(a);
		read(b);
		read(c);

		if(r[c] != 0 && x1[a] == y2[b] && y2[b] == r[c])
			continue;

		x1[a] = y2[b] = r[c] = k;
		k++;

		for(size_t j = 0; j < n; j++)
		{
			vis[j] |= ( (((x[j] - a)  * (x[j] - a)) + ((y[j] - b) * (y[j] - b)))  <=  (c*c) );

			// o trecho a seguir foi responsavel por TLE
			// if (vis[j]) continue;
			// if ( (((x[j] - a)  * (x[j] - a)) + ((y[j] - b) * (y[j] - b)))  <=  (c*c) )
			// 	vis[j] = true;
		}
	}

	lint ans = 0;
	
	for(size_t i = 0; i < n; i++)
	{
		if (!vis[i])
			ans++;
	}

	writeInt(ans);
	putchar_unlocked('\n');

	return 0;
}
