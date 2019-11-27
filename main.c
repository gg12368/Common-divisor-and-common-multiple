#include<stdio.h>
#define N 100 
int gcd(int a,int b)					//利用辗转相除法中的函数递归调用两个数的最大公约数 
{
	if(a%b==0)
		return b;
	else
		return gcd(b,a%b);				
 } 
 int ngcd(int *a, int n)				//主函数中提示输入想要求取最大公约数和最小公倍数的N个数，因数组下标从0开始，故实际下标至n-1数 
{
	if(n==1)
		return *a;
	return gcd(a[n-1],ngcd(a, n-1));    //坐标n-1数与前面数的公约数 ，利用递归调用 求取N个数的最大公约数 
}
int lcm(int a,int b)					//求取两个数的最小公倍数 
{
	return a*b/gcd(a, b);
}
int nlcm(int *a, int n)					//利用递归调用求取N个数的最小公倍数 
{
	if (n==1)
		return *a;
	else
		return lcm(a[n-1],nlcm(a,n-1));
}
 int main()
{
	int n,i;
	int a[N];
	while(1)
	{
		printf("******请输入N个数，将会对这您输入的这N个数求最大公约数和最小公倍数【n>=2】******\n");
		scanf("%d",&n);
		if(n==0) break;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
			
		for(i=0;i<n;i++)
			printf("%d ",a[i]);
		printf("：%d个数\n最大公约数为：%d，最小公倍数为：%d\n",n,ngcd(a,n),nlcm(a,n)); 
	} 
	return 0;
}
