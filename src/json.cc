// Time-stamp: <2018-06-11 15:52:47 daniel>

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
// json.cc:
//


// Required header files
//-----------------------------------------------------------------------------
#include <iostream>  // std::ostream
#include <boost/property_tree/json_parser.hpp>  // write_json
#include "json.hh"  // json::write
#include "format.hh"  // tr::fmt


// Namespace short hand
//-----------------------------------------------------------------------------
using namespace std;  // standard libary


// Read from a JSON file and stick the data into branch
//-----------------------------------------------------------------------------
//void json::read( const string& file_name, json::node& branch ) {
//  boost::property_tree::json_parser::read_json( file_name, branch );
//};  // end json::read


// Read from a JSON file and stick the data into branch
//-----------------------------------------------------------------------------
void json::read( const string* json_string, json::node& branch ) {

  stringstream ss;
  ss << *json_string;
  boost::property_tree::json_parser::read_json( ss, branch );

};  // end json::read



// Write this file to the output stream
//-----------------------------------------------------------------------------
void json::write( ostream& out, const json::node& branch, bool conditional ) {

  boost::property_tree::json_parser::write_json( out, branch, conditional );

};  // end json::write


// Short hand for finding if a key is present in this node
//-----------------------------------------------------------------------------
bool json::has( const json::node& tree, const char* key ) {

  return tree.find( key ) != tree.not_found();

};  // end has


// Return true if the key is not in the tree
//-----------------------------------------------------------------------------
bool json::does_not_have( const json::node& tree, const char* key ) {

  return tree.find( key ) == tree.not_found();

};  // end does_not_have


// Find a key in the passed JSON data
//-----------------------------------------------------------------------------
json::node json::find( const json::node& tree, const char* key ) {

  string error = boost::str( tr::fmt( "JSON key %s not found." ) % key );

  if ( json::does_not_have( tree, key ) ) throw runtime_error( error );
  return tree.get_child( key );

};  // end find
