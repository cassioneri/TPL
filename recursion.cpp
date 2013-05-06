#include <algorithm>
#include <iostream>
#include <iomanip>

template <typename Generator>
void
repeat(int n, Generator g, const char* last) {
  while (n) {
    g(n);
    --n;
  }
  std::cout << last << std::endl;
}

void
lists(int n) {
  
  for (int i = 1; i <= n + 1; ++i)
    std::cout << "x" << std::setfill('0') << std::setw(2) << i << ", ";
  std::cout << "..." << std::endl;
  
  for (int i = 1; i <= n - 1; ++i)
    std::cout << "1, ";
  std::cout << "0" << std::endl;
  
  for (int i = n; i > 1; --i) {
    std::cout << std::setfill(' ') << std::setw(2) << i << ", ";
  }
  std::cout << " 1" << std::endl;
}

int main() {

  const int last = 64;

  lists(last);

  std::cout << "\n// MIN_WITH_TWO" << std::endl;

  repeat(last, [](int i) {
    std::cout << "#define TPL_MIN_WITH_TWO_" << i << " " << std::min(i, 2)
      << std::endl;
  }, "#define TPL_MIN_WITH_TWO_0 0");

  std::cout << "\n// RECURSE" << std::endl;

  repeat(last, [](int i) {
    std::cout << "#define TPL_RECURSE_"<< i << "(t, F) F(TPL_RECURSE_" <<
      i - 1 << "(t, F))" << std::endl;
  }, "#define TPL_RECURSE_0(t, F) t");

  std::cout << "\n// FOR_EACH" << std::endl;
  
  repeat(last, [](int i) {
    std::cout << "#define TPL_FOR_EACH_" << i << "(t, F, a) "
      "(F(TPL_HEAD(t), a)";
    if (i != 1)
        std::cout << ", TPL_TO_LIST(TPL_FOR_EACH_" << i - 1 <<
        "(TPL_TAIL(t), F, a)))";
    else
      std::cout << ")";
    std::cout << std::endl;
  }, "#define TPL_FOR_EACH_0(t, F, a) ()");
  
  std::cout << "\n// FOR_EACH_S_" << std::endl;
  
  repeat(last, [](int i) {
    std::cout << "#define TPL_FOR_EACH_S_" << i << "(t, F, a) "
      "F(TPL_HEAD(t), a) "
      "TPL_FOR_EACH_S_" << i - 1 << "(TPL_TAIL(t), F, a)" <<
      std::endl;
  }, "#define TPL_FOR_EACH_S_0(t, F, ...)");
}
