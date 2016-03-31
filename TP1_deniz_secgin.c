
// tp1_deniz_secgin.c

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define SIZE 20

void get_value();
void print_value();
void find_union();
void find_intersection();

int main(int argc, char *argv[]){
	int arr1[SIZE],arr2[SIZE];
    int union_array[SIZE],intersection_array[SIZE];
	void get_value(int arr1[]);
	void get_value(int arr2[]);
	printf("Dizilerin birlesimi:");
	void find_union(int arr1[], int arr2[], int union_array[]);
	printf("Dizilerin kesisimi:");
	void find_intersection(int arr1[],int arr2[],int intersection_array[]);
    return 0;
}

void get_value(int arr[]){
	int i;
	printf("%d adet tam sayi giriniz:", SIZE);
	for(i=0;i<SIZE;i++){
		scanf("%d", arr[i]);
	}
}

void print_value(int arr[], int n){
	for(n=0;n<SIZE;n++){
		printf("%d",arr[n]);
	}
}

void find_union(int array1[], int array2[], int union_array[]){
	int i,n;
	for(i=0;i<SIZE;i++){
		for(n=0;n<SIZE;n++){
			if(array1[i]==array2[n]){
				scanf("%d",union_array[i]);
				printf("%d", union_array[i]);
			}
			else if(array1[i]!=array2[n]){
				scanf("%d",union_array[i]);
				printf("%d",union_array[i]);
			}
		}
	}
}

void find_intersection(int array1[],int array2[],int intersection_array[]){
	int i,n;
	for(i=0;i<SIZE;i++){
		for(n=0;n<SIZE;n++){
			if(array1[i]==array2[n]){
				scanf("%d", intersection_array[i]);
				printf("%d", intersection_array[i]);
			}
		}
	}
}
