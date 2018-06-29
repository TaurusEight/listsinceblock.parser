// Time-stamp: <2018-06-11 16:27:50 daniel>
#ifndef __APPLICATION_HH__
#define __APPLICATION_HH__


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
// application.hh
//


// Required header files
//-----------------------------------------------------------------------------
#include "lite.hh"  // sql::lite


// Namespace used with this class
//-----------------------------------------------------------------------------
namespace kraken {


  // Support framework for objects that are used to read, parse and output
  // a report on all transaction in the JSON files.
  //
  // Uses SQLite3 as an embedded SQL database under the name "deposit.db".
  //---------------------------------------------------------------------------
  class application {

  public:

    application();   // Constructor
    ~application();  // Destructor

    int run();

  protected:

    void run_transactions( const char* );  // parse the transactions out of JSON
    void generate_report( );  // print the report to standard out

  private:

    sql::lite db_;  // database object
    static constexpr const char* the_database = "deposit.db";

  };  // end application


};  // end NS kraken


#endif  // __APPLICATION_HH__
