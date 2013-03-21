
#ifndef EXAMPLE_FUNCTIONS_IS_ODD
#define EXAMPLE_FUNCTIONS_IS_ODD
bool is_odd(int n) {
	return n & 1;
}
#endif

#ifndef EXAMPLE_FUNCTIONS_IS_EVEN
#define EXAMPLE_FUNCTIONS_IS_EVEN
bool is_even(int n) {
	return !is_odd(n);
}
#endif

#ifndef EXAMPLE_FUNCTIONS_SQUARE
#define EXAMPLE_FUNCTIONS_SQUARE
int square(int x) {
	return x*x;
}
#endif
#ifndef EXAMPLE_FUNCTIONS_ADD
#define EXAMPLE_FUNCTIONS_ADD
int add(int a, int b) {
	return a + b;
}
#endif
