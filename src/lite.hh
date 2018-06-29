#ifndef __LITE_HH__
#define __LITE_HH__

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
// lite.hh
//


// Required header files
//-----------------------------------------------------------------------------
#include <sqlite3.h>  // SQLite3 header file


// Namespace used with object
//-----------------------------------------------------------------------------
namespace sql {


  // Pre-declaration of a needed class
  //---------------------------------------------------------------------------
  class query;  // Forward declaration


  // C++ wrapper around raw SQLite3 API class
  //---------------------------------------------------------------------------
  class lite {

  public:

    lite( const char* );  // constructor
    ~lite();  // destructor

    void exec( query* );  // perform an SQL query

  protected:

  private:

    sqlite3* handle_;  // pointer to the opened database
    int error_code_;  // holds any possible error code associated with the db
    char error_message_[ 64 ];  // store possible error messages from SQLite

  };  // end class lite


};  // end NS sql


#endif  // __LITE_HH__
