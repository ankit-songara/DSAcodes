#include<iostream>
using namespace std;
int main()
{
	int n=0,x;
    int temp=0;
	int arr[100];
	while(cin>>x)
	{
		arr[n++]=x;
	}
	int i=0;
	int j=n-1;
	while(i<j)
	{
		if(arr[i]%2==0)
		{
			i++;
		}
		else if(arr[j]%2==1)
		{
			j--;
		}
		else
		{
			swap(arr[i],arr[j]);
			i++;
			j--;
		}
		
	}

	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}
