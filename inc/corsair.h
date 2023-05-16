#ifndef _CORSAIR_H_
#define _CORSAIR_H_

#include "../libft/libft.h"
#include "read_cert.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <openssl/x509.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct s_corsair {
  char *filename;
  X509 *cert;

} t_corsair;

#endif
