#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/interface.h"

MARSHRUT* createArrayOfMarshrut(int amount) {
  MARSHRUT* arr = (MARSHRUT*)malloc(amount * sizeof(MARSHRUT));
  if (arr == NULL) {
    return NULL;
  }

  for (int i = 0; i < amount; i++) {
    MARSHRUT m;

    printf("Enter number of marshrut %d: ", i + 1);
    scanf("%d", &m.number);

    printf("Enter start of marshrut %d: ", i + 1);
    getchar();
    char startBuffer[100];
    fgets(startBuffer, sizeof(startBuffer), stdin);
    startBuffer[strcspn(startBuffer, "\n")] = '\0'; // Remove newline character if present
    m.start = strdup(startBuffer); // dynamically allocate memory for start string

    printf("Enter end of marshrut %d: ", i + 1);

    char endBuffer[100];
    fgets(endBuffer, sizeof(endBuffer), stdin);
    endBuffer[strcspn(endBuffer, "\n")] = '\0'; // Remove newline character if present
    m.end = strdup(endBuffer); // dynamically allocate memory for end string

    printf("Enter length of marshrut %d: ", i + 1);
    scanf("%d", &m.length);

    arr[i] = m;
  }
  return arr;
}
MARSHRUT getLongestMarshrut(MARSHRUT* arr, int arrLen) {
  int length = 0;
  int pos = 0;
  for (int i = 0; i < arrLen; i++) {
    if (arr[i].length > length) {
      length = arr[i].length;
      pos = i;
    }
  }
  return arr[pos];
}

int compare(const void* a, const void* b){
  MARSHRUT A = *(MARSHRUT*)a;
  MARSHRUT B = *(MARSHRUT*)b;
  return A.number > B.number;
}

void sortByNumber(MARSHRUT* arr, int size) {
  qsort(arr, size, sizeof(MARSHRUT), compare);
}

void printMarshrut(MARSHRUT m) {
  printf("Marshrut number: %d\n", m.number);
  printf("Marshrut start: %s\n", m.start);
  printf("Marshrut end: %s\n", m.end);
  printf("Marshrut length: %d\n", m.length);
}

void printStartAndEndInSamePlace(MARSHRUT* arr, int size, char* place) {
  printf("Marshruts that start and end in place: %s\n", place);
  
  for (int i = 0; i < size; i++) {
    if (*arr[i].end == *arr[i].start &&* arr[i].end == *place) {
      printMarshrut(arr[i]);
    }
    printf("---\n");
  }
}

