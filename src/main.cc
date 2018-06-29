// Time-stamp: <2018-06-11 16:42:22 daniel>


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
// main.cc
//


// Required header files
//-----------------------------------------------------------------------------
#include <iostream>  // std::cout, std::endl
#include "application.hh"  // kraken::application


// Entry into the application.  Parameters ignored.
//-----------------------------------------------------------------------------
int main( int, char*[] ) {

  kraken::application app;
  return app.run();

};  // end main
