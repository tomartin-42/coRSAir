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
  for (int i = 0; s_data[i] != NULL; i++) {
    printf("Filename %s\n", s_data[i]->filename);
  }
}
