// Time-stamp: <2018-06-11 16:45:36 daniel>
#ifndef __NOTATION_HH__
#define __NOTATION_HH__

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
// notation.hh
//


// Required header files
//-----------------------------------------------------------------------------
#include "json.hh"  // json::node, json::read


// Namespace used with this class
//-----------------------------------------------------------------------------
namespace json {


  // Combination of the file having been read and the JSON data.
  //---------------------------------------------------------------------------
  class notation {

  public:

    notation( const char* );  // constructor
    notation( const notation& );  // copy constructor
    virtual ~notation();  // destructor

    operator node&() { return handle_; };

  protected:

  private:

    node handle_;  //

  };  // end class notation


};  // end NS json


#endif  // __NOTATION_HH__
