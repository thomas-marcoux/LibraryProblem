#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <string>
#include "mysql_driver.h"

#define DATABASE_NAME	"Library"
#define USER		"root"
#define PASSWORD	"root"

class	Connector
{
 private:
  sql::mysql::MySQL_Driver	*driver;
  sql::Connection		*con;
  sql::Statement		*stmt;

 public:
  Connector();
  ~Connector();
};

#endif
