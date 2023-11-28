#include "common.h"
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>

void* handle_client(void* arg) {
char *fifo_name = (char *)arg;
int server_fd = open(fifo_name, O_RDONLY);
int n;
char buff[MAX_BUFF];

while ((n = read(server_fd, buff, MAX_BUFF)) > 0) {
if (write(1, buff, n) != n) {
fprintf(stderr, "server.c: Ошибка вывода (%s)\n", strerror(errno));
break;
}
}

close(server_fd);
return NULL;
}

int main() {
const char* fifo_name = "server_fifo";
mkfifo(fifo_name, 0666);

pthread_t client_threads[NUM_CLIENTS];

for (int i = 0; i < NUM_CLIENTS; i++) {
pthread_create(&client_threads[i], NULL, handle_client, fifo_name);
}

// Ожидание потоков
for (int i = 0; i < NUM_CLIENTS; i++) {
pthread_join(client_threads[i], NULL);
}

// Остальной код сервера
return 0;
}
