#include <p32xxxx.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

struct Log {
    char message[255];
    int timestamp;
    struct Log * next;
};

struct Logs {
    int size;
    struct Log * head;
};

struct Logs * logger;

void LOGGER_Init () {
    logger = (struct Logs *) malloc(sizeof(struct Logs));
}

struct Log * addLog(char * message) {
    // Create log element
    struct Log * logElement = (struct Log *) malloc(sizeof(struct Log));
    strcpy(logElement->message,message); // Set message
    // logElement->timestamp = time(NULL); FIXME: FINISH THIS
    
    if (logger->head == NULL) {
        // First element
        logger->head = logElement;
    } else {
        // Append to end
        logger->head->next = logElement;
    }
    // return log element
    return logElement;
}
