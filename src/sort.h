#ifndef H_SORT
#define H_SORT
#include <inttypes.h>
#include <stddef.h>

void merge(double* arr_double, size_t low, size_t mid, size_t high);

void mergesort(double* arr_double, size_t low, size_t high);

void insertionsort(double* arr_double, size_t n);

void count(uint32_t* arr_uint, size_t n);
#endif
