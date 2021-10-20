#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct song_node
{
    char artist[100];
    char name[100];
    struct song_node *next;
};

struct song_node *make_node(char *artist, char *name);
struct song_node *insert_front(struct song_node *head, char *artist, char *name);
struct song_node *insert(struct song_node *head, char *artist, char *name);
struct song_node *remove_song(struct song_node *head, char *artist, char *name);
struct song_node *rand_song(struct song_node *head);
struct song_node *find_song(struct song_node *head, char *artist, char *name);
struct song_node *find_artist_song(struct song_node *head, char *artist);
struct song_node *free_list(struct song_node *head);
int song_cmp(struct song_node *a, struct song_node *b);
void print_node(struct song_node *node);
void print_list(struct song_node *head);

#endif