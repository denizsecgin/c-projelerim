#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct eleman{
    int icerik;                  /*define data as an int */
    struct eleman *ileri; /* stackNodepointer */    
}; 



void yigit_sil(struct eleman ** ust){
  struct eleman *temp = *ust;
  
  if (temp != NULL)
  {
    temp = *ust;
    *ust = (*ust)->ileri;
    free(temp);
    
  }
}

void yigit_ekle(struct eleman **ust, int icerik){
 struct eleman *yeni;
 yeni = malloc(sizeof (struct eleman));
 yeni->icerik = icerik ;
 yeni->ileri = *ust;
 *ust = yeni;
}

int yigit_ust(struct eleman *ust)
{
	return ust->icerik;
}

int main(void)
{
	struct eleman *stack, *gecici;
	stack = NULL;
	yigit_ekle(&stack,2);
	printf("%Yigit ust eleman -> %d\n", yigit_ust(stack));
    
	yigit_ekle(&stack,5);
	printf("%Yigit ust eleman -> %d\n", yigit_ust(stack));
    
	gecici = stack;
	while (gecici!=NULL) {    	
    	printf("%d -> ", gecici->icerik);
        gecici = gecici->ileri;
 
    }
    printf("NULL\n");
    
    yigit_sil(&stack);
    
	gecici = stack;
	while(gecici!=NULL) {    	
    	printf("%d -> ", gecici->icerik);
        gecici = gecici->ileri;
 
    }
    printf("NULL\n");
    

return 0;
}
