// Time-stamp: <2018-06-12 16:04:37 daniel>


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
// transaction.cc
//


// Required Header Files
//-----------------------------------------------------------------------------
#include <iostream>  // std::ostream
#include "transaction.hh"  // block::transaction
#include "lite.hh"  // sql::lite


// NS short hand
//-----------------------------------------------------------------------------
using namespace block;  // main NS for this class
using namespace std;  // short hand for use with standard lib objects


// Transaction object constructor
//
// @param json The raw JSON data holding data for this transaction.
//-----------------------------------------------------------------------------
transaction::transaction( json::node& json )
  : address_(), amount_( 0x0 ), category_(), txid_() {

  parse_address( json );
  parse_amount( json );
  parse_category( json );
  parse_txid( json );
  parse_confirmations( json );

};  // end constructor


// Transaction object copy constructor
//
// @param trans Constant reference to an existing block::transaction object.
//-----------------------------------------------------------------------------
transaction::transaction( const transaction& T )
  : address_( T.address_ ), amount_( T.amount_ ) {};  // end copy constructor


// Transaction object default constructor
//-----------------------------------------------------------------------------
transaction::transaction()
  : address_(), amount_( 0.0 ) { };  // end default constructor


// Transaction object destructor
//-----------------------------------------------------------------------------
transaction::~transaction() { };  // end destructor


// Parse the client address from this transaction.
//
// @param data A reference to the JSON data for this transaction.
//-----------------------------------------------------------------------------
void transaction::parse_address( json::node& data ) {

  json::node address( json::find( data, "address" ) );
  address_ = address.get_value< string >();

};  // end parse_address


// Parse the amount of the transaction from the raw data.
//
// @param data A reference to the JSON data for this transaction.
//-----------------------------------------------------------------------------
void transaction::parse_amount( json::node& data ) {

  json::node amount( json::find( data, "amount" ) );
  amount_ = amount.get_value< float >();

};  // end parse_amount


// Parse the category out of the data for this transaction.
//
// @param data A reference to the JSON data for this transaction.
//-----------------------------------------------------------------------------
void transaction::parse_category( json::node& data ) {

  json::node category( json::find( data, "category" ) );
  category_ = category.get_value< string >();

};  // end parse_category


// Parse out the transacation id
//
// @param data A reference to the JSON data for this transaction.
//-----------------------------------------------------------------------------
void transaction::parse_txid( json::node& data ) {

  json::node txid( json::find( data, "txid" ) );
  txid_ = txid.get_value< string >();

};  // end parse_txid


// Parse the number of confirmations associated with this transaction.
//
// @param data A reference to the raw JSON data for this transaction.
//-----------------------------------------------------------------------------
void transaction::parse_confirmations( json::node& data ) {

  json::node confirmations( json::find( data, "confirmations" ) );
  confirmations_ = confirmations.get_value< int >();

};  // end parse_confirmations


// Output the address and amount of this transaction to an output stream.
//
// @param out A reference to the output stream.
// @param tr A constant reference to a block::transaction.
// @return std::ostream& The reference to the stream passed into this function.
//-----------------------------------------------------------------------------
ostream& block::operator<<( ostream& out, const transaction& tr ) {

  out << tr.address() << " : " << tr.amount();
  return out;

};  // end operator<<


// Is this transaction for an existing client?
//
// @param db A reference to the open database object.
// @return int The numerical id of the row storing this clients data.
//-----------------------------------------------------------------------------
int transaction::existing_client( sql::lite& db ) {

  sql::client_id id( address_ );
  db.exec( &id );
  return id;

};  // end existing_row


// Add a new client into the SQL table 'client'.
//
// @param db A reference to the open database object.
// @return int The numerical id of the row storing this clients data.
//-----------------------------------------------------------------------------
int transaction::insert_client( sql::lite& db ) {

  sql::add_client id( address_ );
  db.exec( &id );
  return id;

};  // end insert_row


// Insert this data into the database.
//
// @param row_id The id of this row, or client account, in the SQL database.
// @param db A reference to the open database object.
//-----------------------------------------------------------------------------
void transaction::insert_deposit( int row_id, sql::lite& db ) {

  sql::add_deposit id( row_id, amount_, txid_ );
  db.exec( &id );

};  // end insert_deposit


// Log this transaction into the SQL database.  If the transaction is of
// category 'send' it is a withdraw and is ignored because the instruction
// required that only valid DEPOSITS are considered.
//
// Also, if a deposit is for an amount of zero it is also not valid and
// so is also ignored.
//
// This set of actions is wrapped within a try / catch block in order to
// log any errors, to standard error, for each transaction.
//-----------------------------------------------------------------------------
void transaction::run( sql::lite& db ) {


  try {

    if ( category_.compare( "send" ) == 0 ) return;  // not a valid deposit
    if ( amount_ <= 0.0 ) return;  // maybe valid but not a deposit
    if ( confirmations_ < transaction::min_confirmations ) return; // not valid

    int row_id = existing_client( db );  //
    if ( row_id == 0 ) row_id = insert_client( db );

    insert_deposit( row_id, db );

  } catch( exception& e ) {

    cerr << "Exception " << e.what() << " : transaction '"
         << txid_ << "' ignored." << endl;

  };  // end try / catch

};  // end name
