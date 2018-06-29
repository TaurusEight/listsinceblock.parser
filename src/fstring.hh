// Time-stamp: <2018-06-11 16:34:44 daniel>
#ifndef __FSTRING_HH__
#define __FSTRING_HH__

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
// fstring.hh
//


// Requirement Header Files
//-----------------------------------------------------------------------------
#include <iosfwd>  // forward decloration of stream classes
#include <string>  // std::string


// Namespace used by this class
//-----------------------------------------------------------------------------
namespace file {


  // Wrapper around the functionality of reading a text file and
  // storing it into a std::string object.
  //---------------------------------------------------------------------------
  class string {

  public:

    string( const char* );  // constructor
    virtual ~string();  // destructor

    // Overload this object so that it is treated as a std::string
    operator const std::string() const { return handle_; };
    operator const std::string*() const { return &handle_; };

    // Used for outputing this data to a stream
    friend std::ostream& operator<<( std::ostream&,  const file::string& );

  protected:

  private:

    std::string handle_;  // actual string being used

  };  // end class file::string


  std::ostream& operator<<( std::ostream&, const file::string& );

};  // end NS file



#endif  // __FSTRING_HH__
