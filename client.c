#include "common.h"

#include <sys/types.h>
#include <unistd.h>
#include <time.h>

int main() {
const char* fifo_name = "server_fifo";
int client_fd = open(fifo_name, O_WRONLY);

while (1) {
time_t current_time = time(NULL);
char message[MAX_BUFF];
snprintf(message, sizeof(message), "Current time: %s", ctime(&current_time));

if (write(client_fd, message, strlen(message)) < 0) {
fprintf(stderr, "client.c: Ошибка при отправке данных (%s)\n", strerror(errno));
break;
}

// Приостановка выполнения клиента на 5 секунд
sleep(5);
}

close(client_fd);
return 0;
}
