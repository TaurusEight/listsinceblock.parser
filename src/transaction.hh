// Time-stamp: <2018-06-12 13:02:32 daniel>
#ifndef __TRANSACTION_HH__
#define __TRANSACTION_HH__


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
// transaction.hh
//


// Required header files
//-----------------------------------------------------------------------------
#include <string>  // std::string
#include <iosfwd>  // forward decloration of iostream objects
#include "json.hh"  // json::node
#include "lite.hh"  // sql::lite
#include "query.hh"  // sql::query


// Namespace used with this class
//-----------------------------------------------------------------------------
namespace block {


  // This class is a wrapper around all function associated with
  // each transaction fround in the listsinceblock
  //---------------------------------------------------------------------------
  class transaction {

  public:

    transaction( json::node& );  // Main constructor
    transaction( const transaction& );  // Copy constructor
    transaction( );  // Default constructor
    virtual ~transaction();

    const std::string address() const { return address_; };
    const float amount() const { return amount_; };
    const std::string txid() const { return txid_; };

    void run( sql::lite& );

    friend std::ostream& operator<<( std::ostream&, const transaction& );

  protected:

    void parse_address( json::node& );
    void parse_amount( json::node& );
    void parse_category( json::node& );
    void parse_txid( json::node& );
    void parse_confirmations( json::node& );

    int existing_client( sql::lite& );
    int insert_client( sql::lite& );
    void insert_deposit( int, sql::lite& );

  private:

    std::string address_;
    float amount_;
    std::string category_;
    std::string txid_;
    int confirmations_;

    static const int min_confirmations = 0x6;

  };  // end class transaction

  std::ostream& operator<<( std::ostream&, const transaction& );

};  // end NS block

#endif  // __TRANSACTION_HH__
