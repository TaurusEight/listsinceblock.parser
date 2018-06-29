-- Time-stamp: <2018-06-11 19:42:31 daniel>


--
-- deposit.sql
--

-- This script is part of the application 'block.parse' which
-- is used to deminstrate parsing of a listsinceblock JSON file.


-- This table holds a row id, a user name and an address
-- for each unique client.  This table will also hold
-- this information for unknown clients.
-- ----------------------------------------------------------------------------
drop table if exists client;
create table if not exists client (
  id integer primary key,
  usr text not null,
  addr text unique not null
);


-- Fill the client table with default client data.
-- ----------------------------------------------------------------------------
insert or ignore into client ( usr, addr ) values
  ( 'Wesley Crusher', 'mvd6qFeVkqH6MNAS2Y2cLifbdaX5XUkbZJ' ),
  ( 'Leonard McCoy', 'mmFFG4jqAtw9MoCC88hw5FNfreQWuEHADp' ),
  ( 'Jonathan Archer', 'mzzg8fvHXydKs8j9D2a8t7KpSXpGgAnk4n' ),
  ( 'Jadzia Dax', '2N1SP7r92ZZJvYKG2oNtzPwYnzw62up7mTo' ),
  ( 'Montgomery Scott', 'mutrAf4usv3HKNdpLwVD4ow2oLArL6Rez8' ),
  ( 'James T. Kirk', 'miTHhiX3iFhVnAEecLjybxvV5g8mKYTtnM' ),
  ( 'Spock', 'mvcyJMiAcSXKAEsQxbW9TYZ369rsMG6rVV' );


-- This table holds all data associated with a valid deposit.
-- The id is the row id of the client table associated with
-- the address in each deposit.
-- ----------------------------------------------------------------------------
drop table if exists deposit;
create table if not exists deposit (
  id integer not null,
  amount real not null,
  txid text unique not null
);


-- A view that joins the client table and the deposit table.
-- It allows an easy way to summerize the client data by
-- grouping it based on each row id.
-- Note that it excludes the data associated with an unknown client.
-- ----------------------------------------------------------------------------
drop view if exists report;
create view report as
 select usr, count( amount ) as cnt, printf( "%.8f", sum( amount ) ) as sm
 from client join deposit on client.id = deposit.id
 where usr != 'Unknown' and client.id = deposit.id
 group by client.id
 order by client.id;


-- Create a view that groups and sums the data associated
-- with the valid deposits for unknown users.
-- ----------------------------------------------------------------------------
drop view if exists unknown;
create view unknown as
  select count( amount ) as cnt, printf( "%.8f", sum( amount ) ) as sm
  from client join deposit on client.id = deposit.id
  where usr == 'Unknown' and client.id = deposit.id;


-- Simple view that formats the smallest valid deposit in table depoist.
-- ----------------------------------------------------------------------------
drop view if exists smallest;
create view smallest as
  select printf( "%.8f", min( amount ) ) as amnt
  from deposit;


-- Simple view that formats the largest valid deposit in table deposit.
-- ----------------------------------------------------------------------------
drop view if exists largest;
create view largest as
  select printf( "%.8f", max( amount ) ) as amnt
  from deposit;
