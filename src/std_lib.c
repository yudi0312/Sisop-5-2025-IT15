#include "std_lib.h"


int div(int a, int b) {
    int quotient;
    int neg;
    int temp;
    int multiple;

    quotient = 0;
    neg = 0;

    if (b == 0) return 0;

    if (a < 0) {
        a = ~a + 1;
        neg = 1;
    }
    if (b < 0) {
        b = ~b + 1;
        neg = !neg;
    }

    while (a >= b) {
        temp = b;
        multiple = 1;
        while ((temp << 1) <= a) {
            temp = temp << 1;
            multiple = multiple << 1;
        }
        a = a - temp;
        quotient = quotient + multiple;
    }

    if (neg)
        return ~quotient + 1;
    else
        return quotient;
}

int mod(int a, int b) {
    int neg;
    if (b == 0) return 0;

    neg = 0;
    if (a < 0) {
        a = ~a + 1;
        neg = 1;
    }
    if (b < 0) {
        b = ~b + 1;
    }

    while (a >= b) {
        a = a - b;
    }

    if (neg)
        return ~a + 1;
    else
        return a;
}

bool strcmp(char *str1, char *str2) {
    int i;
    i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return false;
        }
        i++;
    }
    return str1[i] == '\0' && str2[i] == '\0';
}

void strcpy(char *dst, char *src) {
    int i;
    i = 0;
    while (src[i] != '\0') {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
}

void clear(byte *buf, unsigned int size) {
    unsigned int i;
    i = 0;
    while (i < size) {
        buf[i] = 0;
        i++;
    }
}

void atoi(char *str, int *num) {
    int i;
    int result;
    int negative;
    int digit;
    int temp;
    int j;

    i = 0;
    result = 0;
    negative = 0;

    if (str[0] == '-') {
        negative = 1;
        i = 1;
    }

    while (str[i] >= '0' && str[i] <= '9') {
        digit = str[i] - '0';

        temp = 0;
        j = 0;
        while (j < 10) {
            temp = temp + result;
            j++;
        }
        result = temp + digit;

        i++;
    }

    if (negative)
        *num = ~result + 1;
    else
        *num = result;
}

void itoa(int num, char *str) {
    int i;
    int negative;
    char temp[64];
    int rem;
    int n;
    int j;

    i = 0;
    negative = 0;

    if (num == 0) {
        str[0] = '0';
        str[1] = '\0';
        return;
    }

    if (num < 0) {
        negative = 1;
        num = ~num + 1;
    }

    while (num > 0) {
        rem = mod(num, 10);
        temp[i] = '0' + rem;
        i++;
        num = div(num, 10);
    }

    if (negative) {
        temp[i] = '-';
        i++;
    }

    j = 0;
    i--;
    while (i >= 0) {
        str[j] = temp[i];
        i--;
        j++;
    }
    str[j] = '\0';
}

