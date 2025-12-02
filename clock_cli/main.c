#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main() {
time_t now;

while (1) {
	now = time(NULL);
	struct tm *t = localtime(&now);
	printf("\r%d:%d:%d", t->tm_hour,t->tm_min,t->tm_sec);
	fflush(stdout);
	sleep(1);
}
return 0;
}
