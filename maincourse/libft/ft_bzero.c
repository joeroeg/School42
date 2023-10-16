#include <unistd.h>
#include <stdio.h>

void ft_bzero(void *s, size_t n)
{
  unsigned char *p = (unsigned char *)s;
  size_t i = 0;
  while (i < n)
  {
    p[i] = 0;
    i++;
  }
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};

    printf("Original array:\n");
    for (int i = 0; i < 5; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Using custom bzero to set bytes to zero
    ft_bzero(arr, 5 * sizeof(int));

    printf("Array after custom_bzero:\n");
    for (int i = 0; i < 5; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}