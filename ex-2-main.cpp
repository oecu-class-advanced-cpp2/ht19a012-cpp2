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
public:
	/* ----------------------------------------------------------------- */
	/*
	mcxi
	指定された文字列を解析して、オブジェクトを初期化します。
	以下の場合には例外が創出されます。
	1. [2-9,m,c,x,i] 以外の文字が出現した場合
	2. 2 文字続けて数字 (2-9) が出現した場合
	3. m, c, x, i がこの順序で出現しなかった場合
	ただし、例えば mx のように、特定の文字をスキップする事は許容
	されます。
	*/
	/* ----------------------------------------------------------------- */
  mcxi(const std::string& s) : value_(0)
  {
    int num = 0;
    for (auto pos = s.begin(); pos != s.end(); ++pos) {
	    //*pos は、char ! char ってことが分かってたら、もっと簡単にできるのでは？？
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
    return "XXX";
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
