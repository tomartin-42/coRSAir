#include "../inc/decoder.h"
/*
BIGNUM *gcd = BN_new();
BN_CTX *ctx = BN_CTX_new();

BN_gcd(gcd, a, b, ctx);

// Utiliza el valor de gcd como desees

BN_free(gcd);
BN_CTX_free(ctx);
*/
void decoder(t_corsair **s_data, int i) {
  for (int j = i + 1; s_data[j] != NULL; ++j) {
    BIGNUM *gcd = BN_new();
    BN_CTX *ctx = BN_CTX_new();

    BN_gcd(gcd, s_data[i]->n, s_data[j]->n, ctx);

    if (BN_cmp(gcd, BN_value_one())) {
      if (s_data[j]->p == NULL || !(BN_cmp(s_data[j]->p, BN_value_one()))) {
        s_data[j]->flag = 1;
        s_data[j]->p = BN_dup(gcd);
      }
      if (s_data[i]->p == NULL || !(BN_cmp(s_data[i]->p, BN_value_one()))) {
        s_data[i]->flag = 1;
        s_data[i]->p = BN_dup(gcd);
      }
    }
    BN_CTX_free(ctx);
    BN_free(gcd);
  }
}

void main_decoder(t_corsair **s_data) {
  int i = 0;
  while (s_data[i] != NULL) {
    decoder(s_data, i);
    ++i;
  }
}
