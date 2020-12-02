#include "recursive.h"
#include "hw4.h"
#include <iostream>
#include <unordered_map>

int hash_main()
{
  
}

/*
* Pseudocode
* if key <= 2 return true if key is 2 false 
* if not
* if key % divisor is 0
* return false
* if divisor * divisor > key
* return true
* return isprimehlper(key, divisor + 1)
*/
static bool isPrimeHelper(int key, int divisor)
{ 
    if (key <= 2) 
        return (key == 2) ? true : false; 
    if (key % divisor == 0) 
        return false; 
    if (divisor * divisor > key) 
        return true; 
    return isPrimeHelper(key, divisor + 1); 
}

/*
* Pseudocode
* return is prime helper(key, 2)
*/
static bool isPrime(int key)
{
  return isPrimeHelper(key, 2);
}

static list_t copy(list_t list){
  return append(list, list_make());
}

/*
* Pseudocode
* if list is empty return list
* else return list_make(fib_tail(list_first
*(list)) + sum, hash_test1_helper(list_rest
*(list), sum))
*/
list_t hash_test1_helper(list_t list, int sum)
{
  if(list_isEmpty(list))
    return list;
  else
    return list_make(fib_tail(list_first(list)) + sum, hash_test1_helper(list_rest(list), sum));
}

/*
* Pseudocode
* get sum of list
* return hashtest1helper(list, sum)
*/
list_t hash_test1(list_t list)
{
  int sum_of = sum(list);
  return hash_test1_helper(list, sum_of);
}

/*
* Pseudocode
* get list of odd keys
* get sum of odd keys
* return sum + key
*/
static int hash2_odd(list_t items, int key)
{
  list_t odd_keys = filter_odd(items);
  int odd_sum = sum(odd_keys);
  return odd_sum + key;
}  

/*
* Pseudocode
* if items list is empty return sum
* key is first of items
* if key%2 is 1
* hash = hash2_odd(filter(list, isPrime), key)
*/
static int hash2_even_sum(list_t list, list_t items, int sum)
{
    if (list_isEmpty(items))
      return sum;
    int key = list_first(items);
    int hash = 0;
    if (key % 2 == 1)
      hash = hash2_odd(filter(list, isPrime), key);
    return hash2_even_sum(list, list_rest(items),  sum + hash);
}

/*
* Pseudocode
* if key%2 is 0
* return hash2_even_sum(items, copy(items), 
* key)
* else return hash2_odd(items, key)
*/
static int hash2(list_t items, int key)
{
  if (key % 2 == 0)
    return hash2_even_sum(items, copy(items), key);
  else
    return hash2_odd(items, key);
}

/*
* Pseudocode
* while temp list is not empty
* get first of temp list
* get hashed key
* append key to hash list
* temp list = rest(temp list)
* return hash list
*/
list_t hash_test2(list_t list)
{
  list_t odd_list = filter_odd(list);
  list_t hash_list = list_make();
  list_t temp_list = append(list, list_make());
  while(!list_isEmpty(temp_list))
  {
    int item = list_first(temp_list);
    int key = hash2(list, item);
    hash_list = append(hash_list, list_make(key, list_make()));
    temp_list = list_rest(temp_list);
  }
  return hash_list;
}

/*
* Pseudocode
* 
*/
int new_code_collisions_cnt(list_t list)
{
  list_t temp_list = append(list, list_make());
  int my_map_arr[16];
  int count = 0;
  int collisions = 0;

  while(!list_isEmpty(temp_list)){
    int x = hash2(list, list_first(temp_list));
    my_map_arr[count] = x;
    for(int i = 0; i<count; i++)
    {
      std::cout << "Hash value: " << x << " count: " << count <<std::endl;
      if(my_map_arr[i] == my_map_arr[count])
      {
          collisions++;
          std::cout << "found collision" <<  std::endl;
          break;
      }
    }
    count++;
    temp_list = list_rest(temp_list);
  }
  return collisions;
}