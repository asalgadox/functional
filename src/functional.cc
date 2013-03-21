////////////////////////////////////////////////////////////////////////////
//
// 	Filename: functional.cc
// 	Description: a C++ implementation of functional programming primitives
// 		  		 map, reduce, and filter using std::vector and function
//				 pointers
//	Author: Anthony Salgado
//	Date: March 19, 2012
//				
////////////////////////////////////////////////////////////////////////////

#include <cassert>				// for assert
#include "functional.h"			// for map, reduce, filter, print, range
#include "example_functions.h"	// for add, square, is_even, is_odd, examples



template <class InputType, class OutputType>
std::vector<OutputType> functional::map(OutputType (*function)(InputType), 
							std::vector<InputType> input) {

	std::vector<OutputType> output;
	typename std::vector<InputType>::const_iterator it;
	for (it=input.begin(); it != input.end(); ++it) {
		output.push_back(function(*it));
	}

	return output;
}


template <class InputType>
std::vector<InputType> functional::filter(bool (*function)(InputType), 
					std::vector<InputType> input) {
	std::vector<InputType> output;
	typename std::vector<InputType>::const_iterator it;
	for (it=input.begin(); it != input.end(); ++it) {
		if (function(*it)) {
			output.push_back(*it);
		}
	}
	return output;
}

template <class InputType>
InputType functional::reduce(InputType (*function)(InputType, InputType), 
		std::vector<InputType> input, InputType initial) {
	typename std::vector<InputType>::const_iterator it;
	for (it=input.begin(); it != input.end(); ++it) {
		initial = function(initial, *it);
	}
	return initial;
}

template <class InputType>
void functional::PrintVector(std::vector<InputType> input) {
	std::cout << "[";
	for (size_t i = 0; i < input.size(); ++i) {
		std::cout << input[i];
		if (i != input.size()-1) {
			std::cout << ", ";
		}
	}
	std::cout << "]" << std::endl;
}

std::vector<int> functional::range(int min, int max, int step) {
	
	assert(step > 0);
	std::vector<int> output;
	while (min < max) {
		output.push_back(min);
		min += step;
	}
	return output;
}


int main(int argc, char** argv) {
	using namespace functional;
	std::vector<int> vector = range(0, 10, 1);
	PrintVector(vector);
	PrintVector(map(square, vector));
	PrintVector(filter(is_odd, vector));
	std::cout << reduce(add, map(square, vector), 0) << std::endl;
	return 0;
}	

