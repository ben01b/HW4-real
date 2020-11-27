#include "recursive.h"
#include "hw4.h"
#include <iostream>

/*list_t get_chop_remains(list_t list, int n);
list_t chop_helper(list_t l, unsigned int n, int n_count);*/

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
* if list is empty return 0
* get first value of list
* if there is more in the list
* return head value + sum of rest of list
* if rest is null return 0
*/
int sum(list_t list)
{ 
  if (list == NULL || list_isEmpty(list))
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
  if (list == NULL || list_isEmpty(list))
    return 1;

  int head_val = list_first(list);

  if(list_rest(list))
    return head_val * product(list_rest(list));
  else
    return 1;
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
* if rest of first list is not null
* return append on rest of first list and 
* list_make on first of first and second
*/
list_t append(list_t list_one, list_t list_two)
{
  int first_item = list_first(list_one);
  list_t remainder = list_rest(list_one);
  if (!list_isEmpty(remainder)){
    list_two = append(remainder, list_two);
  }
 
  return list_make(first_item, list_two); 
}

/*
* Pseudocide
* adds item to the end of list
*/
list_t add(list_t list, int item)
{
  list_t empty = list_make();
  return append(list, list_make(item, empty));
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
  if(list_isEmpty(list))
      return list; 

    int first_item = list_first(list);
    list_t odd_list = filter_odd(list_rest(list)); 

    if(first_item % 2 != 0)
      odd_list = list_make(first_item, odd_list);   

    return odd_list;
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
  if(list_isEmpty(list))
      return list; 

    int first_item = list_first(list);
    list_t even_list = filter_even(list_rest(list)); 

    if(first_item % 2 == 0)
      even_list = list_make(first_item, even_list);   

    return even_list;
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
  if(n > 0)
  {
    return rotate(add(list_rest(list), list_first(list)), n-1);
  }
  else
    return list;
}

/*
* Pseudocode
* gg
*/
list_t insert_list(list_t first, list_t second, unsigned int n)
{
  list_t a = chop(reverse(first), 2);
  list_t b = reverse(second);
  list_t c = list_make();
  //list_t c = chop(reverse(first), 2);
  return reverse(append(append(a, b), c));
}

/*list_t get_chop_remains(list_t list, int n)
{
  if(n > -1)
    list = get_chop_remains(list_rest(list), n-1);
  return list;
}*/

list_t chop(list_t l, unsigned int n)
{
  list_print(l);
  std::cout << std::endl;
  if (list_isEmpty(l)){
    return l;  
  } else {
    int x = list_first(l);
   
    // RECURESE
    list_t chopped = chop(list_rest(l), n+1);
    // RECURSE
std::cout << "test2" << std::endl;
    // If n is greater
    // than zero, there are more items to 
    // chop. If n == 0 begin building chop list
    if (n > 0){
      n = n-1;
      std::cout << "N: " << n << std::endl;
      return l;
    } else {
      std::cout << "test4" << std::endl;
      return list_make(x, chopped); 
    }
  } 
}

/*list_t chop_helper(list_t l, unsigned int n, int n_count)
{
  if(n_count == n)
    l = reverse(l);
  if(n_count > 0)
    l = chop_helper(list_rest(l), n, n_count-1);
  return reverse(l);
}*/

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