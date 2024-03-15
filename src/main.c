#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/marshrut.h"

int main(void) {

  int n;
  printf("Enter amount of marshruts to add: ");
  scanf("%d", &n);
  MARSHRUT* marshruts = createArrayOfMarshrut(n);
  printf("\n");
  MARSHRUT longest = getLongestMarshrut(marshruts, n);
  printf("\n");
  printf("The longest marshrut is %d with length %d\n", longest.number, longest.length);

  sortByNumber(marshruts, n);
  printf("Marshruts sorted by number: \n");
  for (int i = 0; i < n; i++) {
    printMarshrut(marshruts[i]);
    printf("---\n");
  }


  printf("\nEnter place: ");
  getchar();
  char place[100];
  fgets(place, sizeof(place), stdin);
  place[strcspn(place, "\n")] = '\0'; // Remove newline character if present
  printStartAndEndInSamePlace(marshruts, n, place);

  return 0;
}
