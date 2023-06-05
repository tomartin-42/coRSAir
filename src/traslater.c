#include "../inc/traslater.h"
#include <openssl/bn.h>
#include <openssl/rsa.h>

void get_privateRSA(t_corsair *s_data) {
  // s_data->n = BN_new();
  BN_CTX *ctx = BN_CTX_new();
  // Calcular modulo
  BN_mul(s_data->n, s_data->p, s_data->q, ctx);

  // Calcular coeficiente Euler
  // BN_sub_word(s_data->p, 1);
  // BN_sub_word(s_data->q, 1);
  // s_data->e = BN_new();
  // BN_mul(s_data->e, s_data->p, s_data->q, ctx);
  BN_CTX_free(ctx);
}

void main_traslater(t_corsair **s_data) {
  for (int i = 0; s_data[i] != NULL; ++i) {
    if (s_data[i]->flag == 1) {
      get_privateRSA(s_data[i]);
    }
  }
}
