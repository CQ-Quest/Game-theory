//����һ��n*n�����̣�ÿ���ƶ�һ��λ�ã����õ�δ������������������ƶ�����ʧ�� 
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	while(~scanf("%d",&n)&&n){
		long long m=n*n-1;
		if(m%2==0) puts("ailyanlu");
		else puts("8600");
	}
	return 0;
}
