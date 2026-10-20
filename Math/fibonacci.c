#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

void fibonacciSeries(int n)
{
    int a = 0;
    int b = 1;
    int next = 0;

    // printf("%d %d", a, b);
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", a);
        next = a + b;
        a = b;
        b = next;
    }
}

bool isPalindrome(char arr[], int n)
{
    int left = 0;
    int right = n - 1;

    while (left >= right)
    {
        if (arr[left] != arr[right])
        {
            return false;
        }
        left++;
        right--;
    }

    return true;
}

bool isArmstring(int n)
{
    int temp = n;
    int digit = 0;
    while (n != 0)
    {
        n = n / 10;
        digit++;
    }

    n = temp;

    int armstring = 0;

    while (n != 0)
    {
        armstring += pow(n % 10, digit);
        n = n / 10;
    }

    if (temp == armstring)
    {
        return true;
    }

    return 0;
}

int main()
{

    int n;
    scanf("%d", &n);

    int ans = isArmstring(n);

    printf("%d", ans);

    // char str[n];

    // for (int i = 0; i < n; i++)
    // {
    //     scanf("%c", &str[i]);
    // }

    // int a = isPalindrome(str, n);

    // printf("%d", a);

    // printf("Enter number of terms : ");
    // scanf("%d", &n);

    // fibonacciSeries(n);
    ///
    return 0;
}