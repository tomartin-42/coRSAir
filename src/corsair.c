#include "corsair.h"

int main(int argc, char **argv) {

  t_corsair **s_data;

  s_data = (t_corsair **)malloc(sizeof(t_corsair*) * argc);
  s_data[argc] = NULL;

  for (int i = 1; i < argc; i++) {
    s_data[i - 1] = (t_corsair*)malloc(sizeof(t_corsair));
    s_data[i - 1]->filename = argv[i];
  }
  s_data[argc - 1] = NULL;
  main_read_cert(s_data); 
  print_s_data(s_data);
}
