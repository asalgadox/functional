#include <iostream>
#include <vector>


namespace functional {

#ifndef FUNCTIONAL_MAP
#define FUNCTIONAL_MAP
template <class InputType, class OutputType>
std::vector<OutputType> map(OutputType (*function)(InputType), 
							std::vector<InputType> input);
#endif 

#ifndef FUNCTIONAL_FILTER
#define FUNCTIONAL_FILTER
template <class InputType>
std::vector<InputType> filter(bool (*function)(InputType), 
					std::vector<InputType> input);
#endif 

#ifndef FUNCTIONAL_REDUCE
#define FUNCTIONAL_REDUCE
template <class InputType>
InputType reduce(InputType (*function)(InputType, InputType), 
		std::vector<InputType> input, InputType initial);
#endif

#ifndef FUNCTIONAL_PRINT_VECTOR
#define FUNCTIONAL_PRINT_VECTOR
template <class InputType>
void PrintVector(std::vector<InputType> input);
#endif

#ifndef FUNCTIONAL_RANGE
#define FUNCTIONAL_RANGE
std::vector<int> range(int min, int max, int step);
#endif

}