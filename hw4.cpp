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

/*
* Pseudocode
* if list is empty return 0
* get first value of list
* if there is more in the list
* return head value + sum of rest of list
* if rest is null return 0
*/
int sum(list_t list)
{ 
  if (list == NULL)
    return 0;
  
  int head_val = list_first(list);
  
  if(list_rest(list) != NULL)
    return head_val + sum(list_rest(list));
  else
    return 0;
}

/*
* Pseudocode
* if list is empty return 0
* get first value of list
* if there is more in the list
* return head value * product of rest of list
* if rest is null return 0
*/
int product(list_t list)
{ 
  if (list == NULL)
    return 0;

  int head_val = list_first(list);

  if(list_rest(list) != NULL)
    return head_val * sum(list_rest(list));
  else
    return 0;
}

/*
* Pseudocode
* if list is null return list
* if rest is null return list
* get first value of list
* if rest is null
* 
*/
list_t reverse(list_t list)
{
  if(list == NULL)
    return list;
  if(list_rest(list) == NULL)
    return list;
  
  int head_val = list_first(list);
  
  

  reverse(list_rest(list));


}

/*
* Pseudocode
* if rest of list is not null
* 
*/
list_t append(list_t first, list_t second)
{
  if(list_rest(first) == NULL)
    return first;
}

/*
* Pseudocode
* get first value of list
* if head % 2 == 0
* 
*/
list_t filter_odd(list_t list)
{
  int head_val = list_first(list);
  if(head_val % 2 == 0)
    return list;
}

list_t filter_even(list_t list)
{

}