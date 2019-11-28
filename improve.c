#include<iostream>
using namespace std;
int gcd(int a,int b)
{
	return a==0?b:gcd(b%a,a);   //求取最大公约数
}
int main(){
int a0,a1,b0,b1;
    int n,X;
	 cin>>n;
	 while(n--){
		cin>>a0>>a1>>b0>>b1;
		X=0;int p=a0/a1;int q=b1/b0;		//确保a0能被a1整除，b1能被b0整除
		for(int x=1;x*x<=b1;x++){
			if(b1%x==0){
				if(x%a1==0 && gcd(x/a1,p)==1 && gcd(b1/x,q)==1) X++;
			int y=b1/x;	//得到另一个因子
			if(y==x) continue;
			if(y%a1==0 && gcd(y/a1,p)==1 && gcd(b1/y,q)==1) X++;
			}
		}
		cout<<X<<endl;
	}
	return 0;
}
