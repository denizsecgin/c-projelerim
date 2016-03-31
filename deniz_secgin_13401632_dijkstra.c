#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define INFINITY 1000
#define MaxVertex 5
#define TRUE 1
#define FALSE 0
typedef int AdjTab[MaxVertex][MaxVertex];
typedef int DistTab[MaxVertex];

int n;
AdjTab cost;
DistTab D;


void dijkstra(int n,AdjTab cost,DistTab D){
	int final[MaxVertex];
	int i,w,v,min;
	final[0]=TRUE;
	D[0]=0;

	for(v=1;v<n;v++){
		final[v]=FALSE;
		D[v]=cost[0][v];
	}
	for(i=1;i<n;i++){
		min=INFINITY;
		for(w=1;w<n;w++){
			if(!final[w])
				if(D[w]<min){
					v=w;
					min=D[w];

				}
			final[v]=TRUE;
			for(w=1;w<n;w++){
				if(!final[w]){
					if(min+cost[v][w]<D[w])
						D[w]=min+cost[v][w];
				}
			}
		}
	}
}


int main(){
	int i,j;

	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			cost[i][j]=1+rand()%5;
		}
	}
	return 0;
}
