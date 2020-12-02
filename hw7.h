#ifndef __HW7_H__
#define __HW7_H__

#include "recursive.h"

static bool isPrimeHelper(int key, int divisor);

static bool isPrime(int key, int divisor);

static list_t copy(list_t list);

static list_t hash_test1_helper(list_t list, int sum);

list_t hash_test1(list_t list);

static int hash2_odd(list_t items, int key);

static int hash2_even_sum(list_t list, list_t items, int sum);

static int hash2(list_t items, int key);

list_t hash_test2(list_t list);

int new_code_collisions_cnt(list_t list);

#endif /* __HW7_H__ */