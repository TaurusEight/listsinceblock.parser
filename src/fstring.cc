// Time-stamp: <2018-06-11 16:32:20 daniel>


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
// fstring.cc
//


// Required Header Files
//-----------------------------------------------------------------------------
#include <iostream>  // std::ostream
#include <fstream>  // std::ifstream
#include "fstring.hh"  // Defines file::string


// Constructor
//
// Read the full text file and store it in a std::string.
//
// @param file_name The name of the file to be read.
//-----------------------------------------------------------------------------
file::string::string( const char* file_name ) : handle_() {

  std::ifstream infile( file_name );
  handle_ = std::string( ( std::istreambuf_iterator< char >( infile ) ),
                         std::istreambuf_iterator< char >() );

};  // end constructor


// Destructor
//-----------------------------------------------------------------------------
file::string::~string( ) { };  // end destructor


// Output this string to the stream reference.
//
// @param out A reference to the output stream.
// @param tr A constant reference to a block::transaction.
// @return std::ostream& The reference to the stream passed into this function.
//-----------------------------------------------------------------------------
std::ostream& operator<<( std::ostream& out,  const file::string& fs ) {

  out << static_cast< std::string >( fs );
  return out;

};  // end operator<<
