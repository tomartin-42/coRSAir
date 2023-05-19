#include "corsair.h"

int main(int argc, char **argv) {

  t_corsair **s_data;

  s_data = (t_corsair **)malloc(sizeof(t_corsair*) * argc);
  s_data[argc] = NULL;

  for (int i = 1; i < argc; i++) {
    s_data[i - 1] = (t_corsair*)malloc(sizeof(t_corsair));
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
  print_s_ones(s_data);

}
