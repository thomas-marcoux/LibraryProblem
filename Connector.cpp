#include "Connector.h"

Connector::Connector()
{
  driver = sql::mysql::get_mysql_driver_instance();
  con = driver->connect("tcp://127.0.0.1:3306", USER, PASSWORD);
  stmt = con->createStatement();
  stmt->execute("USE " DATABASE_NAME);
  res = stmt->executeQuery("SELECT name FROM user");
}

Connector::~Connector()
{
  delete res;
  delete stmt;
  delete con;
}

std::vector<sql::ResultSet*>	*Connector::getBooksFromAuthor(const char *author)
{
  std::vector<sql::ResultSet*> *v = new std::vector<sql::ResultSet*>;
  prep_stmt = con->prepareStatement("SELECT * FROM book WHERE author=?");
  prep_stmt->setString(1, std::string(author));
  res = prep_stmt->executeQuery();
  while (res->next())
    std::cout << res->getString("title") << std::endl;
    v->push_back(res);
  return v;
}

