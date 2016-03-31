/*
 * tp2_deniz_secgin.c
 *
 *  Created on: 15 Eki 2015
 *      Author: deniz
 */

//Ronald Hanifen
//HW5


#include<stdio.h>
#include<stdlib.h>
#include<string.h>




struct entry{
	/*Please at first fill the struct*/
	char isim[20];
	char soyisim[20];
	char tel_no[20];
	struct entry *next;

};
typedef struct entry Entry;
typedef Entry *Entryptr;


void insert_something();
void insert(Entryptr);
void print_it_out();
void delete_something();
void search_something();


Entryptr head = NULL;


int main()
{
    int choice;
    while(choice != 5)
    {


    printf("What would you like to do?\n");
    printf("1 - Insert something in the phonebook?\n");
    printf("2 - delete something from the phonebook?\n");
    printf("3 - Print out one of the contacts?\n");
    printf("4 - Return the element selected?\n");
    printf("5 - Nothing at all\n");
    printf("Enter 1 through 5: ");
    scanf("%d", &choice);


    switch(choice){
        case 1:
            insert_something();
            print_it_out();
            break;
        case 2:
            delete_something();
            break;
        case 3:
            print_it_out();
            break;
        case 4:
            search_something();
            break;
        default:
            printf("\nThank you for using the phonebook\n");
            return 0;
    }
    }


    return 0;


}


void insert_something()
{
/*
	this function creates a new entry by taking the name,surname and telephone number from the end user
	Then, it uses a new function insert() to add this new entry to the list
*/
    Entry *ptr=malloc(sizeof(struct entry));
	printf("isim:");
	scanf("%s", ptr->isim);
	printf("soyisim:");
	scanf("%s", ptr->soyisim);
	printf("telefon numarasi:");
	scanf("%s", ptr->tel_no);
	ptr->next=NULL;
	insert(ptr);
}


void insert(Entryptr newnodeptr)
{
	/*This function adds the given entry to the list.
	It adds the entry by respecting the order of lastname. For example, there is celik, gunaydın and orman in the list ordered and new entry's surname
	is konak, then the new order should be celik, gunaydın, konak and orman. Konak should ne placed between gunaydın and orman.
	You can use strcmp() function to check the string order.
	Do not forget to create the list with the first entry.
	*/

	Entryptr trailing=head, target=head;
	if(head==NULL){
		head=newnodeptr;
	}

	else if(strcmp(newnodeptr->soyisim,target->soyisim)>0){
		newnodeptr->next=head;
		head=newnodeptr;
	}
	else{
		while(target!=NULL){
			if(strcmp(newnodeptr->soyisim,target->soyisim)>0){
				newnodeptr->next=target;
				trailing->next=newnodeptr;
			}
			else{
				trailing=target;
				target=trailing->next;
			}
		}
	}
	print_it_out();
}


void print_it_out()
{
	/*this function prints all the entry of the list to the screen
	You should print lastname, firstname and number all together with one space inbetween*/

	Entryptr tmp;
	tmp=head;
	while(tmp->next != NULL){
		printf("%s %s %s", tmp->soyisim, tmp->isim, tmp->tel_no);
		tmp=tmp->next;
	}
	printf("%s %s %s",tmp->soyisim, tmp->isim, tmp->tel_no);
}


void delete_something()
{
	/*This function asks to the end user the lastname to be deleted and then finds the entry with this lastname and removes this entry from the list.
	Do not forget, you can have more than one entry with the same lastname. you should remove all of them from  the list */
	Entryptr kisi, tmp;
	printf("Silinecek kisinin soyismini giriniz:");
	scanf("%s", kisi->soyisim);
	tmp=head;
	while(tmp!=NULL){
		if(strcmp(tmp->soyisim,kisi->soyisim)==0){
			tmp->next=(tmp->next)->next;
		}
	}
	tmp=tmp->next;
}




void search_something()
{
	/*This function asks from the end user the lastname to be found.
	Then, it finds the first name and phonenumber of the entries with the given lastname and prints the result on the screen*/
	Entryptr kisi,tmp;
	printf("Aradiginiz kisinin soyismini giriniz:");
	scanf("%s", kisi->soyisim);
	tmp=head;
	while(tmp!=NULL){
		if(strcmp(tmp->soyisim,kisi->soyisim)==0){
			printf("%s %s", tmp->isim, tmp->tel_no);
		}
		tmp=tmp->next;
	}
}



