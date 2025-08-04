#include<stdio.h>

int str_len(char* str) {
    int i;
    for(i = 0; str[i]; i++);
    return i;
}

int str_cmp(char* str, char* str1) {
    int i = 0;
    while (str[i] && str1[i]) {
        if (str[i] != str1[i])
            return str[i] - str1[i];
        i++;
    }
    return str[i] - str1[i];
}

int main() {
    int i, j, pos, substr_pos;
    char str[100], str1[100], substr[100];

    printf("Enter 2 strings:\n");
    scanf("%s", str);
    scanf("%s", str1);

    printf("Length of str: %d\n", str_len(str));

    char str2[str_len(str)+str_len(str1)+1];
    for(i = 0; str[i]; i++) str2[i] = str[i];
    for(i = 0; str1[i]; i++) str2[str_len(str) + i] = str1[i];
    str2[str_len(str) + str_len(str1)] = '\0';

    printf("Concatenated: %s\n", str2);
    printf("Comparision of strings: %d\n", str_cmp(str, str1));

    printf("Enter substring to insert: ");
    scanf("%s", substr);
    printf("Enter position to insert substring at: ");
    scanf("%d", &pos);

    char str3[str_len(str)+str_len(substr)+1];

    for(i = 0; i < pos; i++) str3[i] = str[i];
    for(i = 0; substr[i]; i++) str3[pos+i] = substr[i];
    for(i = pos; str[i]; i++) str3[str_len(substr)+i] = str[i];
    str3[str_len(str)+str_len(substr)] = '\0';

    printf("After substring insertion: %s\n", str3);

    printf("Enter substring to delete: ");
    scanf("%s", substr);

    substr_pos = -1;

    for(i = 0; str[i]; i++) {
        int matching = 1;

        for(j = 0; substr[j]; j++)
            if(substr[j] != str[i+j]) matching = 0;

        if(matching == 1) {
            substr_pos = i;
            break;
        }
    }

    if(substr_pos == -1) {
        printf("Substring not found in string\n");
        return 1;
    }

    printf("Substring found at index %d!\n", substr_pos);

    for(i = 0; substr[i]; i++)
        for(j = substr_pos; str[j]; j++)
            str[j] = str[j+1];

    printf("After substring removal: %s\n", str);

    return 0;
}
