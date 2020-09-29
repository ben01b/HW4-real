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
* 
* 
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
* if rest of first list is not null
* return append on rest of first list and list_make on first of first and second
*/
list_t append(list_t first, list_t second)
{
  if(list_rest(first) != NULL)
    return append(list_rest(first), list_make(list_first(first), second));
}

/*
* Pseudocode
* if rest == null
* return list
* if first % 2 == 0
* filter_odd on new list with last odd and list 
* rest
* else
* set last_odd to list first
* filter_odd on list rest
* return list
*/
list_t filter_odd(list_t list)
{
  int last_odd = 0;

  if(list_rest(list) == NULL)
    return list;
  
  if(list_first(list) % 2 == 0)
  {  
    if(last_odd == 0)
      filter_odd(list_make(last_odd, list_rest(list)));
    else
    {
      last_odd = list_first(list);
      filter_odd(list_rest(list));
    }
    return list;
  }    
      
    
}

/*
* Pseudocode
* if rest == null
* return list
* if first % 2 == 0
* filter_odd on new list with last odd and list 
* rest
* else
* set last_odd to list first
* filter_odd on list rest
* return list
*/
list_t filter_even(list_t list)
{
  int last_even = 0;

  if(list_rest(list) == NULL)
    return list;
  
  if(list_first(list) % 2 != 0)
  {  
    if(last_even == 0)
      filter_even(list_make(last_even, list_rest(list)));
    else
    {
      last_even = list_first(list);
      filter_even(list_rest(list));
    }
    return list;
  }    
}

/*
* Pseudocode
* if fn(list_first) is false
* return filter on new list with first element of 
* rest and rest of rest
* else return filter on list rest
*/
list_t filter(list_t list, bool (*fn)(int))
{

  if(fn(list_first(list) == false))
    return filter(list_make(list_first(list_rest(list)), list_rest(list_rest(list))), fn);
  else
    return filter(list_rest(list), fn);
}

list_t rotate(list_t list, unsigned int n)
{
  if(n > 0)
  {

    rotate(list, n);
  }
}

list_t insert_list(list_t first, list_t second, unsigned int n)
{
  
}

list_t chop(list_t l, unsigned int n)
{

}

/*
* Pseudocode
* returns fib_tail(n)
*/
int fib(int n)
{
  return fib_tail(n);
}

/*
* Pseudocode
* if n <= 1
* return n
* return fib(n-1) + fib(n-2)
*/
int fib_tail(int n)
{
  if (n <= 1) 
    return n; 
  return fib(n-1) + fib(n-2); 
}