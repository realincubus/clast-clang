
#ifndef _CLAST_CLANG_HPP
#define _CLAST_CLANG_HPP 

#include <sstream>

namespace clast_clang{
  void clast_pprint(std::stringstream& foo, struct clast_stmt *root, int indent, CloogOptions *options);
}

#endif
