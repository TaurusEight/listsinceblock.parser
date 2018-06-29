// Time-stamp: <2018-06-11 17:02:48 daniel>


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
// query.cc
//


// Required header files
//-----------------------------------------------------------------------------
#include <iostream>  // std::cout
#include "query.hh"  // sql::query and other sql querys
#include "format.hh"  // tr::fmt


// NS short cuts
//-----------------------------------------------------------------------------
using namespace std;  // standard library
using namespace sql;  // queries


// Query
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

// class constructor
//-----------------------------------------------------------------------------
query::query() : handle_() { };  // end constructor


// Destructor
//-----------------------------------------------------------------------------
query::~query() { };  // end destructor


// handle the SQL call
//-----------------------------------------------------------------------------
int query::operator()( int cols, char** value, char** name ) {

  for ( int iter = 0; iter < cols; ++iter )
    cout << value[ iter ] << endl;

  return SQLITE_OK;

};  // end operator


// The query callback function.
// See the SQLite documentation for the sqlite3_exec function.
// https://sqlite.org/c3ref/exec.html
//
// @return int SQLITE_OK if no errors.
//-----------------------------------------------------------------------------
int query::callback( void* ptr, int cols, char** value, char** name ) {

  return ( *reinterpret_cast< query* >( ptr ) )( cols, value, name );

};  // end callback


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------


// Constructor
//
// @param address A reference to a std::string storing the client address.
//-----------------------------------------------------------------------------
client_id::client_id( const string& address ) : query(), client_id_( 0x0 ) {

  tr::fmt Q( "select id, usr from client where addr = '%1%';" );
  handle( ( Q % address ).str() );

};  // end constructor


// Destructor
//-----------------------------------------------------------------------------
client_id::~client_id() { };


// Handle the callback
//-----------------------------------------------------------------------------
int client_id::operator()( int cols, char** value, char** name ) {

  if ( cols != 0 ) client_id_ = stoi( value[ 0 ] );
  return SQLITE_OK;

};  // end operator



//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

//add_client::add_client() : client_id() {};

// Constructor
//-----------------------------------------------------------------------------
add_client::add_client( const string& address ) : client_id( address ) {

  tr::fmt Q( "insert into client ( usr, addr ) values ( 'Unknown', '%1%' ); select last_insert_rowid();" );
  handle( ( Q % address ).str() );

};  // end add_client constructor


//-----------------------------------------------------------------------------
add_client::~add_client() { };  // end destructor



//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

// Insert a deposit into the table 'amount'

// Constructor
//-----------------------------------------------------------------------------
add_deposit::add_deposit( int id, float amount, const string& txid ) {

  tr::fmt Q( "insert into deposit ( id, amount, txid ) values ( %1%, %2%, '%3%' );" );
  handle( ( Q % id % amount % txid ).str() );

};  // end constructor


// Destructor
//-----------------------------------------------------------------------------
add_deposit::~add_deposit() { };  // end destructor
