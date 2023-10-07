// all possible while loop combinations

// 1. while loop with no condition
// 2. while loop with condition
// 3. while loop with condition and body
// 4. while loop with condition, body and increment
// 5. while loop with condition, body, increment and decrement
// 6. while loop with condition, body, increment, decrement and label
// 7. while loop with condition, body, increment, decrement, label and goto
// 8. while loop with condition, body, increment, decrement, label, goto and break
// 9. while loop with condition, body, increment, decrement, label, goto, break and continue
// 10. while loop with condition, body, increment, decrement, label, goto, break, continue and return
// 11. while loop with condition, body, increment, decrement, label, goto, break, continue, return and nested while loop
// 12. while loop with condition, body, increment, decrement, label, goto, break, continue, return, nested while loop and nested if statement
// 13. while loop with condition, body, increment, decrement, label, goto, break, continue, return, nested while loop, nested if statement and nested for loop
// 14. while loop with condition, body, increment, decrement, label, goto, break, continue, return, nested while loop, nested if statement, nested for loop and nested switch statement
// 15. while loop with condition, body, increment, decrement, label, goto, break, continue, return, nested while loop, nested if statement, nested for loop, nested switch statement and nested do while loop
// 16. while loop with condition, body, increment, decrement, label, goto, break, continue, return, nested while loop, nested if statement, nested for loop, nested switch statement, nested do while loop and nested switch statement
// 17. while loop with condition, body, increment, decrement, label, goto, break, continue, return, nested while loop, nested if statement, nested for loop, nested switch statement, nested do while loop, nested switch statement and nested do while loop
// 18. while loop with condition, body, increment, decrement, label, goto, break, continue, return, nested while loop, nested if statement, nested for loop, nested switch statement, nested do while loop, nested switch statement, nested do while loop and nested for loop
// 19. while loop with condition, body, increment, decrement, label, goto, break, continue, return, nested while loop, nested if statement, nested for loop, nested switch statement, nested do while loop, nested switch statement, nested do while loop, nested for loop and nested if statement
// 20. while loop with condition, body, increment, decrement, label, goto, break, continue, return, nested while loop, nested if statement, nested for loop, nested switch statement, nested do while loop, nested switch statement, nested do while loop, nested for loop, nested if statement and nested while loop


// int main (void)
// {
// 	while (); // 1
// 	while (1); // 2
// 	while (1) { } // 3
// 	while (1) { } ++i; // 4
// 	while (1) { } ++i; --i; // 5
// 	while (1) { } ++i; --i; label: // 6
// 	while (1) { } ++i; --i; label: goto label; // 7
// 	while (1) { } ++i; --i; label: goto label; break; // 8
// 	while (1) { } ++i; --i; label: goto label; break; continue; // 9
// 	while (1) { } ++i; --i; label: goto label; break; continue; return 0; // 10
// 	while (1) { while (1) { } } // 11
// 	while (1) { if (1) { } } // 12
// 	while (1) { for (int i = 0; i < 10; ++i) { } } // 13
// 	while (1) { switch (1) { } } // 14
// 	while (1) { do { } while (1); } // 15
// 	switch (1) { case 1: while (1) { } } // 16
// 	switch (1) { case 1: do { } while (1); } // 17
// 	for (int i = 0; i < 10; ++i) { while (1) { } } // 18
// 	for (int i = 0; i < 10; ++i) { if (1) { } } // 19
// 	while (1) { while (1) { } } // 20

// 	return 0;
// }

#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>


int main (void)
{
	int c = 0;
	while (true) // 1
	{
		printf("%c", c);
		sleep(2);
		++c;

	}
	return 0;
}