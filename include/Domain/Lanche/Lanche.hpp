#ifndef _LANCHE_H_
#define _LANCHE_H_

#include <string>

class Lanche
{
	private:
		long id;
		std::string NomeLanche;
		int	calorias;
		bool lactose;
	public:
		Lanche(const char* NomeLanche, int calorias)
		{
			this->NomeLanche = NomeLanche;
			this->calorias = calorias;	
		}

		int GetId()						{return id;}
		std::string GetNome() {return NomeLanche;}
		int GetCalorias()			{return calorias;}
		bool GetLactose()			{return lactose;}
};

#endif
