#include<stdio.h>
#include<limits.h>
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
void maxmin(int *a,int i,int j,int *fx,int *fn)
{
	if(i == j)
	{
		*fx=*fn=a[i];
	}
	else if(i == j-1)
	{
		if(a[i] < a[j])
		{
			*fx=a[j];
			*fn=a[i];
		}
		else
		{
			*fx=a[i];
			*fn=a[j];
		}
	}
	else
	{
		int mid=(i+j)/2;
		maxmin(a,i,mid,fx,fn);
		int lmax=*fx,lmin=*fn;
		maxmin(a,mid+1,j,fx,fn);
		int rmax=*fx,rmin=*fn;
		*fx=max(lmax,rmax);
		*fn=min(lmin,rmin);
	}
}
int main()
{
	int n=0,k=0,fmax=INT_MIN,fmin=INT_MAX,h[100];
	printf("\nEnter The Array Size: ");
	scanf("%d",&n);
	printf("\nEnter The Elements: ");
	for(k=0; k<n; k++)
	{
		scanf("%d",&h[k]);
	}
	maxmin(h,0,n-1,&fmax,&fmin);
	printf("\nMaximum Value: %d and Minimum Value: %d",fmax,fmin);
	return 0;
}

