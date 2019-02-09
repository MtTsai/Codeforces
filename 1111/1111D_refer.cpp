#include<bits/stdc++.h>
#define dbg(x) cerr<<#x<<" = "<<x<<endl
#define _ <<" "<<
using namespace std;
using ll=long long;

const int MXC=52;
const int MXN=1e5+5;
const int MOD=1e9+7;
int add(int x,int y){return(x+=y)<MOD?x:x-MOD;}
int sub(int x,int y){return(x-=y)>=00?x:x+MOD;}
int mul(int x,int y){return(ll)x*y%MOD;}

char s[MXN];
int fact[MXN];
int invr[MXN];

int sz,ways;
int cnt[MXC];
int sol[MXC][MXC];

int dp[MXN/2];

int get(char c){
  if(islower(c))return c-'a';
  if(isupper(c))return c-'A'+26;
  throw;
}

void update(int cnt){
  if(cnt==0)return;
  for(int i=sz;i>=cnt;--i){
    dp[i]=add(dp[i],dp[i-cnt]);
  }
}

void remove(int cnt){
  if(cnt==0)return;
  for(int i=cnt;i<=sz;++i){
    dp[i]=sub(dp[i],dp[i-cnt]);
  }
}

void init(){
  fact[0]=1;
  fact[1]=invr[1]=1;
  for(int i=2;i<MXN;++i){
    fact[i]=mul(fact[i-1],i);
    invr[i]=mul(MOD-MOD/i,invr[MOD%i]);
  }
  cin>>s;
  sz=strlen(s)/2;
  ways=mul(fact[sz],fact[sz]);
  // cout << ways << endl;;
  for(int i=0;s[i];++i){
    int enu=get(s[i]);
    ways=mul(ways,invr[++cnt[enu]]);
    // cout << ways << endl;;
  }
}

void dump(string separator){
  for (int i = 0; i <= sz; i++) {
    cout << dp[i] << " ";
  }
  cout << endl << separator << endl;
}

void calc(){
  dp[0]=1;
  for(int ch=0;ch<MXC;++ch){
    update(cnt[ch]);
  }
  dump("====");
  for(int c1=0;c1<MXC;++c1){
	if (!cnt[c1]) continue;
    remove(cnt[c1]);
    dump("----");
    sol[c1][c1]=mul(2*ways,dp[sz]);
    for(int c2=c1+1;c2<MXC;++c2){
      remove(cnt[c2]);
      sol[c1][c2]=mul(2*ways,dp[sz]);
      sol[c2][c1]=mul(2*ways,dp[sz]);
      update(cnt[c2]);
    }
    update(cnt[c1]);
  }
}

int main(){
  ios::sync_with_stdio(0),cin.tie(0);
  init();
  calc();
  int q;
  cin>>q;
  for(int i=0;i<q;++i){
    int x,y;
    cin>>x>>y;
    int ex=get(s[x-1]);
    int ey=get(s[y-1]);
    cout<<sol[ex][ey]<<'\n';
  }
}
