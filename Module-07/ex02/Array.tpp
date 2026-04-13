
template <typename T>
Array<T>::Array() : _data(NULL), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int size) : _size(size)
{
	if (size > 0)
        this->_data = new T[size]();
    else
        this->_data = NULL;
}

template <typename T>
Array<T>::Array(const Array& O) : _data(NULL), _size(0)
{
    *this = O;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& O)
{
    if (this != &O)
    {
        delete[] this->_data;
        this->_size = O._size;
        this->_data = new T[this->_size];
        unsigned int x = 0;
        while (x < this->_size)
        {
            this->_data[x] = O._data[x];
            x++;
        }
    }
    return *this;
}

template <typename T>
Array<T>::~Array()
{
    delete[] this->_data;
}

template <typename T>
T& Array<T>::operator[](unsigned dex)
{
    if (dex >= this->_size) throw Array<T>::OutOfRange();
    return this->_data[dex];
}

template <typename T>
const T& Array<T>::operator[](unsigned dex) const
{
    if (dex >= this->_size) throw Array<T>::OutOfRange();
    return this->_data[dex];
}

template <typename T>
unsigned int Array<T>::size() const
{
    return this->_size;
}

template <typename T>
const char* Array<T>::OutOfRange::what() const throw()
{
    return "Array is Out of the Range!";
}
