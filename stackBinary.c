#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct eleman{
    int icerik;                  
    struct eleman *ileri; 
}; 



int yigit_sil(struct eleman ** ust){
  struct eleman *temp = *ust;
  int icerik;
  
  if (temp != NULL)
  {
    temp = *ust;
    icerik=temp->icerik;
    *ust = (*ust)->ileri;
    free(temp);
    return icerik;   
  }
  else{
  	fputs("Hata: yýðýt boþ \n", stderr);
  	return -1;
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
void yigit_yazdir(struct eleman *ust)
{
	while (ust!=NULL) {    	
    	printf("%d -> ", ust->icerik);
        ust = ust->ileri;
 
    }
    printf("NULL\n");

}
void ikilik_sistem(int N)
{
  struct eleman *ust=NULL;
  int icerik;
  
  printf("%d:", N);  
  while (N>0)
  {
   yigit_ekle(&ust, N%2);
  // yigit_yazdir(ust);
   N=N/2;
  }
  
  while(ust!=NULL)
  {
   icerik=yigit_sil(&ust);
   printf("%d", icerik);  
  } 
  printf("\n");
  
}

int main(void)
{
	int N;
	printf("Ikilik sisteme cevirmek icin bir sayi giriniz:");
	scanf("%d", &N);
    ikilik_sistem(N);

return 0;
}
