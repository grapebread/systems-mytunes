#define LINKEDLIST_H
#ifndef LINKEDLIST_H

struct song_node
{
    char name[100];
    char artist[100];
    struct song_node *next;
}

#endif