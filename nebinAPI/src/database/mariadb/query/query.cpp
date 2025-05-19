#include "nebinAPI/database/mariadb.hpp"
#include <cstring>

namespace nebin {
namespace database {
namespace mariadb {

void Query::RawQuery(std::string query)
{
  if(mysql_query(QueryContext, query.c_str()))
  {
    msg("erro na query!");
    return;
  }
  msg("~ nebin <database> [ok] [->]: query enviada");
}


Query& Query::PrepareQuery(std::string query)
{
  m_bindquery_str = query;
  if(mysql_stmt_prepare(QueryStatement, m_bindquery_str.c_str(), m_bindquery_str.size()))
  {
    msg(mysql_stmt_error(QueryStatement));
    msg("erro na preparação da string de query!");
  }
  return *this;
}

void Query::Execute()
{
  if(mysql_stmt_execute(QueryStatement))
  {
    msg("erro na execução do bind");
    msg(mysql_stmt_error(QueryStatement));
    m_bindquery_str.clear();
    return;
  }
    msg("tratamento correto, mandado pro banco!");
    m_bindquery_str.clear();
}

} // namespace mariadb
} // namespace database
} // namespace nebin

