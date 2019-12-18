#include <iostream>
#include "DoubleVector.hpp"



int main()
{
	using namespace cie;
	
	cie::DoubleVector v2(3);
	cie::DoubleVector v1(3);
	
	cie::userInput(v2);

	//cie::print(v1);
	cie::print(v2);

	//cie::DoubleVector v1(v2);
	
	
	v1.operator= (v2);
	cie::print(v1);
	/*
	double result = cie::dotProduct(v1, v2);
	std::cout << "The dotproduct of both vector is: " << result << std::endl;

	double value = 1.0;
	v1.push_back(value);
	v2.push_back(value);

	result = cie::dotProduct(v1, v2);
	std::cout << "The extended dotproduct of both vector is: " << result << std::endl;
	std::cout << "Now the size of the vector is: " << v1.size() << std::endl;
	*/
	system("pause");
	return 0;

}