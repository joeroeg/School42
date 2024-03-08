
char *ft_strncpy(char *dst, const char *src, unsigned int n) {
    if (n == 0)
        return dst;
    char *dst_orig = dst;
    while (n > 1 && *src) {
        *dst++ = *src++;
        n--;
    }
    *dst = '\0'; // Null terminate the destination
    return dst_orig;
}

void ft_strncpy(char *dest, const char *src, size_t n) {
    size_t i;
    for (i = 0; i < n; i++) {
        dest[i] = src[i];
    }
    for ( ; i < n; i++) {
        dest[i] = '\0';
    }
}
