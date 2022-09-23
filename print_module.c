#include <stdio.h>
#include <time.h>

#include "print_module.h"

void current_time(char *buffer) {
    int hours, minutes, seconds;
    time_t now;

    time(&now);
    struct tm *local = localtime(&now);
    hours = local->tm_hour;
    minutes = local->tm_min;
    seconds = local->tm_sec;

    sprintf(buffer, "%02d:%02d:%02d", hours, minutes, seconds);
}

void print_as_is(char (*print)(char), char* message) {
    for (int i = 0; message[i] != '\0'; i++)
        print(message[i]);
}

void print_log(char (*print)(char), char* message) {
    char time_msg[20];
    current_time(time_msg);

    print_as_is(print, Log_prefix);
    print_as_is(print, " ");
    print_as_is(print, time_msg);
    print_as_is(print, " ");
    print_as_is(print, message);
    print_as_is(print, "\n");
}

char print_char(char ch) {
    return putchar(ch);
}
