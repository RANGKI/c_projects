#include <stdio.h>
#include <unistd.h>

int main() {
int second,minute,hour;
second=minute=hour=0;
printf("%d",hour);
while (1) {
	second += 1;
	sleep(1);
	if (second == 60) {
		second = 0;
		minute += 1;
	} 
	if (minute == 60) { 
                minute = 0;
                hour += 1;
        }
	if (hour == 24) {
		hour = 0;
		minute = 0;
		second = 0;
	}
	printf("\r%d:%d:%d",hour,minute,second);
	fflush(stdout);
}
return 0;
}
