#include <cassert>
#include <iostream>
#include <stdexcept>
#include <string>

#include "color.h"

struct invalid_enum_conversion : std::runtime_error {
  invalid_enum_conversion() : std::runtime_error("Invalid enum conversion.") {
  }
};

void to_string_error_handler(const char* name, int val) {
  std::cerr << "Invalid value " << val << " for " << name << "." <<
    std::endl;
  std::terminate();
}

void to_value_error_handler(const char* name, const char* str,
  const char* strs[], std::size_t n) {
  std::cerr << "Cannot convert \"" << str << "\" to " << name << ". ";
  if (n == 1)
    std::cerr << "Possible value is \"" << strs[0] << "\"." << std::endl;
  else {
    std::cerr << "Possible values are \"" << strs[0] << "\"";
    for (size_t i = 1; i < n - 1; ++i)
      std::cerr << ", \"" << strs[i] << "\"";
    std::cerr << " and \"" << strs[n - 1] << "\"." << std::endl;
  }
  throw invalid_enum_conversion();
}

void test_enum_in_global_scope() {
  
  std::cout << "test_enum_in_global_scope()..." << std::endl;
  
  assert(to_string(color::red  ) == std::string("Red"  ));
  assert(to_string(color::green) == std::string("Green"));
  assert(to_string(color::blue ) == std::string("Blue" ));

  assert(to_string(color::red  ) != std::string("R"));
  assert(to_string(color::green) != std::string("G"));
  assert(to_string(color::blue ) != std::string("B"));

  assert(color::red   == to_value<color>("Red"  ));
  assert(color::green == to_value<color>("Green"));
  assert(color::blue  == to_value<color>("Blue" ));
  
  assert(color::red   == to_value<color>("R"));
  assert(color::green == to_value<color>("G"));
  assert(color::blue  == to_value<color>("B"));
}

void test_enum_in_namespace_scope() {
  
  //std::cout << __func__ << "..." << std::endl;
  
  assert(to_string(ns::color::red  ) == std::string("Red"  ));
  assert(to_string(ns::color::green) == std::string("Green"));
  assert(to_string(ns::color::blue ) == std::string("Blue" ));

  assert(to_string(ns::color::red  ) != std::string("R"));
  assert(to_string(ns::color::green) != std::string("G"));
  assert(to_string(ns::color::blue ) != std::string("B"));

  assert(ns::color::red   == ns::to_value<ns::color>("Red"  ));
  assert(ns::color::green == ns::to_value<ns::color>("Green"));
  assert(ns::color::blue  == ns::to_value<ns::color>("Blue" ));
  
  assert(ns::color::red   == ns::to_value<ns::color>("R"));
  assert(ns::color::green == ns::to_value<ns::color>("G"));
  assert(ns::color::blue  == ns::to_value<ns::color>("B"));
}

void test_enum_in_class_scope() {
  
  std::cout << "test_enum_in_class_scope()..." << std::endl;
  
  assert(cl::to_string(cl::color::red  ) == std::string("Red"  ));
  assert(cl::to_string(cl::color::green) == std::string("Green"));
  assert(cl::to_string(cl::color::blue ) == std::string("Blue" ));

  assert(cl::to_string(cl::color::red  ) != std::string("R"));
  assert(cl::to_string(cl::color::green) != std::string("G"));
  assert(cl::to_string(cl::color::blue ) != std::string("B"));

  assert(cl::color::red   == cl::to_value<cl::color>("Red"  ));
  assert(cl::color::green == cl::to_value<cl::color>("Green"));
  assert(cl::color::blue  == cl::to_value<cl::color>("Blue" ));
  
  assert(cl::color::red   == cl::to_value<cl::color>("R"));
  assert(cl::color::green == cl::to_value<cl::color>("G"));
  assert(cl::color::blue  == cl::to_value<cl::color>("B"));
}

void test_invalid_conversion() {
  
  std::cout << "test_invalid_conversion()..." << std::endl;
  
  try {
    to_value<color>("White");
  }
  catch (const invalid_enum_conversion& e) {
    std::cerr << e.what() << std::endl;
  }
}

void test_multiple_definitions();

int main() {
  test_enum_in_global_scope();
  test_enum_in_namespace_scope();
  test_enum_in_class_scope();
  test_invalid_conversion();
  test_multiple_definitions();
  return 0;
}
