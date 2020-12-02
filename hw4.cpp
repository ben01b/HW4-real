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

/*
* Pseudocode
* if list is empty return total
* else retunr sumHelper on rest of list and 
* total += total
*/
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
* return sumHelper on list and 0
*/
int sum(list_t list)
{ 
  return sumHelper(list, 0);
}


/*
* Pseudocode
* if list is empty return total
* else retunr productHelper on rest of list and 
* total *= total
*/
static int productHelper(list_t list, int total)
{
  if(list_isEmpty(list))
    return total;
  else
    return productHelper(list_rest(list), list_first(list) * total);
}

/*
* Pseudocode
* return productHelper on list and 1
*/
int product(list_t list)
{ 
  return productHelper(list, 1);
}

/*
* Pseudocode
* if list is empty return list
* if remainder is empty return list
* else return append(reverse(remainder), item 
* list)
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
* if list one is empty create list with last 
* item and list two
* else make list with last item and append 
* helper on rest of one
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
* if list two empty return list one
* else if list one empty return list two
* else turn append helper(list_two, rest
* (list_one), first(list_one))
*/
list_t append(list_t list_one, list_t list_two)
{
  if (list_isEmpty(list_two))
    return list_one;
  else if(list_isEmpty(list_one))
    return list_two;
  else
    return append_helper(list_two, list_rest(list_one), list_first(list_one));
}


/*
* Pseudocode
* create empty list append item + empty onto 
* list
*/
static list_t add(list_t list, int item)
{
  list_t empty = list_make();
  return append(list, list_make(item, empty));
}

/*
* Pseudocode
* if list empty return filtered list
* else if first is odd
* add first to end of filtered list
* return filteroddhelper(rest(list), filtered 
* list)
*/
static list_t filterOddHelper(list_t list, list_t filtered_list)
{
  if(list_isEmpty(list))
    return filtered_list;
  else
  {
    if(list_first(list) % 2 != 0)
      filtered_list = add(filtered_list, list_first(list));
    return filterOddHelper(list_rest(list), filtered_list);
  }
}

/*
* Pseudocode
* if list is empty return list
* else return filteroddhelper(list, empty 
* list)
*/
list_t filter_odd(list_t list)
{
  if(list_isEmpty(list))
    return list;
  else
    return filterOddHelper(list, list_make());
}

/*
* Pseudocode
* if list empty return filtered list
* else if first is even
* add first to end of filtered list
* return filterevenhelper(rest(list), 
* filtered list)
*/
list_t filterEvenHelper(list_t list, list_t filtered_list)
{
  if(list_isEmpty(list))
    return filtered_list;
  else
  {
    if(list_first(list) % 2 == 0)
      filtered_list = add(filtered_list, list_first(list));
    return filterEvenHelper(list_rest(list), filtered_list);
  }
}

/*
* Pseudocode
* if list is empty return list
* else return filterevenhelper(list, empty 
* list)
*/
list_t filter_even(list_t list)
{
  if(list_isEmpty(list))
    return list;
  else
    return filterEvenHelper(list, list_make());
}

/*
* Pseudocode
* if list empty return filtered list
* else if fn(first) == true
* add first to end of filtered list
* return filterevenhelper(rest(list), 
* filtered list)
*/
list_t filterHelper(list_t list, bool (*fn)(int), list_t filtered_list)
{
  if(list_isEmpty(list))
    return filtered_list;
  else
  {
    if(fn(list_first(list)) == true)
      filtered_list = add(filtered_list, list_first(list));
    return filterHelper(list_rest(list), fn, filtered_list);
  }
}

/*
* Pseudocode
* if list is empty return list
* else return filterhelper(list, empty 
* list)
*/
list_t filter(list_t list, bool (*fn)(int))
{
  return filterHelper(list, fn, list_make());
    /*int first_item = list_first(list);
    list_t filtered_list = filter_even(list_rest(list)); 

    if(fn(first_item) == true)
      filtered_list = list_make(first_item, filtered_list);   

    return filtered_list;*/
}

/*
* Pseudocode
* if n is 0 return list
* else return rotate on rest of list with 
* first at end and n-1
*/
list_t rotate(list_t list, unsigned int n)
{
  if(n == 0)
    return list;
  else
    return rotate(add(list_rest(list), list_first(list)), n-1);
}

/*
* Pseudocode
* if n is 0 and second list is empty
* return list make (last item, first)
* else if n is 0 and second is not empty
* return list make(last item, isertlisthelper
* (first, rest(second), n, first(second)))
*/
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
* if second is empty return first
* if first is empty return second
* if n is 0 and second is not empty
* return insertlisthelepr(first, rest(second),
* n, first(second))
* else return insertlistheleper(rest(first), 
* second, n-1, first(first))
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

/*
* Pseudocode
* if n is 0 return l
* else
* reverse rest of l
* return chop(l, n-1)
*/
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
* if n is 1 or 0
* return 1
* else return fib(n-1)+fib(n-2)
*/
int fib(int n)
{
  if((n == 1)||(n == 0))
      return(1);
   else
      return(fib(n-1)+fib(n-2));
}

/*
* Pseudocode
* if n is 0 or 1
* return n
* else return fib(n-1)+fib(n-2)
*/
int fib_tail(int n)
{
  if((n == 1)||(n == 0))
      return(n);
   else
      return(fib(n-1)+fib(n-2));
}