#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

char* getCurrentHumanTime();

typedef struct {
  char* title;
  char* body;
  char* createTimeHuman;
  char* completeTimeHuman;
  time_t createTime;
  time_t completeTime;
} task;

int main (int argc, char** args) {

  char* currentTime = getCurrentHumanTime();

  printf("The time is: %s\n", currentTime);

  free(currentTime);

  return EXIT_SUCCESS;
}

char* getCurrentHumanTime() {
  char* formatTime = malloc((sizeof(char) * 20));
  time_t epoch = time(NULL);
  struct tm* local_time = localtime(&epoch);
  strftime(formatTime, (sizeof(formatTime) * 20), "%Y-%m-%d %H:%M:%S", local_time);

  return formatTime;
}
