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
	std::cout << BLUE << "Character " << _name << " default constructed." << RESET << std::endl;
	int i = 0;
	while (i < 4)
		this->_inv[i++] = NULL;
    i = 0;
    while (i < 1000)
		this->arry[i++] = NULL;
}

Character::Character(std::string name) : _name(name), flag(0)
{
    std::cout << BLUE << "Character " << _name << " constructed." << RESET << std::endl;
	int i = 0;
	while (i < 4)
		this->_inv[i++] = NULL;
    i = 0;
    while (i < 1000)
		this->arry[i++] = NULL;
}

Character::Character(const Character &O) : _name(O._name), flag(0)
{
    std::cout << BLUE << "Character " << _name << " constructed." << RESET << std::endl;
	this->_safeDeepCopy(O);
}

Character &Character::operator=(const Character &O)
{
	if (this != &O)
	{
        std::cout << MAGENTA << "Character assignment operator called. Deep cleaning old data..." << RESET << std::endl;
		this->_safeCleanup();
		this->_safeDeepCopy(O);
	}
	return *this;
}

Character::~Character()
{
    std::cout << BLUE << "Character " << _name << " destroyed. Cleaning up " << this->flag << " Materias (equipped/unequipped)." << RESET << std::endl;
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
	if (this->flag >= 1000)
	{
        std::cout << RED << "Character " << _name << " has reached the maximum Materia ownership limit (" << 1000 << "). Equip rejected and Materia deleted." << RESET << std::endl;
        delete M;
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
			this->_inv[i] = M;
			this->arry[this->flag] = this->_inv[i];
			this->flag++;
            std::cout << CYAN << "Character " << _name << " equipped " << M->getType() << " at slot [" << i << "]." << RESET << std::endl;
			return ;
		}
		i++;
	}
    std::cout << RED << "Character " << _name << " inventory is full. Cannot equip " << M->getType() << ". Deleting Materia to prevent leak." << RESET << std::endl;
	delete M;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3 || this->_inv[idx] == NULL)
	{
        std::cout << RED << "Cannot unequip invalid slot or NULL Materia at index [" << idx << "]." << RESET << std::endl;
		return ;
	}
    std::cout << CYAN << "Character " << _name << " unequipped " << this->_inv[idx]->getType() << " at slot [" << idx << "]. (Materia moved to the floor for later deletion)." << RESET << std::endl;
	this->_inv[idx] = NULL;
}

void Character::use(int idx, ICharacter &T)
{
	if (idx >= 0 && idx < 4 && this->_inv[idx] != NULL)
		this->_inv[idx]->use(T);
	else
        std::cout << RED << "Cannot use Materia at slot [" << idx << "]: slot is empty or invalid." << RESET << std::endl;
}