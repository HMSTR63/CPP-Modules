#include "MateriaSource.hpp"
#include "AMateria.hpp"


void MateriaSource::_safeCleanup()
{
	int i;

	i = 0;
	while (i < 1000)
	{
		if (this->arry[i])
		{
			delete this->arry[i];
			this->arry[i] = NULL;
		}
		i++;
	}
	this->flag = 0;
	i = 0;
	while (i < 4)
	{
		this->_T[i] = NULL;
		i++;
	}
}

void MateriaSource::_safeDeepCopy(const MateriaSource &O)
{
	this->flag = 0;
	int i;
	i = 0;
	while (i < 4)
	{
		this->_T[i] = NULL;
		i++;
	}
	i = 0;
	while (i < 1000)
	{
		this->arry[i] = NULL;
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

MateriaSource::MateriaSource() : flag(0)
{
	std::cout << BLUE << "MateriaSource default constructed." << RESET << std::endl;
	int i = 0;
	while (i < 1000)
		this->arry[i++] = NULL;
	i = 0;
	while (i < 4)
	{
		this->_T[i] = NULL;
		i++;
	}
}

MateriaSource::~MateriaSource()
{
    std::cout << BLUE << "MateriaSource destroyed. Cleaning up " << this->flag << " learned Materias." << RESET << std::endl;
	this->_safeCleanup();
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
			std::cout << YELLOW << "MateriaSource learned " << M->getType() << " at slot [" << i << "]." << RESET << std::endl;
			return ;
		}
		i++;
	}
	std::cout << RED << "MateriaSource is full. Cannot learn " << M->getType() << ". Deleting Materia to prevent leak." << RESET << std::endl;
	delete M;
}

AMateria *MateriaSource::createMateria(std::string const &T)
{
	int i;
	i = 0;
	while (i < 4)
	{
		if (this->_T[i] && this->_T[i]->getType() == T)
		{
			std::cout << YELLOW << "MateriaSource created a new " << T << " Materia." << RESET << std::endl;
			return this->_T[i]->clone();
		}
		i++;
	}
	std::cout << RED << "MateriaSource failed to create Materia of type '" << T << "'." << RESET << std::endl;
	return NULL;
}

MateriaSource::MateriaSource(const MateriaSource &O)
{
	std::cout << BLUE << "MateriaSource copy constructed." << RESET << std::endl;
	this->_safeDeepCopy(O);
}

MateriaSource &MateriaSource::operator=(const MateriaSource &O)
{
	if (this != &O)
	{
		std::cout << MAGENTA << "MateriaSource assignment operator called. Deep cleaning old data..." << RESET << std::endl;	
		this->_safeCleanup();
		this->_safeDeepCopy(O);
	}
	return *this;
}