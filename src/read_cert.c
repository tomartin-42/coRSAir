#include "../inc/corsair.h"

void read_cert(t_corsair *s_data) {
    usigned char    **buf;
    int             fd;

    fd = open(s_data->filename, O_RDONLY);
    if (fd == -1) {
        printf("Error opening file %s\n", s_data->filename);
        s_data->cert = NULL;
        return ;
    }
    while (get_next_line(fd, buf) > 0) {}
    
    s_data->cert = d2i_X509(NULL, (const unsigned char **)&buf[0], bytes_read);
    if (cert == NULL) {
        printf("Error al parsear el certificado\n");
        close(cert_file);
        return 1;
    }

}

void main_read_cert(t_corsair **s_data) {
    int i = 0;
    while (s_data[i] != NULL) {
        read_cert(s_data[i]);
    }

}

