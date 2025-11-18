#include "Character.hpp"
#include "AMateria.hpp"

Character::Character() : _name("Defeault")
{
	int i = 0;
	while (i < 4)
		this->_inv[i++] = NULL;
    i = 0;
    while (i < 1000)
		this->arry[i++] = NULL;
    flag = 0;
}

Character::Character(std::string name) : _name(name)
{
	int i = 0;
	while (i < 4)
		this->_inv[i++] = NULL;
    i = 0;
    while (i < 1000)
		this->arry[i++] = NULL;
    flag = 0;
}

Character::Character(const Character &O) : _name(O._name)
{
	int i = 0;
	flag = 0;
    while (i < 1000)
    {
        arry[i] = NULL;
        i++;
    }
	i = 0;
	while (i < 4)
	{
		this->_inv[i] = NULL;
		i++;
	}
    i = 0;
	while (i < 4)
	{
		if (O._inv[i] != NULL)
        {
			this->_inv[i] = O._inv[i]->clone();
            this->arry[flag] = this->_inv[i];
            this->flag++;
        }
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
        while (arry[i])
        {
			if (this->arry[i])
			{
				delete arry[i];
				arry[i] = NULL;
				i++;
			}
        }
        i = 0;
		while (i < 4)
		{
			this->_inv[i] = NULL;
			i++;
		}
        flag = 0;
		i = 0;
		while (i < 4)
		{
			if (this->_inv[i] != NULL)
			{
				delete this->_inv[i];
				this->_inv[i] = NULL;
			}
			if (O._inv[i] != NULL)
            {
				this->_inv[i] = O._inv[i]->clone();
                arry[flag++] = this->_inv[i];
            }
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
		this->_inv[i] = NULL;
		i++;
	}
    
}

std::string const &Character::getName() const
{
	return this->_name;
}

void Character::equip(AMateria *M)
{
	if (M == NULL)
		return;
	int i = 0;
	while (i < 4)
	{
		if (this->_inv[i] == M)
			return;
		if (this->_inv[i] == NULL)
		{
			this->_inv[i] = M;
			this->arry[this->flag] = M;
			this->flag++;
			return ;
		}
		i++;
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		return ;
	if (idx >= 0 && idx < 4 && this->_inv[idx] != NULL)
		this->_inv[idx] = NULL;
}

void Character::use(int idx, ICharacter &T)
{
	if (idx >= 0 && idx < 4 && this->_inv[idx] != NULL)
		this->_inv[idx]->use(T);
}