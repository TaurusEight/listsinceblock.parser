// Time-stamp: <2018-06-11 16:28:54 daniel>
#ifndef __FORMAT_HH__
#define __FORMAT_HH__

//
// Copyright © 2018 Daniel Mendykie [archadious@gmail.com]
//
// This file is part of ”block.parse” a simplified ‘listsinceblock’ parser.
//
// Project Foo is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Project Foo is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with Project Foo.  If not, see <http://www.gnu.org/licenses/>.
//


//
// format.hh
//


// Required header files
//-----------------------------------------------------------------------------
#include <boost/format.hpp>  // boost::format

// Short hand for the boost format function object
namespace tr {  typedef boost::format fmt;  };  // end project namespace tr

#endif  // __FORMAT_HH__
