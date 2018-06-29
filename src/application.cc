// Time-stamp: <2018-06-11 16:21:53 daniel>


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
// application.cc
//


// Required Header Files
//-----------------------------------------------------------------------------
#include <iostream>  // std::cout
#include "application.hh"  // kraken::application
#include "json.hh"  // json::node, json::read
#include "transaction.hh"  // block::transaction
#include "notation.hh"  // json::notation
#include "report.hh"  // sql::report


// NS short cuts
//-----------------------------------------------------------------------------
using namespace std;  // standard library
using namespace kraken;  // short hand


// Constructor
//-----------------------------------------------------------------------------
application::application() : db_( application::the_database ) {

};  // end constructor


//-----------------------------------------------------------------------------
application::~application() { };  // destructor



// Parse the JSON file and handle each transaction.
// @param 'file_name' Name of the text file containing the JSON listsinceblock.
//-----------------------------------------------------------------------------
void application::run_transactions( const char* file_name ) {

  block::transaction bt;

  json::notation notation( file_name );
  json::node transaction = json::find( notation, "transactions" );

  for ( auto iter : transaction ) {
    bt = block::transaction( iter.second );
    bt.run( db_ );
  };  // end for loop

};  // end parse_file


// Generate the required output from the SQL database based on the
// sample output as defined in the file 'instruction.txt'.
//-----------------------------------------------------------------------------
void application::generate_report( ) {

  sql::report report;
  sql::unknown unknown;
  sql::smallest smallest;
  sql::largest largest;
  cout << endl << "    ```" << endl;
  db_.exec( &report );
  db_.exec( &unknown );
  db_.exec( &smallest );
  db_.exec( &largest );
  cout << "    ```" << endl;

};  // end generate_report


// Start the functions of this object instance.  Read and parse the
// text file containing the listsinceblock transactions and then
// generate the requested reports.  Throw an exception if something
// goes wrong.
// @return int This will be zero if there was no error otherwise 1.
//-----------------------------------------------------------------------------
int application::run() {

  int result = SQLITE_OK;

  try {

    run_transactions( "transactions-1.json" );
    run_transactions( "transactions-2.json" );
    generate_report();

  } catch( exception& e ) {

    cerr << "Exception: " << e.what() << endl;
    result = SQLITE_ERROR;

  };  // end try / catch

  return result;

};  // end run
