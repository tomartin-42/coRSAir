#include "../inc/corsair.h"

void read_cert(t_corsair *s_data) {
    // Crear un objeto BIO para el archivo de clave pública
    BIO *pubkey_bio = BIO_new_file(s_data->filename, "r");
    if (pubkey_bio == NULL) {
        printf("Error al abrir el archivo de la clave pública\n");
        s_data->pkey = NULL;
        return ;
    }

    // Leer la clave pública desde el objeto BIO
    s_data->pkey = PEM_read_bio_PUBKEY(pubkey_bio, NULL, NULL, NULL);
    if (s_data->pkey == NULL) {
        printf("Error al leer la clave pública\n");
        BIO_free(pubkey_bio);
        s_data->n = NULL;
        s_data->e = NULL;
        s_data->p = NULL;
        s_data->q = NULL;
        return ;
    }
    else
    {
        s_data->n = NULL;
        s_data->e = NULL;
        s_data->p = NULL;
        s_data->q = NULL;
        EVP_PKEY_get_bn_param(s_data->pkey, "n", &s_data->n);
        EVP_PKEY_get_bn_param(s_data->pkey, "e", &s_data->e);
    }
    BIO_free(pubkey_bio);
}

void main_read_cert(t_corsair **s_data) {
    int i = 0;
    while (s_data[i] != NULL) {
        read_cert(s_data[i]);
        ++i;
    }
}

