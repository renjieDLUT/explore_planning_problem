#include <vector>
template <class T>
int bisection(int start, int end, const std::vector<T> &input, T num) {
  if (start == end) return start;
  int mid = (start + end) / 2;
  if (num <= input[mid])
    return bisection(start, mid, input, num);
  else if (input[mid + 1] <= num)
    return bisection(mid + 1, end, input, num);
  else
    return mid;
}