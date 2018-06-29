// Time-stamp: <2018-06-11 19:35:43 daniel>

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
// report.cc
//


// Required header files
//-----------------------------------------------------------------------------
#include <iostream>  // std::cout, std::endl
#include "query.hh"  // sql::query
#include "report.hh"  // sql::report


// Short hands
//-----------------------------------------------------------------------------
using namespace std;  // standard library
using namespace sql;  // used with sql queries


// Constructor - Print out report on known clients
//-----------------------------------------------------------------------------
report::report( ) : query() {

  handle( string( "select * from report;" ) );

};  // end constructor


// Destructor
//-----------------------------------------------------------------------------
report::~report() { };  // end destructor


// Query callback
//-----------------------------------------------------------------------------
int report::operator()( int cols, char** value, char** name ) {

  cout << "    Deposited for " << value[ 0 ]
       << ": count=" << value[ 1 ]
       << " sum=" << value[ 2 ]
       << endl;

  return SQLITE_OK;

};  // end operator(




//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------


// Constructor
//-----------------------------------------------------------------------------
unknown::unknown( ) : query() {

  handle( string( "select * from unknown;" ) );

};  // end unknown


// Destructor
//-----------------------------------------------------------------------------
unknown::~unknown() { };  // end destructor


// Handle the output of the query
//-----------------------------------------------------------------------------
int unknown::operator() ( int cols, char** value, char** name ) {

  cout << "    Deposited without reference: count=" << value[ 0 ]
       << " sum=" << value[ 1 ]
       << endl;

  return SQLITE_OK;

};  // end operator



//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

// Constructor
//-----------------------------------------------------------------------------
smallest::smallest( ) : query( ) {

  handle( string( "select * from smallest;" ) );

};  // end smallest


// Destructor
//-----------------------------------------------------------------------------
smallest::~smallest( ) { };  // end destructor


// Handle the output of the query
//-----------------------------------------------------------------------------
int smallest::operator() ( int cols, char** value, char** name ) {

  cout << "    Smallest valid deposit: " << value[ 0 ] << endl;

  return SQLITE_OK;

};  // end operator



//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------


// Constructor
//-----------------------------------------------------------------------------
largest::largest( ) : query( ) {

  handle( string( "select * from largest;" ) );

};  // end largest


// Destructor
//-----------------------------------------------------------------------------
largest::~largest( ) { };  // end destructor


// Handle the output of the query
//-----------------------------------------------------------------------------
int largest::operator() ( int cols, char** value, char** name ) {

  cout << "    Largest valid desposit: " << value[ 0 ] << endl;

  return SQLITE_OK;

};  // end operator
