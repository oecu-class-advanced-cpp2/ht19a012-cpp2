#include <iostream> 
#include <vector>

#define CPP2_PRIME_UPPER_LIMIT 1000000 //探索する値の上限値。 

bool IsPrime(int num)
{
  if (num < 2) return false;
  else if (num == 2) return true;
  else if (num % 2 == 0) return false;
  double sqrtNum = sqrt(num);
  for (int i = 3; i <= sqrtNum; i += 2) {
    if (num % i == 0) {
      return false;
    }
  }
  return true;
}
int nth_prime(unsigned int a, unsigned int d, unsigned int n)
{
  int g, count = 0;
  for (int i = 0; i < CPP2_PRIME_UPPER_LIMIT; i++) {
    g = a + (i * d);
    if (IsPrime(g)) {
      count++;
    }
    if (count == n) {
      break;
    }
  }
  return g;
}

int main()
{
  std::cout << nth_prime(367, 186, 151) << std::endl;
  std::cout << nth_prime(179, 10, 203) << std::endl;
  std::cout << nth_prime(271, 37, 39) << std::endl;
  std::cout << nth_prime(103, 230, 1) << std::endl;
  std::cout << nth_prime(27, 104, 185) << std::endl;
  std::cout << nth_prime(253, 50, 85) << std::endl;s
  std::cin.get();
  return 0;
}