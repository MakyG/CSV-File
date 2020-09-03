/**
 * @file       tests.c
 * @author     Ondřej Ševčík
 * @date       6/2019
 * @brief      Tests for task 1
 * **************************************************************
 * @par       COPYRIGHT NOTICE (c) 2019 TBU in Zlin. All rights reserved.
 */

/* Private includes -------------------------------------------------------- */
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

#include "../src/person.h"
#include "minunit.h"

////////////////////////////// IMPORTANT ///////////////////////////////////////
/////////// Source repository: https://github.com/siu/minunit //////////////////
/////////// For more info consult with this page ///////////////////////////////
////////////////////////////////////////////////////////////////////////////////
/* Private variables -------------------------------------------------------- */
char **path;
#define PERSON_ARRAY_SIZE (256u)

MU_TEST(test_load_csv) {
  tPerson person[PERSON_ARRAY_SIZE];
  FILE *file;
  file = fopen(path[0], "r");
  mu_assert_int_eq(4, Person_LoadCSV(file, person, PERSON_ARRAY_SIZE));
  if (file) fclose(file);

  file = fopen(path[1], "r");
  mu_assert_int_eq(0, Person_LoadCSV(file, person, PERSON_ARRAY_SIZE));
  if (file) fclose(file);

  file = fopen(path[2], "r");
  mu_assert_int_eq(3, Person_LoadCSV(file, person, PERSON_ARRAY_SIZE));
  if (file) fclose(file);

  file = fopen("../../task1/test_files/input4.txt", "r");
  mu_assert_int_eq(-1, Person_LoadCSV(file, person, PERSON_ARRAY_SIZE));
  if (file) fclose(file);

  mu_assert_int_eq(-1, Person_LoadCSV(NULL, NULL, PERSON_ARRAY_SIZE));
}

MU_TEST(test_average_data) {
  double averageWeight = 0, averageHeight = 0, averageAge = 0;
  int count = 0;
  tPerson person[256];
  FILE *file;
  {
    file = fopen(path[0], "r");
    count = Person_LoadCSV(file, person, PERSON_ARRAY_SIZE);
    if (file) fclose(file);

    Person_GetAverageData(person, count, &averageWeight, &averageHeight,
                          &averageAge);
    mu_assert_double_eq(56.50, averageWeight);
    mu_assert_double_eq(145, averageHeight);
    mu_assert_double_eq(30.25, averageAge);
  }
  {
    file = fopen(path[1], "r");
    count = Person_LoadCSV(file, person, PERSON_ARRAY_SIZE);
    if (file) fclose(file);

    mu_check(!Person_GetAverageData(person, count, &averageWeight,
                                    &averageHeight, &averageAge));
    mu_assert_double_eq(56.50, averageWeight);
    mu_assert_double_eq(145, averageHeight);
    mu_assert_double_eq(30.25, averageAge);
  }
  {
    file = fopen(path[2], "r");
    count = Person_LoadCSV(file, person, PERSON_ARRAY_SIZE);
    if (file) fclose(file);

    Person_GetAverageData(person, count, &averageWeight, &averageHeight,
                          &averageAge);
    mu_assert_double_eq(71.66666666667, averageWeight);
    mu_assert_double_eq(166.66666667, averageHeight);
    mu_assert_double_eq(40.00, averageAge);
  }
  { mu_check(!Person_GetAverageData(NULL, count, NULL, NULL, NULL)); }
}

MU_TEST(test_Person_Extremes) {
  int count = 0;
  unsigned int youngest = 0, oldest = 0;
  tPerson person[256];
  FILE *file;
  {
    file = fopen(path[0], "r");
    count = Person_LoadCSV(file, person, PERSON_ARRAY_SIZE);
    if (file) fclose(file);

    mu_check(Person_Extremes(person, count, &youngest, &oldest));
    mu_assert_int_eq(1, (int)youngest);
    mu_assert(2 == oldest, "Wrong index of oldest person.");
  }
  {
    file = fopen(path[1], "r");
    count = Person_LoadCSV(file, person, PERSON_ARRAY_SIZE);
    if (file) fclose(file);

    mu_check(!Person_Extremes(person, count, &youngest, &oldest));
  }
  {
    file = fopen(path[2], "r");
    count = Person_LoadCSV(file, person, PERSON_ARRAY_SIZE);
    if (file) fclose(file);

    mu_check(Person_Extremes(person, count, &youngest, &oldest));
    mu_assert(1 == oldest, "Wrong index of oldest person.");
    mu_assert(0 == youngest, "Wrong index of youngest person.");
  }
  { mu_check(!Person_Extremes(NULL, count, NULL, NULL)); }
}

MU_TEST_SUITE(test_suite) {
  MU_RUN_TEST(test_load_csv);
  MU_RUN_TEST(test_average_data);
  MU_RUN_TEST(test_Person_Extremes);
}

int main(int argc, char **argv) {
  if (argc != 4) {
    fprintf(stderr, "Expecting 3 input files\n");
    return 0;
  }

  path = &argv[1];

  MU_RUN_SUITE(test_suite);
  MU_REPORT();

  return 0;
}
