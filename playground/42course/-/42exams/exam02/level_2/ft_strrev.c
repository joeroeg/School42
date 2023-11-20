char *ft_strrev(char *str) {
    // Find the length of the string
    int length = 0;
    while (str[length] != '\0')
        length++;

    // Reverse the string in-place
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }

    return str;
}
