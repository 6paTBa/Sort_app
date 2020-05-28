#ifndef H_SORT
#define H_SORT
#include <inttypes.h>
#include <stddef.h>

void merge(double* arr_double, size_t low, size_t mid, size_t high);

void merge_sort(double* arr_double, size_t low, size_t high);

void insertion_sort(double* arr_double, size_t n);

void counting_sort(uint32_t* arr_uint, size_t n);
#endif
