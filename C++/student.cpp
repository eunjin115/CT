#include <iostream>
#include <sstream>
#include <algorithm>

template <typename T>
class dynamic_array
{
	T* data;
	size_t n;
	
	public:
		dynamic_array(int n)
		{
			this->n = n;
			data = new T[n];
		}
		dynamic_array(const dynamic_array<T>& other)
		{
			n = other.n;
			data = new T[n];

			for (int i = 0; i < n; i++)
				data[i] = other[i];
		}
		T& operator[](int index)
		{
			return data[index];
		}
		const T &operator[](int index)const
		{
			return data[index];
		}

		T& at(int index)
		{
			if (index < n)
				return data[index];
			throw "Index out of range";
		}
		
		size_t size() const
		{
			return n;
		}

		~dynamic_array()
		{
			delete[] data; //메모리 해제 -> 메모리 릭 방지
		}

		T* begin() { return data; }
		const T *begin()const { return data; }
		T* end() { return data + n; }
		const T *end()const { return data + n; }
		//두 배열을 하나로 합치는 연산 수행하는 연산자 정의
		friend dynamic_array<T> operator+(const dynamic_array<T> &arr1, dynamic_array<T> &arr2)
		{
			dynamic_array<T> result(arr1.size() + arr2.size());
			std::copy(arr1.begin(), arr1.end(), result.begin());
			std::copy(arr2.begin(), arr2.end(), result.begin() + arr1.size()); 	//result 시작부터 갖다 붙인 arr1 사이즈까지 -> arr1 붙인 뒤의 위치

			return result;
		}

	std::string 
};