#include <nebinAPI/database/mariadb.hpp>
#include <nebinAPI/nebin.hpp>
namespace nebin {
namespace database {
namespace mariadb {

DbService::DbService(const char *host, const char *database)
    : context(mysql_init(NULL))  {

  internal.host = new char[strlen(host) + 1];
  internal.database = new char[strlen(database) + 1];
  strcpy(internal.host, host);
  strcpy(internal.database, database);
}

short DbService::User(const char *db_user, const char *db_pwd) {
  if (!db_user || !db_pwd) {
    LOG_ERROR(10, "erro das credenciais");
  }
  if (internal.db_user && internal.db_pwd) {
    LOG_ERROR(77, "");
    return -1;
  }
  internal.db_user = new char[strlen(db_user) + 1];
  internal.db_pwd = new char[strlen(db_pwd) + 1];

  strcpy(internal.db_user, db_user);
  strcpy(internal.db_pwd, db_pwd);

  if (!mysql_real_connect(context, internal.host, db_user, db_pwd,
                          internal.database, 0, NULL, 0)) {
    std::cout << mysql_error(context) << std::endl;
    return 1;
  } else {
    std::cout << "banco conectado com sucesso" << std::endl;
  }
  return 0;
}


} // namespace mariadb
} // namespace database
} // namespace nebin
