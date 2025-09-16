// We play with pointer to pointer through command line arguments
#include <stdio.h>

// As you can see, argv is a pointer to pointer
int main(int argc, char **argv)
{
	// Here, argv is a way to represent an array of strings
	// Or more accurately, an array of character arrays (C lacks string data type)
	// A particular character array can be accessed using square brackets
	// Yes, the first argument is the name of the script itself
	printf("argv[0] -> %s\n", argv[0]);

	// Each character of the character array can also be accessed
	printf("argv[0][2] -> %c\n", argv[0][2]);

	// I get it, the square bracket notation is not exciting enough
	// If we try to dereference argv, C gives us the address of the character array, a.k.a string
	printf("*argv -> %p\n", *argv);

	// The trick is to use %s format specifier (C recognises strings after all!)
	printf("*argv -> %s\n", *argv);

	// To get the next string, we can use pointer arithmetic
	// Remember that argv holds the base address of an array full of strings (just excuse the term for the moment)
	// If we do argv+1, it should point to the next string in the array
	// We do just that, then use the dereference operator to get the value at the address
	printf("*(argv+1) -> %s\n", *(argv+1));

	// If we go one step down with **argv, we get to a single character
	printf("**argv -> %c\n", **argv);

	// We can use the following to jump through characters
	// As before, *argv will give us the base address of the character array (a string)
	// The base address of an array will point to the zeroeth element of the array
	// If we do *argv+1, it will give us the address of second element in the array
	// We then dereference it again so that we can retrieve the value stored at the address
	printf("*(*argv+1) -> %c\n", *(*argv+1));
	
	return 0;
}
