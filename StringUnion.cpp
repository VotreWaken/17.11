#include <iostream>

class String
{
public:
	// Constructor by Parametres
	explicit String(const char* data)
	{
		if (!data)
		{
			throw std::invalid_argument("Incorrect string");
		}
		// Fill Zeros to representation
		memset(&str_representation, 0, sizeof(str_representation));
		// Create Buffer
		char* buffer;
		const size_t data_len = strlen(data);
		// Condition for creating
		if (data_len + 1 <= small_string::STRING_SIZE)
		{
			// Small String Representation
			buffer = str_representation.small.data;
			str_representation.small.data[small_string::MAGIC_NUM_INDEX] = small_string::MAGIC_NUM;
		}
		else
		{
			// Big String Representation
			str_representation.big.capacity_ = data_len + data_len / 2;
			buffer = str_representation.big.data_ = new char[str_representation.big.capacity_];
		}
		// Assign values to class fields
		size_ = data_len;
		std::copy(data, data + data_len + 1, buffer);
	}
	// Destructor 
	~String()
	{
		// If a large string means allocated dynamically and you need to delete the memory
		if (str_representation.small.data[small_string::MAGIC_NUM_INDEX] != small_string::MAGIC_NUM)
		{
			delete[] str_representation.big.data_;
		}
	}
	// Struct of Small String
	struct small_string
	{
		static constexpr size_t BUFF_SIZE = 18u;
		static constexpr size_t STRING_SIZE = 17u;
		static constexpr size_t MAGIC_NUM_INDEX = 17u;
		static constexpr size_t MAGIC_NUM = 0x01;
		char data[18u];
	};
	// Struct of Big String
	struct big_string
	{
		size_t capacity_;
		char* data_;
	};
	// Union to Representation String
	union representation
	{
		small_string small;
		big_string big;
	};
	// Get Size Method
	size_t GetSize()
	{
		return size_;
	}
private:
	// String Fields
	size_t size_ = 0u;
	representation str_representation;
};

int main()
{
	String small("Hello World");
	std::cout << small.GetSize() << '\n';

	// Second String allocated dynamically
	String big("Hello World, Hello World, Hello World");
	std::cout << big.GetSize() << '\n';
}
