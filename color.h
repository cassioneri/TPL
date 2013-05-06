#ifndef COLOR_H_
#define COLOR_H_

#include "enum.h"

// Define enum in global scope.

ENUM_IMPLEMENT(                   \
    color, default, (             \
        (red  , _, "Red"  , "R"), \
        (green, _, "Green", "G"), \
        (blue , _, "Blue" , "B")  \
    )                             \
)

namespace ns {

// Define enum in namespace scope.
  
ENUM_IMPLEMENT(                   \
    color, default, (             \
        (red  , _, "Red"  , "R"), \
        (green, _, "Green", "G"), \
        (blue , _, "Blue" , "B")  \
    )                             \
)

} // namespace ns

class cl {
public:
  
  // Define enum in class scope.
  
  ENUM_IMPLEMENT(                   \
      color, default, (             \
          (red  , _, "Red"  , "R"), \
          (green, _, "Green", "G"), \
          (blue , _, "Blue" , "B")  \
      )                             \
  )
};

#endif // COLOR_H_
