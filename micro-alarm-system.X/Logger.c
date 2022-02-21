#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "UART.h"

char *concat(const char *s1, const char *s2)
{
    const size_t len1 = strlen(s1);
    const size_t len2 = strlen(s2);
    char *result = malloc(len1 + len2 + 1); // +1 for the null-terminator
    // in real code you would check for errors in malloc here
    memcpy(result, s1, len1);
    memcpy(result + len1, s2, len2 + 1); // +1 to copy the null-terminator
    return result;
}

struct log
{
    char *data;
    struct log *next;
};

struct log *head = NULL;
struct log *current = NULL;

//display the list
void printList()
{
    struct log *ptr = head;

    //start from the beginning
    while (ptr != NULL)
    {
        putU4_string(ptr->data);
        putU4_string(" \n");
        ptr = ptr->next;
    }
    putU4_string("\n\n");
}

//insert link at the first location
void insert(char *data)
{
    //create a link
    struct log *link = (struct log *)malloc(sizeof(struct log));

    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char s[64];
    strftime(s, sizeof(s), "%c", tm);

    char *dataLog = concat(s, ": ");
    dataLog = concat(dataLog, data);

    link->data = dataLog;
    link->next = head;
    head = link;
}

void empty()
{
    head = NULL;
    current = NULL;
}