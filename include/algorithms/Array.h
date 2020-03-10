/*
This class aims to solve the sorting problem.
Input: A sequence of n numbers a_1, a_2, ... ,a_n.
Output: A permutation (reordering) of n numbers a_1', a_2', ... ,a_n' such that a_1' < a_2' < ...  < a_n'.
The list is passed by reference and altered in place.

This class aims to solve the maximum subarray problem.
Input: A sequence of n numbers a_1, a_2, ... ,a_n.
Output: A subsequence of numbers a_i, a_(i+1), ..., a_j where (i, j) 
are chosen so the sum from k=i to j gives a maximum.
The list is passed by reference and unaltered.
*/

#pragma once

#include <iostream>
#include <vector>
#include <limits> // sentinals
#include <cmath> // floor

template<class T> 
struct value { 
private:
	typedef typename std::vector<T>::iterator iter;
public:
	iter max_left;
	iter max_right;
	T sum;
};

template<class T>
class Array
{
private:
	typedef typename std::vector<T>::iterator iter;
public:
	// Insert-Sort
	static void insertSort(std::vector<T> &);

	// Merge-Sort
	static void merge(std::vector<T> &, iter, iter, iter);
	static void mergeRecursive(std::vector<T> &, iter, iter);
	static void mergeSort(std::vector<T> &);

	// Sub-Array
	static value<T> maximumCrossingSubArray(std::vector<T> &, iter, iter, iter);
	static value<T> maximumSubArray(std::vector<T> &, iter, iter);
	static std::vector<T> findMaximumSubArray(std::vector<T> &);

	static void print(std::vector<T> &);
};

/*
Incremental approach
Quadratic in n: O(n^2)
*/
template<class T>
void Array<T>::insertSort(std::vector<T> & vec) {
	T key;
	iter j;

	for (auto i = vec.begin() + 1; i != vec.end(); ++i) {
		key = *i;
		j = i - 1;
		while (j + 1 != vec.begin() && *j > key) {
			*(j + 1) = *j;
			--j;
		}
		*(j + 1) = key;
	}
}


// O(n)
template<class T>
void Array<T>::merge(std::vector<T> & vec, iter p, iter q, iter r) {
	std::vector<T> left(p, q);
	std::vector<T> right(q, r);

	T sentinal = std::numeric_limits<T>::max();

	left.push_back(sentinal);
	right.push_back(sentinal);

	iter i = left.begin();
	iter j = right.begin();

	for(auto k = p; k != r; ++k) {
		if (*i <= *j) {
			*k = *i;
			++i;
		} else {
			*k = *j;
			++j;
		}
	}
}

/*
Divide and Conquer approach
n: O(nlog(n))
*/
template<class T>
void Array<T>::mergeRecursive(std::vector<T> & vec, iter p, iter r) {
	if(p + 1 < r) {
		iter q = p + std::floor(std::distance(p, r)/2); // random access iterator
		mergeRecursive(vec, p, q); // Ends at q-1
		mergeRecursive(vec, q, r); // Ends at r-1 (But r is end of vector pointer)
		merge(vec, p, q, r);
	}
}

template<class T>
void Array<T>::mergeSort(std::vector<T> & vec) {
	mergeRecursive(vec, vec.begin(), vec.end());
}

/*
linear in n: O(n)
*/
template<class T>
value<T> Array<T>::maximumCrossingSubArray(std::vector<T> & vec, iter low, iter mid, iter high) {
	iter max_left;
	iter max_right;

	T left_sum = std::numeric_limits<T>:: min();
	T right_sum = std::numeric_limits<T>:: min();

	T sum = 0;

	for (auto it = mid + 1; it-- != low;) {
		sum = sum + *it;
		if(sum > left_sum) {
			left_sum = sum;
			max_left = it;
		}
	}

	sum = 0;
	
	for (auto it = mid + 1; it <= high; ++it) {
		sum = sum + *it;
		if(sum > right_sum) {
			right_sum = sum;
			max_right = it;
		}
	}

	return value<T> { max_left, max_right + 1, right_sum + left_sum };
}

/*
Divide and Conquer approach
n: O(nlog(n))
*/
template<class T>
value<T> Array<T>::maximumSubArray(std::vector<T> & vec, iter low, iter high) {
	if(high == low) {
		return value<T> { low, high, *low };
	} else {
		iter mid = low + std::floor(std::distance(low, high)/2);
		value<T> left = maximumSubArray(vec, low, mid);
		value<T> right = maximumSubArray(vec, mid + 1, high);
		value<T> cross = maximumCrossingSubArray(vec, low, mid, high);
		if(left.sum >= right.sum && left.sum >= cross.sum) {
			return left;
		} else if(right.sum >= left.sum && right.sum >= cross.sum) {
			return right;
		} else {
			return cross;
		}
	}
}

template<class T>
std::vector<T> Array<T>::findMaximumSubArray(std::vector<T> & vec) {
	value<int> result = maximumSubArray(vec, vec.begin(), vec.end() - 1);
	std::vector<int> sub_array(result.max_left, result.max_right);
	return sub_array;
}

/*
Display
*/
template<class T>
void Array<T>::print(std::vector<T> & vec) {
	for (auto it = vec.begin(); it != vec.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
