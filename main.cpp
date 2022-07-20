#include <iostream>
#include <vector>
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>




template <class T>
class MyVector
{
public:
	MyVector()
	{
		this->ptr = nullptr;
		this->size = 0;
	}

	MyVector(T _size)
	{
		delete[] this->ptr;
		this->ptr = new T[_size];
		this->size = _size;
		for (size_t i = 0; i < this->size; i++)
		{
			this->ptr[i] = 0;
		}
	}

	MyVector(const MyVector& _other)
	{
		this->size = _other.size;
		delete[] this->ptr;
		this->ptr = new T[this->size];

		for (size_t i = 0; i < this->size; i++)
		{
			this->ptr[i] = _other.ptr[i];
		}
	}
	
	MyVector(const MyVector&& _other)
	{
		this->ptr = _other.ptr;
		this->size = _other.size;
	}



	~MyVector()
	{
		this->size = 0;
		delete[] this->ptr;
		this->ptr = nullptr;
	}

	void push_back(const T _value)
	{
		T* new_ptr = new T[this->size + 1];

		for (size_t i = 0; i < size; i++)
		{
			new_ptr[i] = this->ptr[i];
		}
		
		delete[] this->ptr;

		new_ptr[size] = _value;
		this->size++;
		this->ptr = new_ptr;
	}

	bool is_empty()
	{
		return this->size == 0;
	}



	size_t Size()
	{
		return this->size;
	}


	T& operator [](T _index)
	{
		std::cout << "not const\n";
		return this->ptr[_index];
	}

	const T& operator [](T _index) const
	{
		std::cout << "const\n";
		return this->ptr[_index];
	}


	MyVector& operator = (const MyVector& _other)
	{
		this->size = _other.size;
		delete[] this->ptr;
		this->ptr = new T[this->size];

		for (size_t i = 0; i < this->size; i++)
		{
			this->ptr[i] = _other.ptr[i];
		}
	}

	MyVector& operator = (const MyVector&& _other)
	{
		this->ptr = _other.ptr;
		this->size = _other.size;
		delete[] _other.ptr;
		_other.ptr = nullptr;
	}

	bool operator == (const MyVector& _other)
	{
		if (_other.size != this->size)
		{
			return false;
		}

		for (size_t i = 0; i < this->size; i++)
		{
			if (this->ptr[i] != _other.ptr[i])
			{
				return false;
			}
		}
		return true;
	}

	bool operator != (const MyVector& _other)
	{
		if (_other.size == this->size)
		{
			return false;
		}

		for (size_t i = 0; i < this->size; i++)
		{
			if (this->ptr[i] == _other.ptr[i])
			{
				return false;
			}
		}
		return true;
	}

	void Clear()
	{
		delete[] this->ptr;
		this->ptr = nullptr;
		this->size = 0;
	}

private:
	T* ptr;
	size_t size;
};




int main()
{

	MyVector<int> nums;

	nums.push_back(5);

	std::cout << nums[0] << '\n';

	nums[0] = 3;


	_CrtDumpMemoryLeaks();
	return 0;
}