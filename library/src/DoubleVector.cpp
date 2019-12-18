
#include <iostream>
#include <algorithm>
#include "DoubleVector.hpp"

/*
double* cie::DoubleVector::array1()
{
	return array1_;
}
*/

cie::DoubleVector::DoubleVector() : 
	array1_(new double[0]()), size_(0)
{
	array1_ = nullptr;
}


cie::DoubleVector::DoubleVector(int size):
	array1_(new double[size]()), size_(size)  //array1_(new double[size]())  initalising the array
{
	//for (int i = 0; i < size; ++i)
	//{
		//array1_[i] = 0.0;
	//}

}

cie::DoubleVector::DoubleVector(const DoubleVector& other):
	array1_(new double[other.size_]),size_(other.size_)
{

	std::copy(other.array1_, other.array1_ + size_, array1_);

}

cie::DoubleVector& cie::DoubleVector::operator= (const DoubleVector& other)
{
	
	double* array2 = new double[other.size_];
	std::copy(other.array1_, other.array1_ + other.size_, array2);
	delete[] array1_;
	size_ = other.size_;
	array1_ = array2;
	return *this;
	/*std::swap(array1_, other.array1_); hierbei muss const weggelassen sein
	std::swap(size_, other.size_);*/

	return *this;

}

double& cie::DoubleVector::operator[](int index)
{
	
	return array1_[index];
}

cie::DoubleVector::~DoubleVector()
{
	std::cout << "Destructor called " << std::endl;
	delete[] array1_;
}

double& cie::DoubleVector::at(int index)
{
	return array1_[index];
}

int cie::DoubleVector::size()
{
	return size_;
}

double* cie::DoubleVector::array1()
{
	return array1_;
}

void cie::DoubleVector::resize(int newSize) //Resizes the vector while preservig old values and initializing new values with zero
{
	double* array2 = new double[newSize]();
	//for (int i = 0; i < newSize; ++i)
	//{
		//array2[i] = 0.0;
	//}

	if (newSize < size_)
	{
		for (int i = 0; i < newSize; i++)
		{
			array2[i] = array1()[i];
		}
		delete[] array1_;
		array1_ = array2;
		size_ = newSize;
	
	}
	
	else if (newSize > size_)
	{
		for (int i = 0; i < size_; i++)
		{
			array2[i] = array1()[i];
		}
		delete[] array1();
		array1_ = array2;
		size_ = newSize;
		
	}
	
}

void cie::DoubleVector::push_back(double value)
{
	/*double* array2 = new double[size() + 1];
	for (int i = 0; i < size_; i++)
	{
		array2[i] = array1()[i];
	}

	array2[size()] = value;
	delete[] array1();
	array1_ = array2;
	size_++;*/
	resize(size_ + 1);
	array1_[size_-1]= value;
}

void cie::print(DoubleVector& v)
{
	std::cout << "Vector v is [";
	for (int i = 0; i < v.size()-1; i++)
	{
		std::cout << v.at(i) << " ";
	}
	int a = v.size();
	//if(a!=0)
	//std::cout << v.at(a) ;

	std::cout <<v.at(v.size())<< "]" << std::endl;
}

void cie::userInput(DoubleVector& v)
{
	std::cout << "The number of entities of an array is:" << v.size() << std::endl;
	for (int i = 0; i < v.size(); ++i)
	{	
		std::cout << "input the entry of array" << std::endl;
		std::cin >> v.at(i);
	}

}

double cie::dotProduct(DoubleVector& v1, DoubleVector& v2)
{

	if (v1.size() == v2.size())
	{

		double result = 0.0;

		for (int i = 0; i < v1.size(); ++i)
		{
			result += (v1.at(i) * v2.at(i));
		}


		return result;
	}
	else
		std::cout << "number of elements doesn't match!" << std::endl;
}
	

