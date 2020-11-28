#include "recursive.h"
#include "hw4.h"
#include <iostream>

int accumulate(list_t l, int (*fn)(int, int), 
int base)
{
  if (list_isEmpty(l)) {
    return base;
  } else {
    return accumulate(list_rest(l), fn, fn(base, list_first(l)));
  }
}

static int sumHelper(list_t list, int total)
{
  if(list_isEmpty(list))
    return total;
  else{
    return sumHelper(list_rest(list), list_first(list) + total);
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
  return sumHelper(list, 0);
}


/*
* Pseudocode
* 
*/
static int productHelper(list_t list, int total)
{
  if(list_isEmpty(list))
    return total;
  else
    return productHelper(list_rest(list), list_first(list) + total);
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
  return productHelper(list, 0);
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
  if(list_isEmpty(list))
    return list;

  int item = list_first(list);
  list_t remainder = list_rest(list);

  if(list_isEmpty(remainder))
    return list;
  else {
    list_t empty = list_make();
    list_t item_list = list_make(item, empty);
    return append(reverse(remainder), item_list);
  }
}

/*
* Pseudocode
* 
*/
static list_t append_helper(list_t list_two, list_t list_one, int last_item)
{
  if (list_isEmpty(list_one))
    return list_make(last_item, list_two);
  else
    return list_make(last_item, append_helper(list_two, list_rest(list_one), list_first(list_one)));
}

/*
* Pseudocode
* if rest of first list is not null
* return append on rest of first list and 
* list_make on first of first and second
*/
list_t append(list_t list_one, list_t list_two)
{
  if (list_isEmpty(list_two))
    return list_one;
  else
    return append_helper(list_two, list_rest(list_one), list_first(list_one));
}


/*
* Pseudocide
* adds item to the end of list
*/
static list_t add(list_t list, int item)
{
  list_t empty = list_make();
  return append(list, list_make(item, empty));
}

/*
* Pseudocode
* 
*/
static list_t filterOddHelper(list_t list, list_t filtered_list)
{
  if(list_isEmpty(list))
    return filtered_list;
  else
  {
    if(list_first(list) % 2 != 0)
      filtered_list = list_make(list_first(list), filtered_list);
    return filterOddHelper(list_rest(list), filtered_list);
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
list_t filter_odd(list_t list)
{
  return filterOddHelper(list, list_make());

  /*if(list_isEmpty(list))
      return list; 

    int first_item = list_first(list);
    list_t odd_list = filter_odd(list_rest(list)); 

    if(first_item % 2 != 0)
      odd_list = list_make(first_item, odd_list);   

    return odd_list;*/
}

/*
* Pseudocode
* 
*/
list_t filterEvenHelper(list_t list, list_t filtered_list)
{
  if(list_isEmpty(list))
    return filtered_list;
  else
  {
    if(list_first(list) % 2 == 0)
      filtered_list = list_make(list_first(list), filtered_list);
    return filterEvenHelper(list_rest(list), filtered_list);
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
  return filterEvenHelper(list, list_make());

  /*if(list_isEmpty(list))
      return list; 

    int first_item = list_first(list);
    list_t even_list = filter_even(list_rest(list)); 

    if(first_item % 2 == 0)
      even_list = list_make(first_item, even_list);   

    return even_list;*/
}

/*
* Pseudocode
* 
*/
list_t filterHelper(list_t list, bool (*fn)(int), list_t filtered_list)
{
  if(list_isEmpty(list))
    return filtered_list;
  else
  {
    if(fn(list_first(list)) == true)
      filtered_list = list_make(list_first(list), filtered_list);
    return filterHelper(list_rest(list), fn, filtered_list);
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
  if(list_isEmpty(list))
      return list; 

    int first_item = list_first(list);
    list_t filtered_list = filter_even(list_rest(list)); 

    if(fn(first_item) == true)
      filtered_list = list_make(first_item, filtered_list);   

    return filtered_list;
}

/*
* Pseudocode
* if n > 0
* rotate on list make on list rest, n-1 + append 
* list_first
*/
list_t rotate(list_t list, unsigned int n)
{
  if(n == 0)
    return list;
  else
    return rotate(add(list_rest(list), list_first(list)), n-1);
}


list_t insertListHeleper(list_t first, list_t second, unsigned int n, int last_item)
{
  if(n == 0 && list_isEmpty(second))
    return list_make(last_item, first);
  else if(n == 0 && !list_isEmpty(second))
    return list_make(last_item, insertListHeleper(first, list_rest(second), n, list_first(second)));
  else
  {
     return list_make(last_item, insertListHeleper(list_rest(first), second, n-1, list_first(first)));
  }
}

/*
* Pseudocode
* 
*/
list_t insert_list(list_t first, list_t second, unsigned int n)
{
  if (list_isEmpty(second))
    return first;
  else if(list_isEmpty(first))
    return second;

  if(n == 0 && !list_isEmpty(second))
  {
    return insertListHeleper(first, list_rest(second), n, list_first(second));
  }
  else
     return insertListHeleper(list_rest(first), second, n-1, list_first(first));
}

list_t chop(list_t l, unsigned int n)
{
  if(n == 0)
    return l;
  else
  {
    l = reverse(l);
    int item = list_first(l);
    l = reverse(list_rest(l));
    return chop(l, n-1);
  }
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