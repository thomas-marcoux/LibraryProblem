#include "Connector.h"

Connector::Connector()
{
  driver = sql::mysql::get_mysql_driver_instance();
  con = driver->connect("tcp://127.0.0.1:3306", "USER", PASSWORD);
  stmt = con->createStatement();
  //stmt->execute("USE " DATABASE_NAME);
  /*
  stmt->execute("USE Library;");
  stmt->execute("DESC book;");
  stmt->execute("DROP TABLE IF EXISTS test");
  stmt->execute("CREATE TABLE test(id INT, label CHAR(1))");
  stmt->execute("INSERT INTO test(id, label) VALUES (1, 'a')");
  */
}

Connector::~Connector()
{
  /*
  delete stmt;
  delete con;
  */
}
