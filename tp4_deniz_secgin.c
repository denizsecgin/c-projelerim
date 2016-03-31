#include<stdio.h>
#include<stdlib.h>

typedef struct agac{
	int data;
	int count;
	struct agac *right;
	struct agac *left;
}agac;

agac *insert(agac *node,int deger){
	if(node==NULL){
		node=(agac*)malloc(sizeof(struct agac));
		node->left=NULL;
		node->right=NULL;
		node->data=deger;
		return NULL;
	}
	else if(deger>node->data){
		return insert(node->right,deger);
	}
	else{
		return insert(node->left,deger);
	}
}

agac *FindMin(agac *node){
	if(node==NULL){
		printf("Hata agac boş!");
		return NULL;
	}
	else{
		if(node->left==NULL)
			return node;
		else
			return FindMin(node->left);
	}
}

agac *FindMax(agac *node){
	if(node==NULL){
		printf("HATA!");
		return NULL;
	}
	else{
		if(node->right==NULL)
			return node;
		else return FindMax(node->right);
	}
}

agac *Delete(agac *node, int deger){
	struct agac *temp=(agac*)malloc(sizeof(struct agac));
	if(node==NULL){
		printf("agac boş hata!");
		return NULL;
	}
	else{
		if(deger>node->data){
			node->right=Delete(node->right,deger);
		}
		else if(deger<node->data){
			node->left=Delete(node->left,deger);
		}
		else{
			if(node->left && node->right){
				temp=FindMin(node->right);
			}
			else{
				temp=node;
				if(node->left==NULL)
					node=node->right;
				else if(node->right==NULL)
						node=node->left;
				free(temp);
			}
		}
	}
	return node;
}

void PrintInOrder(agac *node){
	if(node==NULL){
		printf("hata");
	}
	PrintInOrder(node->left);
	printf("%d", node->data);
	PrintInOrder(node->right);
}
 void PrintPreOrder(agac *node){
	 if(node==NULL){
	 		printf("hata");
	 	}
	 printf("%d", node->data);
	 PrintPreOrder(node->left);
	 PrintPreOrder(node->right);

 }

 void PrintPostOrder(agac *node){
 	if(node==NULL){
 		printf("hata");
 	}
 	PrintPostOrder(node->right);
 	PrintPostOrder(node->left);
 	printf("%d", node->data);
 }

 int main(int argc, char *argv[]){
	 int menu, deger;
	 struct agac *node;
	 printf(" 1)Agaca ekleme \n 2)Agactan silme\n 3)Preorder siralatma\n 4)Postorder siralatma\n 5)Inorder siralatma\n 6)En dusuk sayiyi bulma\n 7) en yuksek sayiyi bulma\n 8)Cikis\n");
	 scanf("%d", &menu);

	 switch(menu){
	 case 1:printf("Eklenecek sayiyi giriniz:");
	 break;
	 case 2:printf("Silme");
	 break;
	 case 3:printf("Preorder siralatma:");
	 break;
	 case 4:printf("Postorder siralatma:");
	 break;
	 case 5:printf("Inorder siralatma:");
	 break;
	 case 6:printf("Agactaki en dusuk sayi:");
	 break;
	 case 7:printf("Agactaki en yuksek sayi:");
	 break;
	 case 8:printf("Cıkıs");
	 break;
	 }
	 if(menu==1){
		 insert(node,deger);
	 }
     if(menu==2){
    	 Delete(node,deger);
     }
     if(menu==3){
    	 PrintPreOrder(node);
     }
     if(menu==4){
    	 PrintPostOrder(node);
     }
     if(menu==5){
    	 PrintInOrder(node);
     }
     if(menu==6){
    	 FindMin(node);
     }
     if(menu==7){
    	 FindMax(node);
     }
     if(menu==8)
    	 return 0;
     return 0;
 }
