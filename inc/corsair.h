#ifndef _CORSAIR_H_
#define _CORSAIR_H_

#include <openssl/evp.h>
#include <openssl/pem.h>
#include <openssl/x509.h>

typedef struct s_corsair {
  char *filename;
  char *msg;
  EVP_PKEY *pkey;
  BIGNUM *n;
  BIGNUM *e;
  BIGNUM *p;
  BIGNUM *q;


} t_corsair;

#include "../libft/libft.h"
#include "read_cert.h"
#include "debug.h"
#include "decoder.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>


#endif
