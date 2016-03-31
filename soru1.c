#include<stdlib.h>
#include<stdio.h>

#define MAXQUEUE 5

typedef struct queue{
int count;
int front;
int rear;
int entry[MAXQUEUE];
}Queue;

int QueueSize(Queue *q){
	int i;
	for(i=0;i<MAXQUEUE;i++){
		q->count ++;
	}
	return 0;
}

int isEmpty(Queue *q){
	if(q->count == 0){
		return 0;
	}
	else{
		return 1;
	}
}

int isFull(Queue *q){
	int res;
	if(q->count == MAXQUEUE)
		res=0;
	else
		res=1;
	return res;
}


void CreateQueue(Queue *q){
	q->count=0;
	q->front=0;
	q->rear= -1;
}


int Enqueue(Queue *q,int new){
	printf("Yeni kisi ekle");
	if(isFull(q)==0){
		printf("Kuyruk dolu!");
		return 1;
	}
	else{
		q->count ++;
	    q->rear ++;
	    q->entry[q->front]=new;
	}
	return 0;
}

int Dequeue(Queue *q,int a){
	if(isEmpty(q)==0){
		printf("Kuyruk bos!");

		return 1;
	}
	else{
		q->count --;
		a=q->entry[q->front];
		int i=0;
		for(i=0;i<=q->rear;i++){
			q->entry[i]=q->entry[i+1];
		}
		q->rear --;
		return 0;

	}
}

int main(int argc, char *argv[]){
	int a,cevap;
	struct Queue *q;
	printf("Siradaki eleman sayisi:");
	QueueSize(q);

	if(isEmpty(q)==0){
		printf("Kuyruk bos!");
	}

	if(isFull(q)==0){
		printf("Kuyruk dolu!");
	}

	switch(cevap){
	case 1: printf("1)bos kuyruk yaratmak icin:");
	break;
	case 2: printf("2)Kuyruga kisi eklemek icin");
	break;
	case 3: printf("3)Kuyruktan kisi silmek icin ");
	break;
	default: printf("Hata! 1 2 ya da 3 e basiniz.");
	break;
	}

	if(cevap==1) CreateQueue(q);
	if(cevap==2) Enqueue(q,a);
	if(cevap==3) Dequeue(q,a);

}
