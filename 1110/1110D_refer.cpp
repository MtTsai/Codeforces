#include <bits/stdc++.h>
using namespace std;
const int N = 1000001,M = 1000001,inf = 1000000000;
int n,m;
int a[N];
int cnt[M];
int f[M][3][3];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i <= m;i++)cnt[i] = 0;
	for(int i=1;i <= n;i++)scanf("%d",&a[i]),cnt[a[i]]++;
	for(int i=0;i <= 2;i++) for(int j=0;j <= 2;j++) f[0][i][j] = -inf;
	f[0][0][0] = 0;
	for(int i=1;i <= m;i++){
		for(int j=0;j <= 2;j++){
			for(int k=0;k <= 2;k++){
				f[i][j][k] = -inf;
				for(int l=0;l <= 2;l++){
					if(cnt[i] < j + k + l)continue;
					f[i][j][k] = max(f[i][j][k],f[i - 1][l][j] + l + (cnt[i] - j - k - l) / 3);
				}
			}
		}
	}
	printf("%d\n",f[m][0][0]);
	for (int k = 1; k <= m; k++) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d ", f[k][i][j]);
		}
		printf("\n");
	}
		printf("----\n");
	}
	return 0;
}
