#include "hash_tables.h"

/**
 * create_node - Creates a new hash node.
 * @key: The key for the new node.
 * @value: The value for the new node.
 *
 * Return: Pointer to the new node, or NULL on failure.
 */
hash_node_t *create_node(const char *key, const char *value)
{
	hash_node_t *new;

	new = malloc(sizeof(hash_node_t));
	if (new == NULL)
		return (NULL);
	new->key = strdup(key);
	if (new->key == NULL)
	{
		free(new);
		return (NULL);
	}
	new->value = strdup(value);
	if (new->value == NULL)
	{
		free(new->key);
		free(new);
		return (NULL);
	}
	return (new);
}

/**
 * hash_table_set - Adds or updates an element in the hash table.
 * @ht: The hash table.
 * @key: The key.
 * @value: The value.
 *
 * Return: 1 if success, 0 otherwise.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx;
	hash_node_t *tmp, *new;
	char *v_copy;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);
	idx = key_index((const unsigned char *)key, ht->size);
	tmp = ht->array[idx];
	while (tmp)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			v_copy = strdup(value);
			if (v_copy == NULL)
				return (0);
			free(tmp->value);
			tmp->value = v_copy;
			return (1);
		}
		tmp = tmp->next;
	}
	new = create_node(key, value);
	if (new == NULL)
		return (0);
	new->next = ht->array[idx];
	ht->array[idx] = new;
	return (1);
}
