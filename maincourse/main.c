#include "libft.h"

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	ft_putchar_fd(char c, int fd);
void	*ft_memmove(void *dst, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *nptr);
void	*ft_calloc( size_t num, size_t size );
char	*ft_strdup( const char *str1 );
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);


/* MANDATORY */

// ft_isalpha		int main(void)	{	for (int i = 0; i < 128; i++) { printf("%c - %d\n", i, ft_isalpha(i)); } return 0; }
// ft_isdigit		int main(void)	{	for (int i = 0; i < 128; i++) { printf("%c - %d\n", i, ft_isdigit(i)); } return 0; }
// ft_isalnum		int main(void)	{	for (int i = 0; i < 128; i++) { printf("%c - %d\n", i, ft_isalnum(i)); } return 0; }
// ft_isascii		int main(void)	{	for (int i = -256; i <= 256; i++) { printf("%d - %d\n", i, ft_isascii(i)); } return 0; }
// ft_isprint		int main(void)	{	for (int i = 0; i < 128; i++) { printf("%d - %d\n", i, ft_isprint(i)); } return 0; }
// ft_strlen		int	main(void)	{	char *str; int result; str = "Hello"; result = ft_strlen(str); printf ("%d", result); return (0); }
// ft_memset		int	main(void)	{	char str1[] = "abcde"; char str2[] = "abcde"; ft_memset (str1, '-', 3); puts (str1); memset (str2, '-', 3); puts (str2); return (0); }
// ft_bzero			int main(void)	{	char str[] = "Hello World!"; printf("Before bzero: %s\n", str); ft_bzero(str, 5); printf("After bzero: %s\n", str); return 0;}
// ft_memcpy		int main(void)	{	char src[] = "Hello World!";	char dest[] = "1234567890";	printf("Before memcpy dest = %s\n", dest);	ft_memcpy(dest, src, 5);	printf("After memcpy dest = %s\n", dest);	return 0;}
// ft_memmove		int main(void)	{	char memmove_src[] = "abcdef";	char memcpy_src[] = "abcdef";	ft_memmove(&memmove_src[2], &memmove_src[0], 4);  printf("memmove Output: %s\n", memmove_src);  ft_memcpy(&memcpy_src[2], &memcpy_src[0], 4);  printf("memcpy Output: %s\n", memcpy_src);  return 0;}
// ft_strclpy		int main(void)	{	char src[] = "Hello";	char dest[] = "World";	ft_strlcpy(dest, src, 3);	printf("%s\n", dest);	return (0); }
// ft_strlcat		int main()		{	char src[50] = "World!";	char dest[50] = "Hello ";	ft_strlcat(dest, src, 12);	printf("Final destination string : %s\n", dest);	return (0); }
// ft_toupper		int main(void)	{	for (int i = 0; i < 128; i++) { printf("%d - %c\n", i, ft_toupper(i)); } return 0; }
// ft_tolower		int main(void)	{	for (int i = 0; i < 128; i++) { printf("%d - %c\n", i, ft_tolower(i)); } return 0; }
// ft_strchr		int main(void)	{	char string[] = "Hello World";	char ch = 'W';	char *ptr = ft_strchr(string, ch);	printf("before: %s \n", string);	printf("after: %s\n", ptr);	return 0;}
// ft_strrchr		int main(void)	{	char string[] = "Hello World";    char ch = 'o'; char *result;    result = ft_strrchr(string, ch);    printf("%s\n", result);    return 0;}
// ft_strncmp		int main(void)	{	char str1[] = "abcde";	char str2[] = "abcdE";	printf("ft_strncmp: %d\n", ft_strncmp(str1, str2, 5));	return 0;}
// ft_memchr		int main(void)	{	int arr[] = {1, 2, 3, 4, 5};    char str[] = "Hello World!";    printf("%s\n", ft_memchr(str, 'o', sizeof(str)));    printf("%d\n", *(int *)ft_memchr(arr, 4, sizeof(arr)));    return 0;}
// ft_memcmp		int main(void)	{	char str1[] = "abcdef";     char str2[] = "abcdeF";       int result;     result = ft_memcmp(str1, str2, 6);    printf("result : %d\n", result);    return 0; }
// ft_strnstr		int main(void)	{	const char s[] = "FUCK YOU LOVE strnstr!!!";     const char find[] = "L";     size_t slen = 11;       char* result = ft_strnstr(s, find, slen);     printf("%s\n", result);    return 0; }
// ft_atoi			int main(int argc, char *argv[]){	if (argc == 2)	{		printf("%d\n", ft_atoi(argv[1]));	}	return 0;}
// ft_calloc		int main(void)  {   int* arr;    int num_elements = 10;    arr = (int*)ft_calloc(num_elements, sizeof(int));    if (arr == NULL) {        return 1;    }    for (int i = 0; i < num_elements; ++i) {        printf("%d\n", arr[i]);    }    free(arr);    return 0; }
// ft_strdup		int main(void)	{    char *str1 = "Hello World!";    char *str2;    str2 = ft_strdup(str1);    printf("str1: %s\n", str1);    printf("str2: %s\n", str2);        free(str2);    return 0;}
// ft_substr		int main(void)  {   char str[] = "Hello World!";    char *substr = ft_substr(str, 6, 6);    printf("%s\n", substr);    free(substr);    return (0);}
// ft_strjoin		int main(void)  {   char s1[] = "Hello";    char s2[] = "World!";    char *str;    str = ft_strjoin(s1, s2);    printf("%s\n", str);    free(str);	return (0);}
// ft_strtrim		int main(void) 	{	char str[] = "a-217)(*(^&%&^%$#13Hello Worlda-217)(*(^&%&^%$#13";	printf("%s\n", ft_strtrim(str, "a-217)(*(^&%&^%$#13"));}
// ft_split			int main(void){    char a[] = "hello world!";    int i;    char** result = ft_split(a, ' ');    for (i = 0; result[i]; i++) {        printf("%s\n", result[i]);    } for (i = 0; result[i]; i++) {       free(result[i]);    }    free(result);    return 0;}
// ft_itoa			int	main(void)	{	int num = -0;	char *stringNumber = ft_itoa(num);	printf("The integer %d is converted to string as %s\n", num, stringNumber );	free(stringNumber);	return 0;}
// ft_strmapi		char ft_toupper_map(unsigned int i, char c) {    (void)i;    return toupper((unsigned char)c);}int main() {    char const *s = "hello world";    char *upper = ft_strmapi(s, ft_toupper_map);    if (upper != NULL) {        printf("%s\n", upper);        free(upper);    }   return 0;}
// ft_striteri		void upper(unsigned int i, char *c) { if (c) {        *c = toupper((unsigned char)*c); }} int main() {    char str[] = "Hello";    ft_striteri(str, upper);    printf("%s\n", str); return 0;
// ft_putchar_fd	int main(int argc, char **argv){	int fd = open("myfile", O_WRONLY | O_CREAT);	ft_putchar_fd('c', fd);	close(fd);	return 0;}
// ft_putstr_fd		int	main(void)	{	char str[] = "Hello World!";	int fd = 1;	ft_putstr_fd(str, fd);	return (0);}
// ft_putendl_fd	int main(void	{   char *s = "Hello World!";    int fd = 1;    ft_putendl_fd(s, fd);    return 0; }
// ft_putnbr_fd		int main(void)	{	ft_putnbr_fd(-1567, 1);	return 0;}

