// Time-stamp: <2018-06-11 17:06:10 daniel>
#ifndef __REPORT_HH__
#define __REPORT_HH__


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
// report.hh
//


// Required header files
//-----------------------------------------------------------------------------
#include "query.hh"  // sql::query


// Namespace used with this class
//-----------------------------------------------------------------------------
namespace sql {


  // Output data for all known clients
  //---------------------------------------------------------------------------
  class report : public query {
  public:
    report();
    ~report();
    int operator() ( int, char**, char** );
  protected:
  private:
  };  // end class report


  // Output data for all unknown clients
  //---------------------------------------------------------------------------
  class unknown : public query {
  public:
    unknown();
    ~unknown();
    int operator()( int, char**, char** );
  protected:
  private:
  };  // end class unknown


  // Output data about the smalled valid deposit
  //---------------------------------------------------------------------------
  class smallest : public query {
  public:
    smallest();
    ~smallest();
    int operator()( int, char**, char** );
  protected:
  private:
  };  // end class smallest


  // Output data associated with the largest valid deposit
  //---------------------------------------------------------------------------
  class largest : public query {
  public:
    largest();
    ~largest();
    int operator()( int, char**, char** );
  protected:
  private:
  };  // end class largest


};  // end NS sql


#endif  // __REPORT_HH__
