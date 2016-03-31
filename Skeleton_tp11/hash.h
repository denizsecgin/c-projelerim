#ifndef _HASH_H_
#define _HASH_H_

/* Hash veri yapisindaki maksimum kova sayisi */
#define MAXBUCKETS  1000

/* Hash veri yapisinin anahtar tipi */
typedef struct key {
    char *word;
    unsigned long count;
    struct key *next;
} Key;

/* Fonksiyonlarin prototipleri */
unsigned long hash_compute(const char *str);
Key* hash_lookup(Key **table, const char *str, int create);
void hash_free(Key **table);
void hash_dump(Key **table, int n);

#endif
