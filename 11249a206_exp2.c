#include<stdio.h>
void towers(int, char, char, char); 
int main()
{
int num;
printf("Enter the number of disks: ");
scanf("%d", &num);
printf("The sequence of moves involved in towers of hanoi:\n");
towers(num, 'A', 'C', 'B');
return 0;
}
void towers (int num,char source,char disk,char spare)
{
if(num==1)
{
printf("\n move the disc 1 source %c to disk %c", source , disk); 
return;
}
towers(num-1,source,spare,disk);
printf("\n move the disc %d source %c to disk %c", num, source, disk);
towers(num-1,spare,disk,source);
}
