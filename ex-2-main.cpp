#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


namespace cpp2 {
	/* --------------------------------------------------------------------- */
	/*
	mcxi
	mcxi 記法を解析するクラスです。
	*/
	/* --------------------------------------------------------------------- */
class mcxi {
public
	
  mcxi(const std::string& s) : value_(0)
  {
    int num = 0;
    for (auto pos = s.begin(); pos != s.end(); ++pos) {
      if (*pos >= '2' && *pos <= '9') {
	num = *pos - '0';
      } else {
	int u = unit(*pos);
	value_ += std::max(num, 1) * u;
	num = 0;
      }
    }
  }

  /* ----------------------------------------------------------------- */
  /*
  operator+
  2 つのオブジェクトの加算結果を取得します。
  */
  /* ----------------------------------------------------------------- */
  mcxi operator+(const mcxi& rhs)
  {
    return rhs;
  }

  /* ----------------------------------------------------------------- */
  /*
  to_string
  現在の値を mcxi 記法に変換します。
  */
  /* ----------------------------------------------------------------- */
  std::string to_string() const
  {
uint16_t temp;
	std::stringstream ret;
	//m
	temp = value_ / 1000;
	if (temp == 1){
		ret << 'm';
	}
	if (temp > 1){
		ret << temp;
		ret << 'm';
	}

	//x
	temp = (value_ /100) % 10;
	if (temp == 1){
		ret << 'c';
	}
	if (temp > 1){
		ret << temp;
		ret << 'c';
	}

	//c
	temp = (value_ / 10 ) % 10;
	if (temp == 1){
		ret << 'x';
	}
	if (temp > 1){
		ret << temp;
		ret << 'x';
	}

	//i
	temp = value_ % 10;
	if (temp == 1){
		ret << 'i';
	}
	if (temp > 1){
		ret << temp;
		ret << 'i';
	}
	return ret.str();
	}

  void debug_mcxi()
  {
    std::cout << "value_: " << value_ << std::endl;
  }
private:
  int unit(char c)
  {
    switch (c) {
    case 'm': return 1000;
    case 'c': return  100;
    case 'x': return   10;
    case 'i': return    1;
    }
    return -1;
  }

private:
  int value_;
};
}

int main()
{
  cpp2::mcxi a0("x9i");
  a0.debug_mcxi();
  cpp2::mcxi b0("x9i");
  auto result0 = a0 + b0;
  std::cout << "3x" << " " << result0.to_string() << std::endl;

}
