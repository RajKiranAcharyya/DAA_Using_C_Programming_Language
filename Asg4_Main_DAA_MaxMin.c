#include<stdio.h>
#include<limits.h>
int a[100],fmax=INT_MIN,fmin=INT_MAX;
int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}
int min(int a,int b)
{ 
	if(a<b)
		return a;
	else
		return b;
}
void maxmin(int i,int j)
{
	if(i == j)
	{
		fmax=fmin=a[i];
	}
	else if(i == j-1)
	{
		if(a[i] < a[j])
		{
			fmax=a[j];
			fmin=a[i];
		}
		else
		{
			fmax=a[i];
			fmin=a[j];
		}
	}
	else
	{
		int mid=(i+j)/2;
		maxmin(i,mid);
		int lmax=fmax,lmin=fmin;
		maxmin(mid+1,j);
		int rmax=fmax,rmin=fmin;
		fmax=max(lmax,rmax);
		fmin=min(lmin,rmin);
	}
}
int main()
{
	int n=0,k=0;
	printf("\nEnter The Array Size: ");
	scanf("%d",&n);
	printf("\nEnter The Elements: ");
	for(k=0; k<n; k++)
	{
		scanf("%d",&a[k]);
	}
	maxmin(0,n-1);
	printf("\nMaximum Value: %d and Minimum Value: %d",fmax,fmin);
	return 0;
}

