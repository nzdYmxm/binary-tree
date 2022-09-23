#include <stdio.h>
#include <stdlib.h>

#include "print_module.h"
#include "documentation_module.h"

int main() {
    print_log(print_char, Module_load_success_message);

    int *availability_mask = check_available_documentation_module(validate, Documents_count, Documents);

    if (availability_mask != NULL) {
        char* documents[] = { Documents };

        for (int i = 0; i < Documents_count; i++) {
            char message[100];
            if (availability_mask[i])
                sprintf(message, "%-15s: available", documents[i]);
            else
                sprintf(message, "%-15s: unavailable", documents[i]);

            if (i == 0)
                printf("%s", message);
            else
                printf("\n%s", message);
        }

        free(availability_mask);
    }

    return 0;
}
