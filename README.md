

‘block.parse’
-------------

An application to parse ‘listsinceblock’ from JSON text files and store
and filter valid deposit to known clients.



Build Instructions:
-------------------

* By Docker.  The command ‘docker-compose up’ should be sufficient to
  build the application.  Or ‘docker build -t block.parse .’ if using
  the docker command.

* At the command line.  Change into the directory 'src' and issue the
  command ‘Make’.


Programming assumptions:
------------------------

* Deposit vs Withdraw.  Only transactions with a category attribute of
  ‘recieve’ are considered valid deposit.  Transactions with a category
  attribute of ‘send’ are considered withdrawals and will be ignored.

* Number of Confirmations.  Those transactions with a confirmations
  attribute value of less than six will be ignore.  As per the instructions.

* Output precision.   Generated reports will have an 8 digit limit to
  numerical precision.

* Duplicate transactions.  Transactions that have a txid attribute that
  duplicates the txid value of a previous transaction will be considered
  a duplication and is ignored.  The code will throw an exception and
  print a brief error message.


Programming notes:
------------------

* SQLite3 is used as the storage database.

* C++17 is used as the  programming language.

* Besides the sqlite3 library, the only other external library used and
  referenced is the Boost programming library.

* A Docker container is used for testing and debugging.  Both a Dockerfile
  and a docker-compose.yml file are included.

* The application builds with standard GNU Make.


Possible enhancements:
----------------------

* SQLite3 could be replaced with a dedicated database application such
  as MySQL or PostgreSQL.

* More detailed error logging could be implemented including output to a file.

* Withdrawals could be handled as well as deposits.
