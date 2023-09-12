#include "hash_header.h"

/**
 * hash_function - function for hash table
 * @str: contains values maybe
 * Return - index of hash function
*/

unsigned long int hash_function(char *str){

    unsigned long h = 0;

    for (int j = 0; str[j]; j++)
        h += str[j];

        return (h % CAPA);
}

/**
* create_item - function to allocate memory for items
* @key: key
* @value: value
* Return: item's key and values
*/

hash_t *create_item(char *key, char *value)
{
	hash_t *item = malloc(sizeof(hash_t));

	item->key = malloc(strlen(key) + 1);
	item->value = malloc(strlen(value) + 1);

	strcpy(item->key, key);
	strcpy(item->value, value);

	return (item);
}

/**
* create_table - allocates memory for hash_table
* @key: key
* @value: value
* Return: newly created hash table
*/
hash_table *create_table(char *key, char *value)
{
	int i;

	new_table = malloc(sizeof(hash_table)); /*allocate memory*/
	if (new_table == NULL)
	{
		return (NULL);
	}
	new_table->size = size;
	new_table->count = 0;
	new_table_items = malloc(table->size * sieof(hash_t *));
	if (new_table->items == NULL)
	{
		free(new_table);
		return (NULL);
	}
/* initializing memory of items to Null since malloc does not*/
	for (i = 0; i < new_table->size; i++)
	{
		new_table->items[i] == NULL;
	}

	return (new_table);


}

/**
* print_hash_table - function that prints items in hash table
* @table: hash table
* Return: nothing
*/
void print_hash_table(*hash_table table)
{
	int h;

	printf("\nHash table\n-------------\n");

	/*A loop that goes through the table and prints contents*/

	for (h = 0; h < new_table->size; h++)
	{
		if (new_table->items[h] != NULL)
		{
			printf("Index:%d, Key:%s, Value:%s\n",
			h, new_table->items[h]->key, new_table->items[h]->value);
		}
		printf("-------------------\n\n");
	}

}

/**
 * insert_table - function that inserts item in has table
 * @new_table: hash table
 * @key: key
 * @value: value
 * Return: nothing
*/

void insert_table(*hash_table new_table, char *key, char *value)
{
	item = create_item(key, value); /*calling function to create items*/
	int idx = hash_function(key);

	/* checks if an item is stored at the current index*/
	hash_t *current_item = new_table->items[idx];

	if (current_item == NULL)
	{
		if (new_table->count == new_table->size)
		{
			printf("Hash table is full\n");
			return;
		}
		new_table->items = item;
		new_table->count++;
	}
	else
	{
		handle_collision(new_table, item);
	}
}

/**
 * handle_collision - updates value of an existent key
 * @new_table: the hash table
 * @item: item
*/
void handle_collision(*hash_table new_table, *hash_t item)
{
	item = create_item(key, value); /*calling function to create items*/
	int idx = hash_function(key);

	/* checks if an item is stored at the current index*/
	hash_t *current_item = new_table->items[idx];

	if (current_item != NULL)
	{
		if (strcmp(current_item->key, key) == 0) {
            // Update the value for the existing key
            strcpy(new_table->items[idx]->value, value);
        }
	}

}
