#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#include "linkedlist.h"
#include "library.h"
int main(void)
{
    srand(time(NULL));

    printf("LINKED LIST TESTS\n");
    printf("\n===================================\n");

    struct song_node *list = NULL;
    list = insert(list, "pearl jam", "even flow");
    list = insert(list, "ac/dc", "thunderstruck");
    list = insert(list, "pearl jam", "alive");
    list = insert(list, "RADIOHEAD", "paranoid android");
    list = insert(list, "radiohead", "STREET SPIRIT (fade out)");
    list = insert(list, "eminem", "godzilla");
    list = insert(list, "taishi", "reverie for the another sphere");
    list = insert(list, "shibayanrecords", "・－・・ －－－ ・・・－ ・");
    list = insert(list, "21 PILOTS", "BLURRYFACE");
    list = insert(list, "pink floyd", "time");

    printf("\ntesting print_list:\n\t");
    print_list(list);
    printf("\n===================================\n");

    printf("\ntesting print_node:\n\t");
    print_node(list);
    printf("\n===================================\n");

    printf("\ntesting find_song:\n");
    printf("looking for {pearl jam: alive}:\n\t");
    print_node(find_song(list, "pearl jam", "alive"));
    printf("\nlooking for {taishi, false god}:\n\t");
    print_node(find_song(list, "taishi", "false god"));
    printf("\n===================================\n");

    printf("\ntesting find_artist:\n");
    printf("looking for {pearl jam}:\n\t");
    print_list(find_artist(list, "pearl jam"));
    printf("\nlooking for {shibayanrecords:\n\t");
    print_list(find_artist(list, "shibayanrecords"));
    printf("\nlooking for {presidents of the united states of america}:\n\t");
    print_list(find_artist(list, "presidents of the united states of america"));
    printf("\n===================================\n");

    printf("\ntesting song_cmp:\n");
    printf("comparing {pearl jam: even flow} to {pearl jam: even flow}:\n\t");
    printf("%d", song_cmp(find_song(list, "pearl jam", "even flow"), find_song(list, "pearl jam", "even flow")));
    printf("\ncomparing {pearl jam: even flow} to {pearl jam: alive}:\n\t");
    printf("%d", song_cmp(find_song(list, "pearl jam", "even flow"), find_song(list, "pearl jam", "alive")));
    printf("\ncomparing {pearl jam: alive} to {pearl jam: even flow}:\n\t");
    printf("%d", song_cmp(find_song(list, "pearl jam", "alive"), find_song(list, "pearl jam", "even flow")));
    printf("\ncomparing {pearl jam: alive} to {pink floyd: time}:\n\t");
    printf("%d", song_cmp(find_song(list, "pearl jam", "alive"), find_song(list, "pink floyd", "time")));
    printf("\n===================================\n");

    printf("\ntesting rand_song:\n");
    printf("\t");
    print_node(rand_song(list));
    printf("\n");
    printf("\t");
    print_node(rand_song(list));
    printf("\n");
    printf("\t");
    print_node(rand_song(list));
    printf("\n");
    printf("\t");
    print_node(rand_song(list));
    printf("\n");
    printf("\t");
    print_node(rand_song(list));
    printf("\n===================================\n");

    printf("\ntesting remove_song:\n");
    printf("removing {ac/dc: thunderstruck}:\n\t");
    list = remove_song(list, "ac/dc", "THUNDERSTRUCK");
    print_list(list);
    printf("\nremoving {shibayanrecords: ・－・・ －－－ ・・・－ ・}:\n\t");
    list = remove_song(list, "shibayanrecords", "・－・・ －－－ ・・・－ ・");
    print_list(list);
    printf("\nremoving {21 pilots: blurryface}:\n\t");
    list = remove_song(list, "21 pilots", "blurryface");
    print_list(list);
    printf("\nremoving {ac/dc: thunderstruck} (again):\n\t");
    list = remove_song(list, "ac/dc", "THUNDERSTRUCK");
    print_list(list);
    printf("\n===================================\n");

    printf("\ntesting free_list:\n");
    printf("list before free_list:\n\t");
    print_list(list);
    list = free_list(list);
    printf("\nlist after free_list:\n\t");
    print_list(list);
    printf("\n===================================\n");

    printf("\n\nLIBRARY TESTS\n");
    printf("===================================\n");

    struct song_node **library = make_library();

    printf("\ntesting print_letter before add:\n\t");
    print_letter(library, 2);
    printf("\n===================================\n");

    printf("\ntesting print_library before add:\n\t");
    print_library(library);
    printf("\n===================================\n");

    library = add_song_node(library, "pearl jam", "even flow");
    library = add_song_node(library, "ac/dc", "thunderstruck");
    library = add_song_node(library, "pearl jam", "alive");
    library = add_song_node(library, "RADIOHEAD", "paranoid android");
    library = add_song_node(library, "radiohead", "STREET SPIRIT (fade out)");
    library = add_song_node(library, "eminem", "godzilla");
    library = add_song_node(library, "taishi", "reverie for the another sphere");
    library = add_song_node(library, "shibayanrecords", "・－・・ －－－ ・・・－ ・");
    library = add_song_node(library, "21 PILOTS", "BLURRYFACE");
    library = add_song_node(library, "pink floyd", "time");
    library = add_song_node(library, "rich brian", "kids");

    printf("\ntesting print_letter after add:\n\t");
    print_letter(library, 'p');
    printf("\n===================================\n");

    printf("\ntesting print_library after add:\n");
    print_library(library);
    printf("===================================\n");

    printf("\ntesting search:\n");
    printf("looking for {pearl jam: alive}:\n\t");
    print_node(search_song(library, "pearl jam", "alive"));
    printf("\nlooking for {taishi: reverie for the another sphere}:\n\t");
    print_node(search_song(library, "taishi", "reverie for the another sphere"));
    printf("\nlooking for {eminem, stan}:\n\t");
    print_node(search_song(library, "eminem", "stan"));
    printf("\n===================================\n");

    printf("\ntesting search_artist:\n");
    printf("looking for {pearl jam}:\n\t");
    print_list(search_artist(library, "pearl jam"));
    printf("\nlooking for {radiohead}:\n\t");
    print_list(search_artist(library, "radiohead"));
    printf("\nlooking for {rich brian}:\n\t");
    print_list(search_artist(library, "rich brian"));
    printf("\nlooking for {coda}:\n\t");
    print_list(search_artist(library, "coda"));
    printf("\n===================================\n");

    printf("\ntesting delete_song:\n");
    printf("deleting {shibayanrecords: ・－・・ －－－ ・・・－ ・}:\n");
    library = delete_song(library, "shibayanrecords", "・－・・ －－－ ・・・－ ・");
    print_library(library);
    printf("deleting {ac/dc: thunderstruck}:\n");
    library = delete_song(library, "AC/DC", "THUNDERSTRUCK");
    print_library(library);
    printf("deleting {shibayanrecords: myoisia}:\n");
    library = delete_song(library, "shibayanrecords", "myoisia");
    print_library(library);
    printf("\n===================================\n");

    printf("\ntest shuffle:\n");
    printf("test 1 (3):\n");
    shuffle(library, 3);
    printf("test 2 (5):\n");
    shuffle(library, 5);
    printf("===================================\n");

    printf("\ntest clear_library:\n");
    printf("library before free:\n");
    print_library(library);
    printf("library after free:\n");
    library = clear_library(library);
    print_library(library);
    printf("\n===================================\n");

    free(library);

    return 0;
}
