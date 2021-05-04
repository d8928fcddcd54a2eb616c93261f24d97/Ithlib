// platform-dependent string / char features

#ifndef ITHLIB_NSTRING_H
#define ITHLIB_NSTRING_H

#include <string>
#include <string_view>

// TODO cross-platform

#define NSTR(str) L ## str

using nchar_t = wchar_t;
using nstring = std::basic_string<nchar_t>;
using nstring_view = std::basic_string_view<nchar_t>;


#endif
