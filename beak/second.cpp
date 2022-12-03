//피보나치 수열 0과 1이 몇번 호출 되는 지 알아봅시다/

#include<iostream>

int arr_0[41];
int arr_1[41];
int sumarr[41];

int fibonacci(int n,int base)
{
    if(n==0)
    {
       arr_0[base]++;
        return 0;
    }
    if(n==1)
    {
        arr_1[base]++;
        return 1;

    }
    else{
        int sum1,sum2;

        if(sumarr[n-1]>0)
        {
            sum1=sumarr[n-1];
            arr_0[base]+=arr_0[n-1];
            arr_1[base]+=arr_1[n-1];
        }
        else 
        sum1=fibonacci(n-1,base);

        if(sumarr[n-2]>0){
            sum2=sumarr[n-2];
            arr_0[base]+=arr_0[n-2];
            arr_1[base]+=arr_1[n-2];
        }
        else 
        sum2=fibonacci(n-2,base);    
    
     return sumarr[n]=sum1+sum2;
    }
   
}

void Result()
{
    int a;
    scanf("%d",&a);
    while(a--)
    {
        int num;
        scanf("%d",&num);
        for( int i=0;i<40;i++)
        {
            arr_0[i]=0;
            arr_1[i]=0;
            sumarr[i]=0;
        }
        for( int i=0;i<=num;i++)
        fibonacci(i,i);

      	printf("%lld %lld\n", 
			arr_0[num],
			arr_1[num]);
	}
        
    
}
 int main(){
    Result();
    return 0;
 }
