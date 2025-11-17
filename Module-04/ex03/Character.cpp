#include "Character.hpp"
#include "AMateria.hpp"

Character::Character() : _name("Defeault")
{
	int i = 0;
	while (i < 4)
		this->_inv[i++] = NULL;
}

Character::Character(std::string name) : _name(name)
{
	int i = 0;
	while (i < 4)
		this->_inv[i++] = NULL;
}

Character::Character(const Character &O)
{
	this->_name = O._name;
	int i = 0;
	while (i < 4)
	{
		if (O._inv[i] != NULL)
			this->_inv[i] = O._inv[i]->clone();
		else
			this->_inv[i] = NULL;
		i++;
	}
}

Character &Character::operator=(const Character &O)
{
	if (this != &O)
	{
		this->_name = O._name;
		int i = 0;
		while (i < 4)
		{
			if (this->_inv[i] != NULL)
				delete this->_inv[i];
			i++;
		}
		i = 0;
		while (i < 4)
		{
			if (O._inv[i] != NULL)
				this->_inv[i] = O._inv[i]->clone();
			else
				this->_inv[i] = NULL;
			i++;
		}
	}
	return *this;
}

Character::~Character()
{
	int i = 0;
	while (i < 4)
	{
		if (this->_inv[i] != NULL)
			delete this->_inv[i];
		i++;
	}
}

std::string const &Character::getName() const
{
	return this->_name;
}

void Character::equip(AMateria *M)
{
	if (!M)
		return;
	int i = 0;
	while (i < 4)
	{
		if (this->_inv[i] == NULL)
		{
			this->_inv[i] = M;
			return ;
		}
		i++;
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && this->_inv[idx] != NULL)
		this->_inv[idx] = NULL;
}

void Character::use(int idx, ICharacter &T)
{
	if (idx >= 0 && idx < 4 && this->_inv[idx] != NULL)
		this->_inv[idx]->use(T);
}