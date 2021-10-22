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

struct song_node *insert(struct song_node *head, char *artist, char *name)
{
    if (head == NULL)
    {
        return insert_front(head, artist, name);
    }

    struct song_node *node = make_node(artist, name);
    if (!song_cmp(head, node))
    {
        node->next = head;
        return head;
    }

    struct song_node *tmp = head;
    while (tmp)
    {
        if (!song_cmp(tmp, node))
        {
            node->next = tmp->next->next;
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
    int artist_cmp = 0;
    int name_cmp = 0;

    int a_artist_len = strlen(a->artist);
    int b_artist_len = strlen(b->artist);
    int a_name_len = strlen(a->name);
    int b_name_len = strlen(b->name);

    if (a_artist_len != b_artist_len)
    {
        int i = 0;
        while (a->artist[i] == b->artist[i] && a->artist[i] != '\0' && b->artist[i] != '\0')
            ++i;

        return a->artist[i] - b->artist[i];
    }

    if (a_name_len != b_name_len)
    {
        int i = 0;
        while (a->name[i] == b->name[i] && a->name[i] != '\0' && b->name[i] != '\0')
            ++i;

        return a->name[i] - b->name[i]; // stuff
    }

    return 0;
}

void print_node(struct song_node *node)
{
    printf("%s: %s", node->artist, node->name);
}

void print_list(struct song_node *head)
{
    struct song_node *tmp = head;
    while (tmp)
    {
        printf(" ");
        print_node(tmp);
        printf(" |");

        tmp = tmp->next;
    }
    printf("\n");
}