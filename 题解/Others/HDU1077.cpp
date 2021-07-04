#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	int t;
	int year,month,date;
	while(~scanf("%d",&t)){
		while(t--){
			scanf("%d%d%d",&year,&month,&date);
			if((month+date)%2==0||(month==9||month==11)&&date==30)
			puts("YES");
			else puts("NO");
		}
	}
	return 0;
}
