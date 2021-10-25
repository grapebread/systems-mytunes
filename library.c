#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "linkedlist.h"
#include "library.h"

struct song_node **make_library()
{
	return calloc(27, sizeof(struct song_node *));
};

struct song_node **add_song_node(struct song_node **head, char *artist, char *name)
{
	head[to_index(artist[0])] = insert(head[to_index(artist[0])], artist, name);
	return head;
}

struct song_node *search_song(struct song_node **head, char *artist, char *name)
{
	return find_song(head[to_index(artist[0])], artist, name);
}

struct song_node *search_artist(struct song_node **head, char *artist)
{
	return find_artist(head[to_index(artist[0])], artist);
}

struct song_node **delete_song(struct song_node **head, char *artist, char *name)
{
	head[to_index(artist[0])] = remove_song(head[to_index(artist[0])], artist, name);
	return head;
}

struct song_node **clear_library(struct song_node **head)
{
	for (int i = 0; i < 27; i++)
	{
		free_list(head[i]);
	}
	free(head);
	return NULL;
}

int to_index(char c)
{
	if (tolower(c) >= 97 && tolower(c) <= 122)
	{
		return tolower(c) - 97;
	}
	return 26;
}

void print_letter(struct song_node **head, char l)
{
	print_list(head[to_index(l)]);
}

void print_artist(struct song_node **head, char *artist)
{
	struct song_node *temp = head[to_index(artist[0])];
	printf("| ");
	while (temp)
	{
		if (!strcasecmp(temp->artist, artist))
		{
			printf("%s: %s", temp->artist, temp->name);
			printf(" |");
			printf(" ");
		}
		temp = temp->next;
	}
	printf("\n\n");
}

void print_library(struct song_node **head)
{
	if (head)
	{
		for (int i = 0; i < 27; i++)
		{
			if (head[i])
			{
				if (i == 26)
				{
					printf("#: ");
				}
				else
				{

					printf("%c: ", i + 97);
				}

				print_list(head[i]);
				printf("\n");
			}
		}
	}
	else
	{
		printf("");
	}
}

int count_total_nodes(struct song_node **head)
{
	int count = 0;
	for (int i = 0; i <= 26; ++i)
	{
		count += count_nodes(head[i]);
	}

	return count;
}

int generate_random(struct song_node **head)
{
	int r = rand() % 27;
	while (!head[r])
	{
		r = rand() % 27;
	}
	return r;
}

void shuffle(struct song_node **head, int n)
{
	struct song_node *temp = NULL;
	int count = count_total_nodes(head);
	for (int i = 0; i < n && i < count; i++)
	{
		int r = generate_random(head);
		struct song_node *r2 = rand_song(head[r]);
		while (find_song(temp, r2->artist, r2->name))
		{
			r = generate_random(head);
			r2 = rand_song(head[r]);
		}
		print_node(r2);
		printf("\n");
		temp = insert(temp, r2->artist, r2->name);
	}
}

/*void shuffle(struct song_node **head, int n){
	struct song_node *temp = NULL;
	for (int i = 0; i < n && )
	int r = rand() % 27;
	while (!head[r]){
		r = rand() % 27;
	}

}*/
