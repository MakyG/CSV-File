/**
 * @file       main.c
 * @author     Ondřej Ševčík
 * @date       6/2019
 * @brief      Main file
 * **************************************************************
 * @par       COPYRIGHT NOTICE (c) 2019 TBU in Zlin. All rights reserved.
 */

/* Private includes -------------------------------------------------------- */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "person.h"

/* Private defines --------------------------------------------------------- */
#define MAX_PERSON_ARRAY (256u)

int main(int argc, char** argv) {
  double averageWeight = 0, averageHeight = 0, averageAge = 0;
  int loadedPersons = 0;
  unsigned int youngest = 0, oldest = 0;

  FILE* openedFile = stdin;
  if (argc == 2) {
    openedFile = fopen(argv[1], "r");
    if (openedFile == NULL) {
      return 0;
    }
  }

  tPerson personsArray[MAX_PERSON_ARRAY];

  loadedPersons = Person_LoadCSV(openedFile, personsArray, MAX_PERSON_ARRAY);
  if (argc == 2) {
    fclose(openedFile);
  }
  if (loadedPersons == -1) {
    fprintf(stderr, "Error loading file\n");
    return 0;
  }

  if (Person_GetAverageData(personsArray, (unsigned int)loadedPersons,
                            &averageWeight, &averageHeight, &averageAge)) {
    printf(
        "The average weight is: %.2f\n"
        "The average height is: %.2f\n"
        "The average age is: %.2f\n",
        averageWeight, averageHeight, averageAge);
  }

  if (Person_Extremes(personsArray, (unsigned int)loadedPersons, &youngest,
                      &oldest)) {
    printf(
        "The youngest is %s - %d years old\n"
        "The oldest is: %s - %d years old\n",
        personsArray[youngest].name, personsArray[youngest].age,
        personsArray[oldest].name, personsArray[oldest].age);
  }

  return 0;
}
