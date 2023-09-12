#ifndef HASH_HEADER_H
#define HASH_HEADER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define CAPA 50000

/**
* struct hash_table_item - struct for items in hash table
* @key: key
* @value: value
*/

typedef struct hash_table_item
{
	char *key;
	char *value;

} hash_t;

/**
* struct hash_table - structure for hash table
* @size: size of the hash_table
* @count: count of elements in hash table
*/

typedef struct hash_table
{
	hash_t **items;
	int size;
	int count;

} hash_table;

unsigned long int hash_function(char *str);
hash_t *create_item(char *key, char *value);
hash_table *create_table(char *key, char *value);
void print_hash_table(*hash_table table);
void insert_table(*hash_table new_table, char *key, char *value);
void handle_collision(*hash_table table, *hash_t item);

#endif /* HASH_HEADER_H */

