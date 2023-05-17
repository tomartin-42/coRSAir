#include "../inc/debug.h"

void print_s_data(t_corsair **s_data) {
    int i = 0;
    while (s_data[i] != NULL) {
        printf("Filename %s\n", s_data[i]->filename);
        printf("Pkey %p\n", s_data[i]->pkey);
        i++;
    }
}