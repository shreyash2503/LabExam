#include <bits/stdc++.h>
using namespace std;

void mergeArray(int afhfint x[], int y[], int s, int e)
{
	int mid = (s+e)/2;
	int i = s;
	int j = mid+1;
	int k = s;
	while(i <= mid && j <= e)
	{
		if(x[i] > y[j])
		{
			a[k] = y[j];
			k++;
			j++;
		}
		else
		{
			a[k] = x[i];
			k++;
			i++;
		}

	}
	while(i <= mid)
	{
		a[k] = x[i];
		k++;
		i++;
	}
	while(j <= e)
	{
		a[k] = y[j];
		k++;
		j++;
	}
}

void mergeSort(int a[], int s, int e)
{
	if(s >= e) return;
	int mid = (s+e)/2;
	int x[100];
	int y[100];
	for(int i=0;i<=mid;i++)
	{
		x[i] = a[i];
	}
	for(int i=mid+1;i<=e;i++)
	{
		y[i] = a[i];
	}
	mergeSort(x, s, mid);
	mergeSort(y, mid+1, e);
	mergeArray(a, x, y, s, e);
}

int partiion(int a[], int s, int e)
{
	int pivot = a[e];
	int i = s;
	for(int j=0;j<=e-1;j++)
	{
		if(a[j] < pivot)
		{
			swap(a[i], a[j]);
			i++;
		}
	}
	swap(a[i], a[e]);
	return i;
}

void quickSort(int a[], int s, int e)
{
	if(s >= e)
	{
		return;
	}
	int p = partition(a, s, e);
	quickSort(a, s, p-1);
	quickSort(a, p+1, e);
}


int main()
{

}