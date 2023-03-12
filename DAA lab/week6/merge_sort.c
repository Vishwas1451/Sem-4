#include <stdio.h>
#include <stdlib.h>

void merge(int a[], int low, int mid, int high){
	int i,j,k;
	int temp[20];
	k=low;
	i=low;
	j=mid+1;
	while(i<=mid && j<=high){
		if(a[i]<=a[j])
				temp[k++]=a[i++];
		else	
				temp[k++]=a[j++];
			
	}
	if(i>mid && j<=high){
		while(j<=high){
			temp[k++]=a[j++];
		}
	}
	else if(j>high && i<=mid){
		while(i<=mid){
			temp[k++]=a[i++];
		}
	}
	for(k=low; k<=high;k++){
		a[k]=temp[k];
	}
	
}	
void mergesort(int a[], int low, int high){
	int mid;
	if(low<high){
		mid=(low+high)/2;
		mergesort(a,low,mid);
		mergesort(a,mid+1,high);
		merge(a,low,mid,high);
	}
}
void display(int a[],int n){
	for(int i=0;i<n;i++){
		printf("%d\t",a[i]);
	}
}

int main(){
	int i, low, high,n;
	printf("Enter the array size");
	scanf("%d",&n);
	printf("Enter the elements of the array:");
	int a[n];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		
	}
	low=0;
	high = n-1;
	mergesort(a,low,high);
	display(a,n);
	return 0;
}
