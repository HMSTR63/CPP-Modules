#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	int i = 0;
	while (i < 1000)
		this->arry[i++] = NULL;
	i = 0;
	while (i < 4)
	{
		this->_T[i] = NULL;
		i++;

	}
	flag = 0;
}

MateriaSource::~MateriaSource()
{
	int i = 0;
	while (i < 1000)
	{
		if (this->arry[i])
		{
			delete this->arry[i];
			this->arry[i] = NULL;
		}
		i++;
	}
	i = 0;
	while (i < 0)
	{
		this->_T[i] = NULL;
		i++;
	}
}

void MateriaSource::learnMateria(AMateria *M)
{
	if (M == NULL)
		return;
	int i = 0;
	while (i < 4)
	{
		if (this->_T[i] == M)
			return;
		if (this->_T[i] == NULL)
		{
			this->_T[i] = M;
			this->arry[this->flag] = M;
			this->flag++;
			return ;
		}
		i++;
	}
}

AMateria *MateriaSource::createMateria(std::string const &T)
{
	int i;
	i = 0;
	while (i < 4)
	{
		if (this->_T[i] && this->_T[i]->getType() == T)
			return this->_T[i]->clone();
		i++;
	}
	return NULL;
}

MateriaSource::MateriaSource(const MateriaSource &O)
{
	int     i = 0;
	flag = 0;
    while (i < 1000)
    {

        arry[i] = NULL;
    }
	 i = 0;
	while (i < 4)
	{
		this->_T[i] = NULL;
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (O._T[i] != NULL)
		{
			this->_T[i] = O._T[i]->clone();
			this->arry[this->flag++] = this->_T[i];
			
		}
		i++;
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &O)
{
	if (this != &O)
	{
		int i = 0;

        while (arry[i])
        {
            delete arry[i];
            arry[i] = NULL;
            i++;
        }
        i = 0;
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
			{
				this->_T[i] = O._T[i]->clone();
				this->arry[this->flag++] = this->_T[i];
			}

			else
				this->_T[i] = NULL;
			i++;
		}
	}
	return *this;
}