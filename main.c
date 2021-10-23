#include <stdio.h>

#include "linkedlist.h"

int main(void)
{
    struct song_node *alive = make_node("pearl jam", "alive");
    struct song_node *even_flow = make_node("pearl jam", "even flow");
    struct song_node *yellow = make_node("pearl jam", "yellow ledbetter");
    struct song_node *time = make_node("pink floyd", "time");

    printf("%d\n", song_cmp(even_flow, time));

    struct song_node *test = insert_front(yellow, "pearl jam", "even flow");
    test = insert_front(test, "pink floyd", "time");
    print_list(test);
    printf("\n%s\n", "Find First Artist Song");
    print_node(find_artist_song(test, "pearl jam"));
    printf("\n%s\n", "Print Random Node");
    print_node(rand_song(test));
    test = remove_song(test, "PEARL JAM", "yellow LEDBETTER");
    printf("\n%s\n", "After Removing Node");
    print_list(test);
    printf("\n%s\n", "After Freeing List");
    test = free_list(test);
    print_list(test);
}
