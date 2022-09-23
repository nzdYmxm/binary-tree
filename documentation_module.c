#include "documentation_module.h"
#include <stdarg.h>
#include <stdlib.h>

int validate(char* data) {
    int validation_result = !strcmp(data, Available_document);
    return validation_result;
}

int* check_available_documentation_module(int (*validate)(char*), int document_count, ...) {
    va_list args;
    va_start(args, document_count);

    int* validity = (int*) malloc(sizeof(int) * document_count);

    if (validity != NULL) {
        for (int i = 0; i < document_count; i++) {
            char *document = va_arg(args, char*);
            validity[i] = validate(document);
        }
    }

    va_end(args);
    return validity;
}
