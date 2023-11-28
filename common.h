
#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define FIFO_NAME "fifo"
#define MAX_BUFF 80
#define NUM_CLIENTS 2
#define SERVER_RUNTIME 30
#define CLIENT_SLEEP_INTERVAL 5 // Добавьте эту строку с интервалом сна клиента

#endif /* COMMON_H */ 
