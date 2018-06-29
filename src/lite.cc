// Time-stamp: <2018-06-11 16:39:28 daniel>


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
// lite.cc
//


// Required header files
//-----------------------------------------------------------------------------
#include <stdexcept>  // std::runtime_error
#include "lite.hh"  // defines sql::lite
#include "query.hh"  // sql::functor
#include <iostream>


// Short hande for needed namespaces
//-----------------------------------------------------------------------------
using namespace sql;
using namespace std;


// Constructor
//
// Open the database throwing an exception if there was an error.
//
// @param db_name Name to give to the SQLite3 database file.
//-----------------------------------------------------------------------------
lite::lite( const char* db_name ) : handle_( nullptr ), error_code_( 0x0 ) {

  int flags = SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE;

  error_code_ = sqlite3_open( db_name, &handle_ );
  if ( error_code_ != SQLITE_OK )
    throw std::runtime_error( sqlite3_errstr( error_code_ ) );

};  // end constructor


// Destructor
//
// Close the handle to the open database.
//-----------------------------------------------------------------------------
lite::~lite() {

  error_code_ = sqlite3_close( handle_ );

};  // end destructor


// Perform an SQL query.
//
// @param pointer A pointer to the query object containing the actual text
// of the query and the callback function to be run with the data resolting
// from the query.
//-----------------------------------------------------------------------------
void lite::exec( query* pointer ) {

  char* error_message = error_message_;

  error_code_ = sqlite3_exec( handle_, pointer->c_str(),
                              query::callback, pointer, &error_message );

  if ( error_code_ != SQLITE_OK )
    throw std::runtime_error( sqlite3_errstr( error_code_ ) );

};  // end exec
