#include<iostream>
#include "recursive.h"
#include "hw4.h"
#include "hw7.h"

bool ListEqual(list_t l1, list_t l2)
    // EFFECTS: reeturns true of l1 and l2 are equal, false otherwise
{
    // If either are empty, both must be empty for equality
    if (list_isEmpty(l1) || list_isEmpty(l2)) {
	return (list_isEmpty(l1) && list_isEmpty(l2));
    }

    if (list_first(l1) != list_first(l2)) {
	return false;
    } else {
	return ListEqual(list_rest(l1), list_rest(l2));
    }
}

bool notByFour(int i)
{
    return (i%4);
}

int main() {
  list_t test = list_make();
  list_t test1 = list_make(1,test);
  list_t test2 = list_make(2,test1);
  list_t test3 = list_make(3,test2);
  list_t test4 = list_make(4,test3);
  list_t test_filter_odd = test3;
  list_t test_filter_even = test3;
  list_t test_rotate = test3;
  list_t test_chop = test4;
  list_t test_chop_remains = list_make(5, test4);
  list_t test_product = list_make(3, test2);
  list_t test_insert1 = test_chop_remains;


  list_t one = list_make(9, list_make());
  list_t two = list_make(10, one);
  list_t three = list_make(11, two);
  list_t test_insert2 = three;
  list_t test_hash = three;
  list_print(test3);
  std::cout << std::endl;

  list_t test_list = list_make(9, list_make());
  test_list = list_make(8, test_list);
  test_list = list_make(7, test_list);
  test_list = list_make(6, test_list);
  
  std::cout << "Test list: ";
  list_print(test_list);
  std::cout << std::endl;
  if(list_isEmpty(test3))
    std::cout << "Test3 is empty" << std::endl;
  else
    std::cout << "Test3 is not empty" << std::endl;

  int v =  sum(test3);
  std::cout << std::endl << "Sum value: ";
  list_print(test3);
  std::cout << std::endl << v << std::endl;
  
  int k = product(test_list);
  std::cout << std::endl << "Product: ";
  list_print(test_list);
  std::cout << std::endl << k << std::endl;

  std::cout << std::endl << "Reversing: ";
  list_print(test_product);
  std::cout << std::endl;
  list_t reversed = reverse(test_product);
  list_print(reversed);
  std::cout << std::endl;

  std::cout << std::endl << "Appending: ";
  list_print(test2);
  list_print(test3);
  std::cout << std::endl;
  list_t appended = append(test2, test3);
  list_print(appended);
  
  std::cout << std::endl << std::endl << "Filtering odd from: ";
  list_print(test_filter_odd);
  std::cout << std::endl;
  list_t filtered_odd = filter_odd(test_filter_odd);
  list_print(filtered_odd);

  std::cout << std::endl << std::endl << "Filtering even from: ";
  list_print(test_filter_even);
  std::cout << std::endl;
  list_t filtered_even = filter_even(test_filter_odd);
  list_print(filtered_even);

  std::cout << std::endl << std::endl << "Rotating: ";
  list_print(test_rotate);
  std::cout << " 2 time(s)" << std::endl;
  list_t rotated = rotate(test_rotate, 2);
  list_print(rotated);
  std::cout << std::endl;

  std::cout << std::endl << "Chopping 2 elements from: ";
  list_print(test_chop_remains);
  std::cout << std::endl;
  list_t chopped = chop(test_chop_remains, 2);
  list_print(chopped);
  std::cout << std::endl;

  std::cout << std::endl << "Inserting: ";
  list_print(test_insert2);
  std::cout << std::endl << "into: ";
  list_print(test_insert1);
  std::cout << " at 2" << std::endl;
  list_t inserted = insert_list(test_insert1, test_insert2, 2);
  list_print(inserted);

  std::cout << std::endl << std::endl << "Hashing1: ";
  list_print(test_hash);
  std::cout << std::endl << "Hashed1: ";
  list_t hashed = hash_test1(test_hash);
  list_print(hashed);

  std::cout << std::endl << std::endl << "Hashing2: ";
  list_print(test_hash);
  std::cout << std::endl << "Hashed2: ";
  list_t hashed2 = hash_test2(test_hash);
  list_print(hashed2);

  std::cout << std::endl << std::endl << "Collisions when inserting: ";
  list_print(appended);
  std::cout << std::endl << "Hashed: ";list_print(hash_test2(appended));
  std::cout << std::endl << "... ";
  int x = new_code_collisions_cnt(appended);
  std::cout << x << std::endl;
    //std::cout << "Reverse: " << reverse(test3) << std::endl;
    
    
    /*list_t original = list_make();
    list_t rotated = list_make();
    list_t testlist;

    const int largest = 7;
    const int steps = 4+largest;

    bool answer = true;

    for (int i = largest-1; i>=0; i--) {
      original = list_make(i, original);
      rotated = list_make((i+steps)%largest, rotated);
    }

    testlist = rotate(original, steps);
    bool results  = ListEqual(testlist, rotated);

  list_print(rotated);
  list_print(testlist);*/

}