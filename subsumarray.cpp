#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t)
	{
		int n,max;
		scanf("%d%d",&n,&max);
		int arr[n];
		for(int i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
		int first,last;
		first=0;
		last=0;
		int count=0;
		for(int i=0;i<n;i++)
		{
			if(arr[i]==max&&first!=last)
			{
				count=count+2;
				first=i+1;
				last=i+1;
			}
			else if(arr[i]==max&&first==last)
			{
				count++;
				first=i+1;
				last=i+1;
			}
			else if(arr[i]<max)
			{
				last++;
			}
			else if(arr[i]>max)
			{
				first=i+1;
				last=i+1;
			}
		}
		printf("%d",count);
		t--;
	}
}
