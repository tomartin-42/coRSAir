#include "../inc/debug.h"

void print_s_data(t_corsair **s_data) {
    int i = 0;
    while (s_data[i] != NULL) {
        printf("Filename %s\n", s_data[i]->filename);
        printf("Msg %s\n", s_data[i]->msg);
        printf("Pkey %p\n", s_data[i]->pkey);
        printf("N %p\n", s_data[i]->n);
        printf("E %p\n", s_data[i]->e);
        printf("P %p\n", s_data[i]->p);
        printf("Q %p\n", s_data[i]->q);
        i++;
    }
}

void print_s_ones(t_corsair **s_data){
    int i = 0;
    while (s_data[i] != NULL) {
        if(s_data[i]->n == NULL || !BN_cmp(s_data[i]->n, BN_value_one())) {
            printf("Filename %s\n", s_data[i]->filename);
            printf("Msg %s\n", s_data[i]->msg);
            printf("Pkey %p\n", s_data[i]->pkey);
            printf("N %p\n", s_data[i]->n);
            printf("E %p\n", s_data[i]->e);
            printf("P %p\n", s_data[i]->p);
            printf("Q %p\n", s_data[i]->q);
            i++;
        }
    }
}