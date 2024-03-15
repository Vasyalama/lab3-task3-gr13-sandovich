#ifndef LAB3_3_MARSHRUT_H
#define LAB3_3_MARSHRUT_H

typedef struct{
  int number;
  char* start;
  char* end;
  int length;
} MARSHRUT;

MARSHRUT* createArrayOfMarshrut(int amount);
MARSHRUT getLongestMarshrut(MARSHRUT* arr, int arrLen);
int compare(const void* a, const void* b);
void sortByNumber(MARSHRUT* arr, int size);
void printMarshrut(MARSHRUT m);
void printStartAndEndInSamePlace(MARSHRUT* arr, int size, char* place);

#endif
