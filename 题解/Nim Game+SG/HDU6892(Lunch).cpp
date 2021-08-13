//转化为nim游戏，sg定理求解
/*对于长度为l的巧克力，sg(l)等于l的奇质因数的幂次和+l是否为偶数*/ 
#include<cstdio>
using namespace std;
typedef long long ll;
const int N=1e5+2;
int pri[N],check[N],num[N];
int w[N],cnt;
void init(){  //欧拉筛 
	for(int i=2;i<=N;i++){
		if(!check[i]) pri[++cnt]=i,num[i]=1;
		for(int j=1;j<=cnt&&i*pri[j]<=N;j++){
			check[i*pri[j]]=1;
			num[i*pri[j]]=num[i]+1;
			if(i%pri[j]==0) break;
		}
	}
} 
int SG(int x){
	int res=0;
	for(int i=1;i<=cnt&&pri[i]<=x/pri[i];i++){
		if(x%pri[i]==0){
			if(pri[i]==2){
				res++;
				while(x%pri[i]==0) x/=pri[i];
			}
			else {
				while(x%pri[i]==0) x/=pri[i],res++;
			}
		}
	}
	if(x>1) res++;
	return res;
}
int main(){
	init();
	int t;
	scanf("%d",&t);
	while(t--){
		int n;scanf("%d",&n);
		ll ans=0;
		for(int i=1;i<=n;i++) {
			int x;scanf("%d",&x);
		    ans^=SG(x);
		}
		if(ans) puts("W");
		else puts("L");
	}
	return 0;
}
