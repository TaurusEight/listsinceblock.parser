// Time-stamp: <2018-06-11 16:35:23 daniel>
#ifndef __JSON_HH__
#define __JSON_HH__

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
// json.hh
//


// Required header files
//-----------------------------------------------------------------------------
#include <iosfwd>  // std::ostream
#include <boost/property_tree/ptree.hpp>  // boost parsing library
#include <string>  // std::string


// Short hand for the boost json property_tree namespace
//-----------------------------------------------------------------------------
namespace json {

  typedef boost::property_tree::ptree node;

  //  void read( const std::string&, node& );
  void read( const std::string*, node& );
  void write( std::ostream&, const node&, bool = true );

  bool has( const json::node&, const char* );
  bool does_not_have( const json::node&, const char* );
  json::node find( const json::node&, const char* );

};  // end NS json


#endif  // __JSON_HH__
