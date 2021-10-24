#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "linkedlist.h"
#include "library.h"

struct song_node **make_library(){
  return calloc(27, sizeof(struct song_node *));
};

struct song_node **add_song_node(struct song_node **head, char *artist, char *name){
  head[to_index(artist[0])] = insert(head[to_index(artist[0])], artist, name);
  return head;
}

struct song_node *search_song(struct song_node **head, char *artist, char *name){
  return find_song(head[to_index(artist[0])], artist, name);
}

struct song_node *search_artist(struct song_node **head, char *artist){
  return find_artist_song(head[to_index(artist[0])], artist);
}

struct song_node **delete_song(struct song_node **head, char *artist, char *name){
  head[to_index(artist[0])] = remove_song(head[to_index(artist[0])], artist, name);
  return head;
}

struct song_node **clear_library(struct song_node **head){
  int i;
  for (int i = 0; i < 27; i++){
    free_list(head[i]);
  }
  return NULL;
}

int to_index(char c){
  if (tolower(c) >= 97 && tolower(c) <= 122){
    return tolower(c) - 97;
  }
  return 26;
}

void print_letter(struct song_node **head, char l){
  print_list(head[to_index(l)]);
  printf("\n");
}

void print_artist(struct song_node **head, char *artist){
  struct song_node *temp = head[to_index(artist[0])];
  printf("| ");
  while (temp){
    if (!strcasecmp(temp -> artist, artist)){
      printf("%s: %s", temp->artist, temp->name);
      printf(" |");
      printf(" ");
    }
    temp = temp -> next;
  }
  printf("\n\n");
}

void print_library(struct song_node **head){
  int i;
  for (int i = 0; i < 27; i++){
    if (head[i]){
      printf("%c: ", i + 97);
      print_list(head[i]);
    }
  }
  printf("\n");
}

/*void shuffle(struct song_node **head, int n){
  struct song_node *temp = NULL;
  for (int i = 0; i < n && )
    int r = rand() % 27;
    while (!head[r]){
      r = rand() % 27;
    }

}*/
