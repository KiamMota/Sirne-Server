#include "nebinAPI/database/mariadb.hpp"
#include <cstring>

namespace nebin {
namespace database {
namespace mariadb {


Query& Query::v(short index, int& decimal) {
  bind[index].buffer_type = MYSQL_TYPE_LONG;
  bind[index].buffer = &decimal;
  bind[index].is_null = 0;

  if(!mysql_stmt_bind_param(QueryStatement, bind)){ 
    std::cout << "dados enviados!" << std::endl;
    return *this;
  }else 
  {
    msg("erro no bind sua bicha");
    msg(mysql_stmt_error(QueryStatement));
  }
  return *this;
}


      
      
Query& Query::v(short index, std::string& string) {
  bind[index].buffer_type = MYSQL_TYPE_STRING;
  bind[index].buffer = (void *)string.c_str();
  bind[index].buffer_length = string.size();
  bind[index].is_null = 0;
  if (mysql_stmt_bind_param(QueryStatement, bind)) {
    msg(string);
    return *this;
  } 
    std::cout << "bind preparado" << std::endl;
    return *this;
}

Query& Query::v(short index, float& flutuant) {
  bind[index].buffer_type = MYSQL_TYPE_FLOAT;
  bind[index].buffer = &flutuant;
  bind[index].buffer_length = sizeof(float);
  bind[index].is_null = 0;

  mysql_stmt_bind_param(QueryStatement, bind);
  msg(mysql_stmt_error(QueryStatement));
    return *this;
}

} // namespace mariadb
} // namespace database
} // namespace nebin
