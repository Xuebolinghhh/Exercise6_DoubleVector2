#include <algorithm>

namespace cie
{
	class DoubleVector
	{
	public:
		DoubleVector();

		DoubleVector(int size);

		DoubleVector(const DoubleVector& other);
			
		DoubleVector& operator= (const DoubleVector& other);

		~DoubleVector();
		
		double& operator[] (int index);

		double& at(int index);

		int size();

		void resize(int newSize);

		void push_back(double value);

		double* array1();

	private:
		double *array1_;
		int size_;
	};

	void print(DoubleVector& v);

	void userInput(DoubleVector& v);

	double dotProduct(DoubleVector& v1, DoubleVector& v2);
}