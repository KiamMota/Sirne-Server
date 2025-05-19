#include <iostream>

#include <mariadb/mysql.h>

#if !defined(MARIA_CLASS)
#define MARIA_CLASS

#define msg(literal_string) std::cout << literal_string << std::endl;
#define sucesso() std::cout << "sucesso!" << std::endl;

namespace nebin {
namespace database {
namespace mariadb{
  
class DbService{
  protected:
  MYSQL *context;
  
  struct internal_data {
  public:
    internal_data()
        : host(NULL), database(NULL), db_user(NULL), db_pwd(NULL), file(NULL) {}
    ~internal_data() {
      if (host)
        delete[] host;
      if (database)
        delete[] database;
      if (db_user)
        delete[] db_user;
      if (db_pwd)
        delete[] db_pwd;
      if (file)
        delete[] file;
    }
    char *host;
    char *database;
    char *db_user;
    char *db_pwd;
    char *file;
  };
public:
  MYSQL* GetContext() {return context;}
  DbService(const char *host = "localhost", const char *database = "nebin");
  internal_data internal{};
  short User(const char *db_user = NULL, const char *db_pwd = NULL);
  void close();
};

//---

class Query {
private:
  MYSQL *QueryContext;
  MYSQL_STMT *QueryStatement;
  MYSQL_BIND bind[10];

  std::string m_bindquery_str;
  int m_ivalue;
  float m_fvalue;

public:

  Query(DbService* obj) : QueryContext(obj->GetContext()), 
  QueryStatement(mysql_stmt_init(QueryContext)) 
  {}

  Query &PrepareQuery(std::string query);
  Query &v(short index, int& decimal);
  Query &v(short index, std::string& string);
  Query &v(short index, float& flutu);

  void RawQuery(std::string query);
  void Execute();
};

}
} // namespace database
} // namespace nebin

#endif
