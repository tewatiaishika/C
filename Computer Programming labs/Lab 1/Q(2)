#include <stdio.h>

void printeachdigit(int N)
{
  //declaring variable//
    int i = 0;
    int s=0;
    int arr[7]; // declaring the array to contain 8 numbers//
    int j;
    int rem;
    while (N!= 0)
    {
      rem = N % 10;
      arr[i] = rem;
      i++;
      N = N / 10;
    }
      for (j=i-1;j>-1;j--)
      {
        s = s + arr[j];
        printf("%d\n",arr[j]);
    }
    //sum of the student number digits entered by the user//
    printf("The sum of the digits is\n");
    printf("%d\n", s);
}

int main()
{
    int n;
    printf("enter the student number:");
    scanf("%d",&n);
    if(n<0)
{
  //additional check//
    printf("Invalid number entered");

}
    printeachdigit(n);
    return 0;
}