/* BONUS */

// ft_lstnew
/*
int main() {
    int *content = malloc(sizeof(int));
    *content = 42;
    t_list *node = ft_lstnew(content);

    if (node != NULL) {
        printf("New node created with content: %d\n", *(int *)node->content);
        free(node->content); // Free the content if it was dynamically allocated
        free(node); // Free the node itself
    } else {
        printf("Failed to create new node.\n");
        free(content); // free content if node creation fails
    }

    return 0;
}
*/

// ft_lstsize
/*
int main() {
    t_list *list = NULL;
    for (int i = 1; i <= 5; i++) {
        int *value = malloc(sizeof(int));
        *value = i;
        ft_lstadd_back(&list, ft_lstnew(value));
    }
    int size = ft_lstsize(list);
    printf("%d\n", size);
    ft_lstclear(&list, free);
    return 0;
}
*/

// ft_lstlast
/*
int main() {
    t_list *list = NULL;

    // Assume `ft_lstnew` and `ft_lstadd_back` have been defined correctly.
    for (int i = 1; i <= 5; i++) {
        int *value = malloc(sizeof(int));
        *value = i;
        ft_lstadd_back(&list, ft_lstnew(value));
    }

    t_list *last = ft_lstlast(list);
    if (last != NULL) {
        printf("The last element is: %d\n", *(int*)last->content);
    } else {
        printf("The list is empty.\n");
    }

    // Assume `ft_lstclear` has been defined correctly.
    ft_lstclear(&list, free);
    return 0;
}
*/

