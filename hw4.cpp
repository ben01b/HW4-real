#include "recursive.h"
#include "hw4.h"
#include <iostream>

int accumulate(list_t l, int (*fn)(int, int), int base)
{
  if (list_isEmpty(l)) {
    return base;
  } else {
    return accumulate(list_rest(l), fn, fn(base, list_first(l)));
  }
}

int sum(list_t list)
{
  int head_val = list_first(list);
  
  if (list == NULL)
    return 0;
  else
    return head_val + sum(list_rest(list));
}

int product(list_t list)
{
  int head_val = list_first(list);
  
  if (list == NULL)
    return 0;
  else
    return head_val * sum(list_rest(list));
}

list_t reverse(list_t list)
{
  int head_val = list_first(list);

}

list_t append(list_t first, list_t second)
{
  
}