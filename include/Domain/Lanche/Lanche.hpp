#ifndef _LANCHE_H_
#define _LANCHE_H_
#include "Domain/Lanche/Vo/Calorias.hpp"
#include <string>

class Lanche
{
	private:
		std::string NomeLanche;
	public:
		Lanche(const char* NomeLanche)
		{
			this->NomeLanche = NomeLanche;

		}

};



#endif
