//#include <cmath>
//#include <cstdio>
//#include <cstdlib>
//#include <vector>

//I am implementing binary search here, and here I will return -1 if the given number is not found in the given array of number
int find_index_helper(vector<int> & numbers, int targetNum) {
  int l = 0, r = numbers.size() - 1;
  while (l <= r) {
    int middle = (r - l) / 2 + l;
    int comparator = numbers[middle];
    //In order to determine if both target and numbers[middle] are on same side.
    if (((targetNum < numbers[0]) && (numbers[middle] < numbers[0])) ||
        ((targetNum >= numbers[0]) && (numbers[middle] >= numbers[0])))
      comparator = numbers[middle];
    else {
      //Figure out where numbers[middle] is and making comparator as -INF or INF
      if (targetNum < numbers[0])
        comparator = -INFINITY;
      else
        comparator = INFINITY;
    }
    if (targetNum == comparator)
      return middle;
    if (targetNum > comparator)
      l = middle + 1;
    else
      r = middle - 1;
  }
  return -1;
}
