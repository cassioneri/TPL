#include <cassert>
#include <iostream>
#include <string>

#include "color.h"

// Test whether inclusion of color.h in different cpp files triggers linker
// error about multiple definitions.
void test_multiple_definitions() {
  std::cout << "test_multiple_definitions()..." << std::endl;
  assert(to_string(color::red) == std::string("Red"));
  assert(color::red == to_value<color>("Red"));
}