// ft_lstadd_front
/*
void free_content(void *content)
{
    free(content);
}

void print_list(t_list *list)
{
    while (list)
    {
        printf("%d ", *(int *)list->content);
        list = list->next;
    }
    printf("\n");
}

int main(void)
{
    t_list *list = NULL;

    // Add nodes to the list in a non-sequential order
    int values[] = {10, 5, 15, 3, 8};
    for (int i = 0; i < 5; ++i) {
        int *value = malloc(sizeof(int));
        *value = values[i];
        ft_lstadd_front(&list, ft_lstnew(value));
        print_list(list); // Print after each insertion
    }

    // Free the list
    ft_lstclear(&list, free_content);

    return 0;
}
*/

// ft_lstadd_back
/*
void free_content(void *content)
{
    free(content);
}

void print_list(t_list *list)
{
    while (list)
    {
        printf("%d ", *(int *)list->content);
        list = list->next;
    }
    printf("\n");
}

int main(void)
{
    t_list *list = NULL;

    // Add nodes to the list in a non-sequential order
    int values[] = {10, 5, 15, 3, 8};
    for (int i = 0; i < 5; ++i) {
        int *value = malloc(sizeof(int));
        *value = values[i];
        ft_lstadd_back(&list, ft_lstnew(value));
        print_list(list); // Print after each insertion
    }

    // Free the list
    ft_lstclear(&list, free_content);

    return 0;
}
*/

// ft_lstdelone
/*
void free_content(void *content)
{
    free(content);
}

int main(void)
{
    t_list *node = NULL;
    int *value = malloc(sizeof(int));
    *value = 42; // Arbitrary number for testing
    node = ft_lstnew(value);

    if (node == NULL) {
        free(value); // Ensure no leak if list creation fails
        return 1;
    }

    ft_lstdelone(node, free_content);

    // At this point, node has been freed. We cannot access it anymore.
    // Use a memory checking tool to ensure it was properly freed.

    // For manual memory leak checking:
    // gcc -g -o test main.c
    // valgrind --leak-check=full ./test

    return 0;
}
*/

// ft_lstclear
/*
void free_content(void *content)
{
    free(content);
}

int main(void)
{
    t_list *list = NULL;
    for (int i = 1; i <= 5; ++i) {
        int *value = malloc(sizeof(int));
        *value = i;
        ft_lstadd_back(&list, ft_lstnew(value));
    }

    ft_lstclear(&list, free_content);

    // Check that the list pointer is set to NULL
    if (list == NULL) {
        printf("List cleared, head is NULL.\n");
    } else {
        printf("Error: List head is not NULL.\n");
    }

    // To check for memory leaks, run the program with Valgrind
    // valgrind --leak-check=full ./a.out

    return 0;
}

*/

// ft_lstiter
/*
void print_content(void *content)
{
    printf("%d ", *(int *)content);
}

int main(void)
{
    t_list *list = NULL;
    int *value;

    for (int i = 1; i <= 5; ++i) {
        value = malloc(sizeof(int));
        *value = i;
        ft_lstadd_back(&list, ft_lstnew(value));
    }

    ft_lstiter(list, print_content);

    ft_lstclear(&list, free);

    return 0;
}
*/

// ft_lstmap
/*
void	*double_content(void *content)
{
    int *result = malloc(sizeof(int));
    if (result)
        *result = 2 * *(int *)content;
    return result;
}

void	del_content(void *content)
{
    free(content);
}

int		main(void)
{
    t_list *list = NULL;
    int *value;

    for (int i = 1; i <= 5; i++) {
        value = malloc(sizeof(int));
        *value = i;
        ft_lstadd_back(&list, ft_lstnew(value));
    }

    t_list *new_list = ft_lstmap(list, double_content, del_content);

    for (t_list *tmp = new_list; tmp; tmp = tmp->next) {
        printf("%d ", *(int *)tmp->content);
    }
    printf("\n");

    ft_lstclear(&list, del_content);
    ft_lstclear(&new_list, del_content);

    return 0;
}
*/
