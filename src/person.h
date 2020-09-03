/**
 * @file       person.h
 * @author     Ondřej Ševčík
 * @date       6/2019
 * @brief      Header file of Person module
 * **************************************************************
 * @par       COPYRIGHT NOTICE (c) 2019 TBU in Zlin. All rights reserved.
 */

#ifndef PERSON_H
#define PERSON_H

/* Public includes -------------------------------------------------------- */
#include <stdbool.h>
#include <stdio.h>

/* Person structure ---------------------------------------------------------*/
typedef struct {
  char name[256];
  unsigned int age;
  unsigned int weight;
  unsigned int height;
} tPerson;

/* Public Person API ------------------------------------------------------- */
/**
 * @brief       Loads data to an pointer at Person Array
 * @param[in]   fileName    Pointer at opened file
 * @param[out]  data        Pointer at array of structure tPerson
 * @return  Returns the number of persons in an array, returns -1 if opening
 * file failed
 */
int Person_LoadCSV(FILE *fileName, tPerson *data, unsigned arraySize);

/**
 * @brief       Calculates the avarage data from input array of structure
 *              tPerson
 * @param[in]   data            Pointer at array of structure tPerson
 * @param[in]   sizeOfAnArray   Number of persons in array
 * @param[out]  averageWeight   Pointer at calculated output value
 * @param[out]  averageHeight   Pointer at calculated output value
 * @param[out]  averageAge      Pointer at calculated output value
 * @return      Return true if avarage data were calculated correctly,
 * false if input data are NULL or size of an array is less than 1
 */
bool Person_GetAverageData(tPerson *data, unsigned sizeOfAnArray,
                           double *averageWeight, double *averageHeight,
                           double *averageAge);

/**
 * @brief       Finds the indexes of the youngest and oldest person in array
 * @param[in]   data            Pointer at array of structure tPerson
 * @param[in]   sizeOfAnArray   Number of persons in array
 * @param[out]  youngest        Pointer at index from an array at youngest
 *                              tPerson
 * @param[out]  oldest          Pointer at index from array at oldest tPerson
 * @return      Return true if indexes were set, false if input data are null
 *              or size of an array is 0 or less
 */
bool Person_Extremes(tPerson *data, unsigned sizeOfAnArray,
                     unsigned int *youngest, unsigned int *oldest);

#endif  // PERSON_H
