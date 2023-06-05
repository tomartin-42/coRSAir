#ifndef _CORSAIR_H_
#define _CORSAIR_H_

#include <openssl/evp.h>
#include <openssl/pem.h>
#include <openssl/x509.h>
#include <stdint.h>

typedef struct s_corsair {
  char *filename;
  char *msg;
  EVP_PKEY *pkey;
  BIGNUM *n;
  BIGNUM *e;
  BIGNUM *p;
  BIGNUM *q;
  int8_t flag;
} t_corsair;

#include "../libft/libft.h"
#include "debug.h"
#include "decoder.h"
#include "read_cert.h"
#include "traslater.h"
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void free_struct(t_corsair **s_data);

#endif
