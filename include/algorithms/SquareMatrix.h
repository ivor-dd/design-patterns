/*
This class aims to overload
the * operator and use Strassen's method
to calculate the product of two matrices
*/

#pragma once

#include <iostream>
#include <vector>

template<class T>
class SquareMatrix
{
private:
	typedef typename std::vector<std::vector<T>> matrix;
	matrix value;
	int size;
public:
	SquareMatrix(int);
	template<class ...Args>
	SquareMatrix(Args &...);

	void addRow(std::vector<T> &);
	template<class ...Args>
	void addRow(std::vector<T> &, Args &...);

	SquareMatrix action(SquareMatrix &, T (*)(T, T)) const;
	SquareMatrix operator+(SquareMatrix &);
	SquareMatrix operator-(SquareMatrix &);

	//void setBlock(SquareMatrix &, const int, const int);
	SquareMatrix makeSubMatrix(const int, const int) const;
	SquareMatrix combineSubMatricies(SquareMatrix &, SquareMatrix &, SquareMatrix &, SquareMatrix &) const;
	SquareMatrix operator*(SquareMatrix &);
	
	void print() const;
};

template<class T>
SquareMatrix<T>::SquareMatrix(const int n) {
	size = n;
	matrix value(n, std::vector<T>(n));
}

template<class T>
template<class ...Args>
SquareMatrix<T>::SquareMatrix(Args&... args) {
	size = sizeof...(Args);
	matrix value(size, std::vector<T>(size));
	this->addRow(args...);
}

template<class T>
void SquareMatrix<T>::addRow(std::vector<T> & row) {
	value.push_back(row);
}

template<class T>
template<class ...Args>
void SquareMatrix<T>::addRow(std::vector<T> & row, Args &... args) {
	addRow(row);
	addRow(args...);
}

template<class T>
SquareMatrix<T> SquareMatrix<T>::action(SquareMatrix & B, T (*func)(T, T)) const {
	SquareMatrix<T> C(this->size);

	std::vector<T> temp;
	for(auto i = 0; i != this->size; ++i) {
		for(auto j = 0; j != this->size; ++j) {
			temp.push_back(func((this->value)[i][j], (B.value)[i][j]));
		}
		C.addRow(temp);
		temp.clear();
	}

	return C;
}

template<class T>
SquareMatrix<T> SquareMatrix<T>::operator+(SquareMatrix & B) {
	return action(B, [](T a, T b) -> T { return a + b; });
}

template<class T>
SquareMatrix<T> SquareMatrix<T>::operator-(SquareMatrix & B) {
	return action(B, [](T a, T b) -> T { return a - b; });
}

/*
Incremental approach
Quadratic in n: O(n^2)
*/
template<class T>
SquareMatrix<T> SquareMatrix<T>::makeSubMatrix(const int r, const int c) const {
	int n = this->size;
	SquareMatrix<T> output(n/2);

	std::vector<T> temp;
	for(int i = (r-1)*n/(2); i != r*n/2; ++i) {
		for (int j = (c-1)*n/(2); j != c*n/2; ++j) {
			temp.push_back((this->value)[i][j]);
		}
		output.addRow(temp);
		temp.clear();
	}
	
	return output;
}

/*
Incremental approach
Quadratic in n: O(n^2)
*/
template<class T>
SquareMatrix<T> SquareMatrix<T>::combineSubMatricies(SquareMatrix & C11, SquareMatrix & C12, SquareMatrix & C21, SquareMatrix & C22) const {	
	int n = 2*C11.size;
	SquareMatrix<T> C(n);

	for(int i = 0; i < n/2; ++i) {
		C11.value[i].insert(C11.value[i].end(), C12.value[i].begin(), C12.value[i].end());
		C.addRow(C11.value[i]);
	}

	for(int i = 0; i < n/2; ++i) {
		C21.value[i].insert(C21.value[i].end(), C22.value[i].begin(), C22.value[i].end());
		C.addRow(C21.value[i]);
	}

	return C;
}

/*
Divide and conquer approach
n: O(n^log7)
*/
template<class T>
SquareMatrix<T> SquareMatrix<T>::operator*(SquareMatrix & B) {
	int n = this->size;

	if(n==1) {
		std::vector<T> bottom_out = { (this->value)[0][0] * (B.value)[0][0] };
		SquareMatrix<T> C(bottom_out);
		return(C);
	} else {
		SquareMatrix<T> A11 = this->makeSubMatrix(1, 1);
		SquareMatrix<T> A12 = this->makeSubMatrix(1, 2);
		SquareMatrix<T> A21 = this->makeSubMatrix(2, 1);
		SquareMatrix<T> A22 = this->makeSubMatrix(2, 2);
		SquareMatrix<T> B11 = B.makeSubMatrix(1, 1);
		SquareMatrix<T> B12 = B.makeSubMatrix(1, 2);
		SquareMatrix<T> B21 = B.makeSubMatrix(2, 1);
		SquareMatrix<T> B22 = B.makeSubMatrix(2, 2);
		SquareMatrix<T> S1 = B12 - B22;
		SquareMatrix<T> S2 = A11 + A12;
		SquareMatrix<T> S3 = A21 + A22;
		SquareMatrix<T> S4 = B21 - B11;
		SquareMatrix<T> S5 = A11 + A22;
		SquareMatrix<T> S6 = B11 + B22;
		SquareMatrix<T> S7 = A12 - A22;
		SquareMatrix<T> S8 = B21 + B22;
		SquareMatrix<T> S9 = A11 - A21;
		SquareMatrix<T> S10 = B11 + B12;
		SquareMatrix<T> P1 = A11 * S1;
		SquareMatrix<T> P2 = S2 * B22;
		SquareMatrix<T> P3 = S3 * B11;
		SquareMatrix<T> P4 = A22 * S4;
		SquareMatrix<T> P5 = S5 * S6;
		SquareMatrix<T> P6 = S7 * S8;
		SquareMatrix<T> P7 = S9 * S10;
		SquareMatrix<T> C11 = P5 + P4 - P2 + P6;
		SquareMatrix<T> C12 = P1 + P2;
		SquareMatrix<T> C21 = P3 + P4;
		SquareMatrix<T> C22 = P5 + P1 - P3 - P7;
		SquareMatrix<T> C = combineSubMatricies(C11, C12, C21, C22);
		return(C);
	}
}

/*
Display
*/
template<class T>
void SquareMatrix<T>::print() const {
	for(auto i = 0; i != size; ++i) {
		for(auto j = 0; j != size; ++j) {
			std::cout << value[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}