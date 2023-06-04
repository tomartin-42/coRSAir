#include "../inc/traslater.h"

void get_privateRSA(t_corsair *s_data) { ; }

void main_traslater(t_corsair **s_data) {
  for (int i = 0; s_data[i] != NULL; ++i) {
    if (s_data[i]->flag == 1) {
      get_privateRSA(s_data[i]);
    }
  }
}
