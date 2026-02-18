#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_STACK 100
#define MAX_TAG_LEN 20

char stack[MAX_STACK][MAX_TAG_LEN];
int top = -1;

void push(char* tag) {
    if (top < MAX_STACK - 1) {
        strcpy(stack[++top], tag);
    }
}

bool pop(char* outTag) {
    if (top >= 0) {
        strcpy(outTag, stack[top--]);
        return true;
    }
    return false;
}

bool is_balanced_html(char* html) {
    int i = 0;
    while (html[i] != '\0') {
        if (html[i] == '<') {
            i++;
            bool isClosing = (html[i] == '/');
            if (isClosing) i++;

            char tagName[MAX_TAG_LEN];
            int j = 0;
            while (html[i] != '>' && html[i] != ' ' && html[i] != '\0') {
                if (j < MAX_TAG_LEN - 1) tagName[j++] = html[i];
                i++;
            }
            tagName[j] = '\0';

            while (html[i] != '>' && html[i] != '\0') i++;

            if (isClosing) {
                char openTag[MAX_TAG_LEN];
                if (!pop(openTag) || strcmp(openTag, tagName) != 0) {
                    return false;                 }
            } else {
                if (strcmp(tagName, "br") != 0 && strcmp(tagName, "img") != 0) {
                    push(tagName);
                }
            }
        }
        if (html[i] != '\0') i++;
    }
    return top == -1;}

int main() {
    char* code1 = "<html><body><h1>Title</h1><p>Text</p></body></html>";
    char* code2 = "<div><span>Mismatch</div></span>";

    printf("HTML 1 valid: %s\n", is_balanced_html(code1) ? "Yes" : "No");
    printf("HTML 2 valid: %s\n", is_balanced_html(code2) ? "Yes" : "No");

    return 0;
}
