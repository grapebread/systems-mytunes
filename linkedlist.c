#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "linkedlist.h"

struct song_node *make_node(char *artist, char *name)
{
    struct song_node *node = malloc(sizeof(struct song_node));
    strcpy(node->artist, artist);
    strcpy(node->name, name);
    node->next = NULL;

    return node;
}

struct song_node *insert_front(struct song_node *head, char *artist, char *name)
{
    struct song_node *new_head = make_node(artist, name);
    new_head->next = head;

    return new_head;
}

struct song_node *insert(struct song_node *head, char *artist, char *name)
{
    if (head == NULL)
    {
        return insert_front(head, artist, name);
    }

    struct song_node *node = make_node(artist, name);
    if (song_cmp(head, node) > 0)
    {
        node->next = head;
        return node;
    }

    struct song_node *tmp = head;
    while (tmp)
    {
        if (tmp -> next == NULL){
          tmp -> next = node;
          break;
        }
        if (song_cmp(tmp, node) < 0 && (song_cmp(tmp -> next, node) > 0))
        {
            node->next = tmp->next;
            tmp->next = node;
            break;
        }

        tmp = tmp->next;
    }

    return head;
}

struct song_node *find_song(struct song_node *head, char *artist, char *name)
{
    while (head)
    {
        if (!strcmp(head->artist, artist) && !strcmp(head->name, name))
        {
            return head;
        }

        head = head->next;
    }

    return head;
}

int song_cmp(struct song_node *a, struct song_node *b)
{
    if (strcasecmp(a ->artist, b ->artist) == 0) return strcasecmp(a -> name, b->name);
    // different artists
    else return strcasecmp(a->artist, b->artist);
}

void print_node(struct song_node *node)
{
    if (node) {
      printf("%s: %s\n", node->artist, node->name);
    }
    if (!node){
      printf("%s\n", "No Song");
    }
}

void print_list(struct song_node *head)
{
    struct song_node *tmp = head;
    printf("| ");
    while (tmp)
    {
        printf("%s: %s", tmp->artist, tmp->name);
        printf(" |");
        printf(" ");

        tmp = tmp->next;
    }
    printf("\n");
}

struct song_node *find_artist_song(struct song_node *head, char *artist){
	while (head){
		if (!(strcasecmp((head -> artist), artist))){
		  return head;
    }
    head = head -> next;
	}
	return NULL;
}


struct song_node *rand_song(struct song_node *head){
	int r = rand() % count_nodes(head);
	while (r){
		head = head -> next;
    r--;
	}
	return head;
}

int count_nodes(struct song_node *a){
  int i = 0;
  while (a){
    i++;
    a = a -> next;
  }
  return i;
}

struct song_node *remove_song(struct song_node *head, char *artist, char *name){
	struct song_node *first = head;
  struct song_node *temp;
  int tmp = 1;
  while (head){
    if (!(song_cmp(head, make_node(artist, name))) && tmp != 1){
      temp -> next = head -> next;
      free(head);
    }
    if (!(song_cmp(head, make_node(artist, name))) && tmp == 1){
      temp = head -> next;
      first = temp;
      free(head);
    }
    temp = head;
    head = head -> next;
    tmp++;
  }
  return first;
}

struct song_node *free_list(struct song_node *head){
	struct song_node *first = head;
	struct song_node *temp;
	while (head){
		temp = head;
		free(temp);
		head = head -> next;
	}
	return NULL;
}
