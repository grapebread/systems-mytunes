#ifndef LIBRARY_H
#define LIBRARY_H

struct song_node **make_library();
struct song_node **add_song_node(struct song_node **head, char *artist, char *name);
struct song_node *search_song(struct song_node **head, char *artist, char *name);
struct song_node *search_artist(struct song_node **head, char *artist);
struct song_node **delete_song(struct song_node **head, char *artist, char *name);
struct song_node **clear_library(struct song_node **head);
void print_letter(struct song_node **head, char l);
void print_artist(struct song_node **head, char *artist);
void print_library(struct song_node **head);
void shuffle(struct song_node **head, int n);
int to_index(char c);

#endif
