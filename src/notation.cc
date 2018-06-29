// Time-stamp: <2018-06-11 16:43:42 daniel>


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
// notation.cc
//


// Required header notations
//-----------------------------------------------------------------------------
#include "notation.hh"  // json::notation
#include "fstring.hh"  // file::string


// Namespace short cuts
//-----------------------------------------------------------------------------
using namespace json;  // NS short hand



// Constructor
//
// @param file_name The name of the JSON file to be read and parsed.
//-----------------------------------------------------------------------------
notation::notation( const char* file_name ) : handle_() {

  json::read( file::string( file_name ), handle_ );

};  // end constructor



// Copy Constructor
//
// @param original The original notation object to be copied.
//-----------------------------------------------------------------------------
notation::notation( const notation& original ) {

};  // end copy constructor



// Destructor
//-----------------------------------------------------------------------------
notation::~notation() {
};  // end destructor
