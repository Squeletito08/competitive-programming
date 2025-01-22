#include <iostream>
#include <set>

int main()
{
  std::set<int> mySet = {1, 2, 3, 4, 5};

  auto it_end = --mySet.end(); // Penúltimo elemento
  for (auto it = mySet.begin(); it != it_end; ++it)
  {
    std::cout << *it << " ";
  }

  return 0;
}
