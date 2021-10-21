#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void print_node(struct song_node *node)
{
    printf("%s: %s", node->artist, node->name);
}

void print_list(struct song_node *head)
{
    struct song_node *tmp = tmp;
    while (tmp)
    {
        printf(" ");
        print_node(tmp);
        printf(" |");

        tmp = tmp->next;
    }
    printf("\n");
}