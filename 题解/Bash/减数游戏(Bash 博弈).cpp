/*�����ˣ�n��ʯ�ӣ�Mondayÿ���ܴ�ʯ����ȡx����
LXHingÿ���ܴ�ʯ����ȡy�����ʻغϽ���ʱ����
�Ƿ���Ӯ 
*/ 
#include<bits/stdc++.h>
using namespace std;
int judge(int n,int a,int b){
	if(a==b){
		if(n%(a+1)==0) return 0;
		else return 1;
	}
	else {
		if(a>b) return 1;
		else {
			if(a>=n) return 1;
			else return 0;
		}
	}
}
int main(){
	int n,x,y;
	scanf("%d%d%d",&n,&x,&y);
	int ans=judge(n,x,y);
	if(ans) printf("Monody wins!\n");//���� 
	else printf("LXHing wins\n");
	return 0;
} 
