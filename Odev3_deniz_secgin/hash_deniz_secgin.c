#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "hash.h"

/* Stringler icin basit bir hash hesaplama fonksiyonu.
 * Her harfin ASCII degeri, onceki hash degerinin bir
 * carpanina ekleniyor.
 * Ornegin: "abcde" stringi icin:
 *  h0 = 0 * 31 + 97 = 97
 *  h1 = h0 * 31 + 98 = 3105
 *  h2 = h1 * 31 + 99 = 96354
 *  h3 = h2 * 31 + 100 = 2987074
 *  h4 = h3 * 31 + 101 = 92599395
 *  92599395 % MAXBUCKETS (1000) = 395
 */
unsigned long hash_compute(const char *str) {
    unsigned long hash = 0;
    while (*str) {
        hash = (hash * 31) + *str;
        ++str;
    }
    return hash % MAXBUCKETS;
}

/* Her elemani bir bagli liste gostericisi olan table
 * dizisi parametre olarak veriliyor. Bu table dizisi
 * aslinda hash veriyapisini temsil eder.
 *
 * str ile verilen string hash'te var ise adresi
 * dondurulur. Yoksa ve create == 1 ise, hash
 * veriyapisina bu string eklenir.*/
Key* hash_lookup(Key **table, const char *str, int create) {
    /* TODO 1 */
	int n=hash_compute(str);
		if(table[n]!=NULL){
			struct key *tmp=table[n];
			while(tmp->next!=NULL){
				if(tmp->word==str){
				return tmp;
				}
				tmp=tmp->next;
			}
		}


    /* Bulunmazsa eklensin mi? */
    if (create) {
        /* TODO 2 */
    	struct key *tmp=malloc(sizeof(Key));
    	tmp->word=strdup(str);
    	tmp->next=table[n];
    	table[n]=tmp;
    	return tmp;
    }
    return NULL;
}

/* table ile verilen hash veriyapisini
 * isletim sistemine iade eden fonksiyon.
 * Temizlerken, her bagli listenin dugumlerini
 * ve bu dugumlerdeki "word" uyesini free()
 * etmeniz gerekiyor.*/
void hash_free(Key **table) {
    /* TODO 3 */
	int i;
	for(i=0;i<MAXBUCKETS;i++){
		struct key *tmp=table[i];

		while(tmp->next!=NULL){
		free(tmp->word);
		}

		free(table[i]);

	}
}

/* count parametresi >= n olan kelimeleri ekrana
 * yazdiran fonksiyon. Ekrana yazdirirken
 * "%30s-->%5ld\n" formatini kullanin.
 * %ld: unsigned long icin gerekiyor.*/
void hash_dump(Key **table, int n) {
    /* TODO 4 */
	int i;
	for(i=0;i<MAXBUCKETS; i++){
		struct key *tmp=table[i];
		while(tmp->next!=NULL){
			if(tmp->count >= n){
				printf("%30s-->%5ld\n",tmp->word, tmp->count);
			}
		}
	}
}
