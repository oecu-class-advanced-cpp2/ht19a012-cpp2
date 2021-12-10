#include <iostream> 
#include <vector>

#define CPP2_PRIME_UPPER_LIMIT 1000000 //探索する値の上限値。 

int gcd(int a, int b)
{
  if (a % b == 0) {
    return(b);
  } else {
    return(gcd(b, a % b));
  }
}
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
int nth_prime(int a,int d,int n)
{

  if (a < 0 || d < 0 || n < 0) {
    std::cout << "入力値にマイナスが含まれています" << std::endl;
    return -1;
  }
  if (a == 0 || d == 0 || n == 0) {
    std::cout << "入力値に0が含まれています" << std::endl;
    return -1;
  }
  if (a > 65535 || d > 65535 || n > 65535) {
    std::cout << "入力値が大きすぎます" << std::endl;
    return -1;
  }
  if (!(gcd(a, d) == 1)) {
    std::cout << "aとbが素数ではありません" << std::endl;
    return -1;
  }
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
 //成功の場合
std::cout << nth_prime(367, 186, 151) << std::endl;
std::cout << nth_prime(179, 10, 203) << std::endl;
std::cout << nth_prime(271, 37, 39) << std::endl;
std::cout << nth_prime(103, 230, 1) << std::endl;
std::cout << nth_prime(27, 104, 185) << std::endl;
std::cout << nth_prime(253, 50, 85) << std::endl;
std::cout << nth_prime(9075, 337, 210) << std::endl;

//入力する値にマイナスの数値が入っている場合
std::cout << nth_prime(-367, 186, 151) << std::endl;
std::cout << nth_prime(179, -10, 203) << std::endl;
std::cout << nth_prime(271, 37, -39) << std::endl;
std::cout << nth_prime(-307,-24,-79) << std::endl;

//入力する値に0が入っている場合
std::cout << nth_prime(0, 230, 1) << std::endl;
std::cout << nth_prime(27, 0, 185) << std::endl;
std::cout << nth_prime(253, 50, 0) << std::endl;
std::cout << nth_prime(0, 0, 0) << std::endl;

//入力する値が大きすぎる場合
std::cout << nth_prime(65537, 186, 151) << std::endl;
std::cout << nth_prime(367, 65537, 151) << std::endl;
std::cout << nth_prime(367, 186, 65537) << std::endl;

//aとdが素数でない
std::cout << nth_prime(4, 242, 120) << std::endl;

std::cin.get();
return 0;
}