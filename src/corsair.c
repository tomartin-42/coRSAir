#include "corsair.h"

void free_struct(t_corsair **s_data) {
  int i = 0;
  while (s_data[i] != NULL) {
    free(s_data[i]->msg);
    EVP_PKEY_free(s_data[i]->pkey);
    BN_free(s_data[i]->n);
    BN_free(s_data[i]->e);
    BN_free(s_data[i]->p);
    BN_free(s_data[i]->q);
    if (s_data[i]->flag == 1) {
      // BN_free(s_data[i]->private_key);
      printf("IIIIIIIHIK\n");
    }
    free(s_data[i]);
    i++;
  }
  free(s_data);
}

int main(int argc, char **argv) {

  t_corsair **s_data;

  s_data = (t_corsair **)malloc(sizeof(t_corsair *) * argc);
  s_data[argc] = NULL;

  for (int i = 1; i < argc; i++) {
    s_data[i - 1] = (t_corsair *)malloc(sizeof(t_corsair));
    s_data[i - 1]->filename = argv[i];
    s_data[i - 1]->msg = ft_strdup(argv[i]);
    char *tmp = ft_strchr(s_data[i - 1]->msg, '.');
    *(tmp + 1) = 'b';
    *(tmp + 2) = 'i';
    *(tmp + 3) = 'n';
  }

  s_data[argc - 1] = NULL;
  main_read_cert(s_data);
  main_decoder(s_data);
  print_only_break(s_data);
  free_struct(s_data);
}
