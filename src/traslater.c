#include "../inc/traslater.h"
#include <openssl/rsa.h>

void get_privateRSA(t_corsair *s_data) { s_data->priv_rsa = RSA_new(); }

void main_traslater(t_corsair **s_data) {
  for (int i = 0; s_data[i] != NULL; ++i) {
    if (s_data[i]->flag == 1) {
      get_privateRSA(s_data[i]);
    }
  }
}
