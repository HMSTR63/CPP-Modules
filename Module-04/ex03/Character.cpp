#include "Character.hpp"
#include "AMateria.hpp"

void Character::_safeCleanup()
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
		delete this->_inv[i];
		this->_inv[i] = NULL;
		i++;
	}
}

void Character::_safeDeepCopy(const Character &O)
{
	this->flag = 0;
	int i;
	i = 0;
	while (i < 4)
	{
		this->_inv[i] = NULL;
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
		if (O._inv[i] != NULL)
		{
			this->_inv[i] = O._inv[i]->clone();
			this->arry[this->flag++] = this->_inv[i];
		}
		i++;
	}

}

Character::Character() : _name("Defeault"), flag(0)
{
	int i = 0;
	while (i < 4)
		this->_inv[i++] = NULL;
    i = 0;
    while (i < 1000)
		this->arry[i++] = NULL;
}

Character::Character(std::string name) : _name(name), flag(0)
{
	int i = 0;
	while (i < 4)
		this->_inv[i++] = NULL;
    i = 0;
    while (i < 1000)
		this->arry[i++] = NULL;
}

Character::Character(const Character &O) : _name(O._name), flag(0)
{
	this->_safeDeepCopy(O);
}

Character &Character::operator=(const Character &O)
{
	if (this != &O)
	{
		this->_safeCleanup();
		this->_safeDeepCopy(O);
	}
	return *this;
}

Character::~Character()
{
	this->_safeCleanup();
}

std::string const &Character::getName() const
{
	return this->_name;
}

void Character::equip(AMateria *M)
{
	if (M == NULL)
	{
		std::cout << RED << "Cannot equip NULL Materia." << RESET << std::endl;
		return;
	}
	int i = 0;
	while (i < 4)
	{
		int j = 0;
		while (j < 4)
		{
			if (this->_inv[j] == M)
			{
				std::cout << RED << "Materia of type " << M->getType() << " is already equipped." << RESET << std::endl;
				return;
			}
			j++;
		}
		if (this->_inv[i] == NULL)
		{
			this->_inv[i] = M->clone();
			return ;
		}
		i++;
	}
    std::cout << RED << "Character " << _name << " inventory is full. Cannot equip " << M->getType() << ". Deleting Materia to prevent leak." << RESET << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3 || this->_inv[idx] == NULL)
	{
        std::cout << RED << "Cannot unequip invalid slot or NULL Materia at index [" << idx << "]." << RESET << std::endl;
		return ;
	}
	if (this->_inv[idx] && this->flag < 1000)
	{
		this->arry[this->flag++] = this->_inv[idx];
		this->_inv[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter &T)
{
	if (idx >= 0 && idx < 4 && this->_inv[idx] != NULL)
		this->_inv[idx]->use(T);
	else
        std::cout << RED << "Cannot use Materia at slot [" << idx << "]: slot is empty or invalid." << RESET << std::endl;
}
