#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <strings.h>

#include "linkedlist.h"
#include "library.h"
int main(void)
{
    srand(time(NULL));
    printf("%s\n","LINKED LIST TESTS");
    printf("%s\n","---------------------");
    struct song_node *alive = make_node("pearl jam", "alive");
    struct song_node *even_flow = make_node("pearl jam", "even flow");
    struct song_node *yellow = make_node("pearl jam", "yellow ledbetter");
    struct song_node *time = make_node("pink floyd", "time");

    struct song_node *test = insert(alive, "pink floyd", "time");
    print_list(test);
    test = insert(test, "pearl jam", "yellow ledbetter");
    print_list(test);
    printf("\n%s\n", "Find First Artist Song");
    print_node(find_artist_song(test, "pearl"));
    printf("\n%s\n", "Print Random Node");
    print_node(rand_song(test));
    test = remove_song(test, "PEARL JAM", "yellow LEDBETTER");
    printf("\n%s\n", "After Removing Node");
    print_list(test);
    printf("\n%s\n", "After Freeing List");
    test = free_list(test);
    print_list(test);
    printf("%s\n","MUSIC LIBRARY TESTS");
    printf("%s\n","---------------------");
    struct song_node **library = make_library();
    printf("%s\n","Adding Songs");
    library = add_song_node(library, "pearl jam", "even flow");
    library = add_song_node(library, "pearl jam", "yellow ledbetter");
    library = add_song_node(library, "ad/dc", "thundershock");
    library = add_song_node(library, "radiohead", "paranoid android");
    print_library(library);
    printf("%s\n", "Print Letter: a");
    print_letter(library, 'a');
    printf("%s\n", "Finding Artist Songs");
    print_artist(library, "pearl JAM");
    printf("%s\n", "Find Song | ad/dc: thundershock");
    print_node(search_song(library, "ad/dc", "thundershock"));
    printf("\n");
    printf("%s\n", "Find Song | yes: no");
    print_node(search_song(library, "yes", "no"));
    printf("\n");
    printf("%s\n", "Deleting Song | pearl jam: yellow ledbetter");
    library = delete_song(library, "pearl jam", "YELLOW LEDBETTER");
    print_library(library);
    //shuffle(library, 5);
}
