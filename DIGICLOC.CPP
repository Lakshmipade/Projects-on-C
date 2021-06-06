#include<stdio.h>
#include<conio.h>

void main()
{
	int h=0,m=0,s=0;
	printf("Please enter the format in HH:MM:SS:");
	scanf("%d%d%d",&h,&m,&s);

	start:
	for(h;h<24;h++)
	{
		for(m;m<60;m++)
		{
				for(s;s<60;s++)
				{
					clrscr();
					printf("\n\n\n\t\t\t\t%d %d %d\n",h,m,s);
					printf("\n\n\n\t\tSunday 18 NOV 2019");
					if(h<12)
					{
						printf("  AM");

					}
					 else
					{
						printf("  PM");
					}
					for(double i=0;i<361999;i++)
					i++;
					i--;

				}
		}        s=0;
		m=0;
	}
   h=0;
   goto start;
 getch();
}
