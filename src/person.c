/**
 * @file       person.c
 * @author     Tomáš Makyča
 * @date       17/02/2020
 * @brief      Source file of Person module
 * *****************************************************************
 * @par       COPYRIGHT NOTICE (c) 2019 TBU in Zlin. All rights reserved.
 */

/* Private includes -------------------------------------------------------- */
#include "person.h"

/* Public function definitions --------------------------------------------- */
int Person_LoadCSV(FILE *file, tPerson *personsArray, unsigned arraySize) {
    if(file == NULL || personsArray == NULL){
    return -1;
    }
    char buffer[1024];
    int ok;
    unsigned int counter = 0;

    while(fgets(buffer, 1024, file) != NULL && counter < arraySize){

        ok = sscanf(buffer, "%[^;];%d;%d;%d", personsArray[counter].name, &personsArray[counter].age,
               &personsArray[counter].height, &personsArray[counter].weight);

        if (ok == 4){
            counter++;
        }
    }
    return counter;
}

bool Person_GetAverageData(tPerson *personsArray, unsigned sizeOfAnArray,
                           double *averageWeight, double *averageHeight,
                           double *averageAge) {
  if(personsArray == NULL || averageWeight == NULL || averageHeight == NULL || averageAge == NULL || sizeOfAnArray == 0){
      return false;
  }
  *averageAge = *averageHeight = *averageWeight = 0;
  for(unsigned i = 0; i < sizeOfAnArray; i++){
      *averageAge += personsArray[i].age;
      *averageHeight += personsArray[i].height;
      *averageWeight += personsArray[i].weight;
  }

  *averageAge /= sizeOfAnArray;
  *averageHeight /= sizeOfAnArray;
  *averageWeight /= sizeOfAnArray;

  return true;
}

bool Person_Extremes(tPerson *personsArray, unsigned sizeOfAnArray,
                     unsigned int *youngest, unsigned int *oldest) {
  if(personsArray == NULL || youngest == NULL || oldest == NULL || sizeOfAnArray == 0){
      return false;
  }
  *youngest = *oldest = 0;
  for(unsigned int i = 0; i < sizeOfAnArray; i++){
      if(personsArray[i].age < personsArray[*youngest].age){
          *youngest = i;
      }
      if(personsArray[i].age > personsArray[*oldest].age){
          *oldest = i;
      }
  }
  return true;
}
