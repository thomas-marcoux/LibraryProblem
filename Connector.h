#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <string>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <vector>
#include "mysql_driver.h"
#include "mysql_connection.h"

#define DATABASE_NAME	"Library"
#define USER		"root"
#define PASSWORD	"root"

class	Connector
{
 private:
  sql::mysql::MySQL_Driver	*driver;
  sql::Connection		*con;
  sql::Statement		*stmt;
  sql::PreparedStatement	*prep_stmt;

 public:
  sql::ResultSet		*res;
  Connector();
  ~Connector();
  std::vector<sql::ResultSet*>	*getBooksFromAuthor(const char *author);
};

#endif
