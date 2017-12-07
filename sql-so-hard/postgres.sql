CREATE DATABASE userdb;
CREATE ROLE userdb WITH PASSWORD 'userdb';
GRANT ALL PRIVILEGES ON DATABASE userdb TO userdb;
ALTER ROLE userdb WITH LOGIN;

\connect userdb;

CREATE TABLE users ( username varchar(250), password varchar(250));
GRANT ALL PRIVILEGES ON TABLE users TO userdb;



