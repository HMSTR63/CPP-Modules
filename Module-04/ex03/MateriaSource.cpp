#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	int i = 0;
	while (i < 4)
	{
		this->_T[i] = NULL;
		i++;
	}
}

MateriaSource::~MateriaSource()
{
	int i = 0;
	while (i < 4)
	{
		if (this->_T[i] != NULL)
			delete this->_T[i];
		i++;
	}
}

void MateriaSource::learnMateria(AMateria *M)
{
	if (M == NULL)
		return ;
	int i = 0;
	while (i < 4)
	{
		if (this->_T[i] == NULL)
		{
			this->_T[i] = M;
			return ;
		}
		i++;
	}
	delete M;
}

AMateria *MateriaSource::createMateria(std::string const &T)
{
	int i = 0;
	while (i < 4)
	{
		if (this->_T[i] != NULL && this->_T[i]->getType() == T)
			return this->_T[i]->clone();
		i++;
	}
	return NULL;
}

MateriaSource::MateriaSource(const MateriaSource &O)
{
	int i = 0;
	while (i < 4)
	{
		this->_T[i] = NULL;
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (O._T[i] != NULL)
			this->_T[i] = O._T[i]->clone();
		i++;
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &O)
{
	if (this != &O)
	{
		int i = 0;
		while (i < 4)
		{
			if (this->_T[i] != NULL)
				delete this->_T[i];
			i++;
		}
		i = 0;
		while (i < 4)
		{
			if (O._T[i] != NULL)
				this->_T[i] = O._T[i]->clone();
			else
				this->_T[i] = NULL;
			i++;
		}
	}
	return *this;
}