#include <stdio.h>

int main() {
    FILE *file = fopen("program2.c", "w");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    fprintf(file, "#include <stdio.h>");
	fprintf(file, "\n");
    fprintf(file, "int main() {");
	fprintf(file, "\n");
    fprintf(file, "    printf(\"Hello from program2!");");
	fprintf(file, "\n");
    fprintf(file, "    return 0;\\n");
	fprintf(file, "\n");
    fprintf(file, "}");

    fclose(file);
    return 0;
}
