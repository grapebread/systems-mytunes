#include <stdio.h>

#include "linkedlist.h"

int main(void)
{
    struct song_node *alive = make_node("pearl jam", "alive");
    struct song_node *even_flow = make_node("pearl jam", "even flow");
    struct song_node *yellow = make_node("pearl jam", "yellow ledbetter");
    struct song_node *time = make_node("pink floyd", "time");

    printf("%d\n", song_cmp(even_flow, time));
}