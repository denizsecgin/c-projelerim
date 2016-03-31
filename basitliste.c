#include <stdio.h>
#include <stdlib.h>
struct eleman {
    int icerik;
    struct eleman* ileri;
};


struct eleman* basit_liste(void) {
    struct eleman* head = NULL;
    struct eleman* second = NULL;
    struct eleman* third = NULL;

    head = malloc(sizeof(struct eleman));
    second = malloc(sizeof(struct eleman));
    third = malloc(sizeof(struct eleman));

    head->icerik = 2;
    head->ileri = second;

    second->icerik =4;
    second->ileri = third;

    third->icerik = 6;
    third->ileri = NULL;

    return head;
}


int main(int argc, char *argv[])
{
    struct eleman* liste = basit_liste();
    struct eleman* gecici;
    gecici = liste;
    do {    	
       		printf("%d -> ", gecici->icerik);
            gecici = gecici->ileri;
 
    }while (gecici != NULL);
    
    printf("NULL\n");
    
return 0;
}
