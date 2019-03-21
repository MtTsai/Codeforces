#include <bits/stdc++.h>                                                                                                                                                                                      //YaLoh

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)1e6 + 123, M = 12, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int n, m, pp[N], cnt[1 << M], gg[1 << M];
ll ans, k, g, a[N], b[N], c[M], val[1 << M], dp[M][1 << M], tmp[M][1 << M];
vector< ll > p, v[N]; 
map<int, int> mt;

bool cmp(int i, int j){
	return b[i] < b[j];
}
int main()
{            

	scanf("%d%lld", &n, &k);
	for(int i = 0; i < n; i++)
		scanf("%lld", &a[i]); // uncertainty
	for(int i = 0; i < n; i++)
		scanf("%lld", &b[i]); // experience;
	for(int i = 0; i < n; i++)
		pp[i] = i;
	sort(pp, pp + n, cmp); // sort experience, store its idx
	
	for(int i = 0; i < n; i++)
		g = __gcd(g, a[i]);
    // g = gcd ( a[0.....n])

    for(int i = 2; 1ll * i * i <= g; i++)
		if(g % i == 0){
			while(g % i == 0)
				g /= i;
			p.pb(i);                      	
		}
	if(1 < g)
		p.pb(g);
	m = p.size();
    // p store all prime
    // m is the num of kind of prime
	if(m == 0){
		printf("0");
		return 0;
	}	

    // i: prime idx
    // j: 2 ^ m => bitmask?
	for(int i = 0; i <= m; i++)
		for(int j = 0; j < (1 << m); j++)
			tmp[i][j] = dp[i][j] = INF;
	tmp[0][0] = dp[0][0] = 0;                    
	ans = INF;

    // i: 2 ^ m => bitmask?
    // j: prime idx
	for(int i = 1; i < (1 << m); i++)
		for(int j = 0; j < m; j++)
			if((i >> j) & 1)
				gg[i] = j;
    // gg[i] means the max prime idx

    // traverse all element
	for(int q = 0; q < n; q++){
		int i = pp[q]; // get the idx with experience from small to big
		ll cur = 1;
		for(int j = 0; j < m; j++){
			c[j] = 1;
			while(a[i] % p[j] == 0)
				a[i] /= p[j], c[j] *= p[j];
			cur *= c[j];
		}	
        // cur  = a[i]
        // c[j] = is the prime j # th power of prime j
        // mt is kind of vis
		if(mt[cur] > m)
			continue;
		mt[cur]++;
		val[0] = 1;
        // traverse all bitmask
		for(int msk = 1; msk < (1 << m); msk++){
            // val means the prod of all prime (with prime #)in msk
			val[msk] = val[msk ^ (1 << gg[msk])] * c[gg[msk]];
            cout << msk << ", " << val[msk] << endl;
			if(val[msk] <= k && cnt[msk] <= m){
				v[i].pb(msk);
	            cnt[msk]++;
			}
		}                    

        // dp [how much judge involves] [ cover msk ]
		for(int x = m - 1; x >= 0; x--)
			for(auto msk : v[i])
				for(int it = 0; it < (1 << m); it++)
					dp[x + 1][msk | it] = min(dp[x + 1][msk | it], dp[x][it] + b[i]);
	}
	for(int x = 1; x <= m; x++)
		if(dp[x][(1 << m) - 1] != INF)
        	ans = min(ans, x * dp[x][(1 << m) - 1]);
	
	if(ans == INF)
		ans = -1;
	
	printf("%lld", ans);
	return 0;
}
