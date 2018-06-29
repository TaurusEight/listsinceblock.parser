// Time-stamp: <2018-06-11 16:49:50 daniel>
#ifndef __QUERY_HH__
#define __QUERY_HH__


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
// query.hh
//


// Required header files
//-----------------------------------------------------------------------------
#include <string>  // std::string
#include <sqlite3.h>  // SQLITE_OK


// Namespace used with this class
//-----------------------------------------------------------------------------
namespace sql {


  // Wrapper around the handler of the Sqlite3 exec callback function
  //---------------------------------------------------------------------------
  class query {

  public:

    query();  // constructor
    virtual ~query();  // destructor

    virtual int operator()( int, char**, char** );
    static int callback( void*, int, char**, char** );

    const char* c_str() const { return handle_.c_str(); };

  protected:

    void handle( const std::string& S ) { handle_ = S; };

  private:

    std::string handle_;

  };  // end class query


  // Wrapper around a query to seek the row id for this address in 'client'
  //---------------------------------------------------------------------------
  class client_id : public query {

  public:

    client_id( const std::string& );
    ~client_id();

    int operator()( int, char**, char** );
    operator int() const { return client_id_; };

  protected:

  private:

    int client_id_;

  };  // end class client_id


  // Wrapper around the query that adds a new client to this database.
  //---------------------------------------------------------------------------
  class add_client : public client_id {
  public:
    add_client( const std::string& );
    ~add_client();
  protected:
  private:

  };  // end add_client


  // Wrapper around the query that adds this clients deposit into the database.
  //---------------------------------------------------------------------------
  class add_deposit : public query {
  public:
    add_deposit( const int, const float, const std::string& );
    ~add_deposit();
  protected:
  private:
  };  // end add_deposit


};  // end NS sql


#endif  // __QUERY_HH__
