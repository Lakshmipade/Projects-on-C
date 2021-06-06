 #include<stdio.h>
 #include<conio.h>
 #include<string.h>
 #include<stdlib.h>
 struct contact
 {
	int Serial_no;
	char Category[20];
	char Name[20];
	char Gender;
	int Age;
	char Address;
	int Phone[15];
	char Email_id[10];
}cont;
 void main()
 {
	void add_contact();//prototype declaration
	void list_contact();
	void delete_contact();
	int i;
	char pass[30],ch,original[30],choice;
	FILE *fp;
	window(1,1,80,25);
	textbackground(YELLOW);
	clrscr();
	window(20,10,60,15);
	textbackground(BLACK);
	clrscr();
	gotoxy(4,3);
	textcolor(RED+BLINK);
	cprintf("ENTER THE PASSWORD:");
	i=0;
	while(1)
	{
		ch=getch();
		if(ch==13) //ASCII code ENTER key
		{
			pass[i]='\0';
			break;
		}
		pass[i++]=ch;
		printf("*");

	}
	//Reading data from the file
	fp=fopen("password.dat","r");
	fgets(original,30,fp);
	fclose(fp);
	if(!strcmp(original,pass)==0)
	{
		gotoxy(4,5);
		textcolor(WHITE+BLINK);
		printf("INCORRECET PASSWORD!! Press any Key...");
		getch();
		exit(0);

	}
	else
		{
		window(1,1,80,25);
		textbackground(11);
		clrscr();
		gotoxy(30,4);
		textcolor(RED);
		cprintf("CONTACT MANAGER");
		gotoxy(30,6);
		textcolor(BLUE);
		cprintf("Version no.:1.0");
		gotoxy(25,8);
		textcolor(YELLOW);
		cprintf("Developed by: Computer Education");
		gotoxy(5,20);
		textcolor(RED);
		cprintf("Please wait......");
		for(i=0;i<=50;i++)
		{
			 cprintf("%c",220);
			 delay(10);
		}
		textbackground(YELLOW);
		clrscr();
		window(18,4,60,20);
		textbackground(BLACK);
		clrscr();
		textcolor(RED);
		gotoxy(18,2);
		cprintf("MAIN MENU");
		gotoxy(15,3);
		cprintf("----------------");
		textcolor(WHITE);
		gotoxy(15,4);
		cprintf("1.Add new contact");
		gotoxy(15,5);
		cprintf("2.Delete contact");
		gotoxy(15,6);
		cprintf("3.Edit contact");
		gotoxy(15,7);
		cprintf("4.search contact");
		gotoxy(15,8);
		cprintf("5.List of contact");
		gotoxy(15,9);
		cprintf("6.Change password");
		gotoxy(15,10);
		cprintf("7.Exit");
		gotoxy(10,11);
		cprintf("-------------------------");
		gotoxy(14,12);
		textcolor(YELLOW+BLINK);
		cprintf("Enter your choice?");

		choice=getche();
		switch(choice)
		{
			case '1':
				add_contact();
				break;
			case '2':
				delete_contact();
				break;
		   case '5':
				list_contact();
				break;
		   case '7':
				exit(0);
		}
		getch();
	}
}
void add_contact()

  {  int i;
	 FILE *fp;
	window(1,1,80,25);
	textbackground(GREEN);

	textcolor(WHITE);
	clrscr();
	cprintf("Add New Contact\n");
	printf("\n");
	for(i=1;i<=80;i++)
	{
	cprintf("-");
	}
	fflush(stdin);
	cprintf("\nEnter Serial_no:");
	scanf("%d",&cont.Serial_no);
	fflush(stdin); //to clear input buffer
	cprintf("\nEnter Name:");
	gets(cont.Name);
	fflush(stdin);
	cprintf("\nEnter Category(Friend/Customer/Student/Salesmem/PG):");
	gets(cont.Category);
	fflush(stdin);
	cprintf("\nEnter Gender(M/F):");
	scanf("%c",&cont.Gender);
	fflush(stdin);
	cprintf("\nEnter Address:");
	scanf("%d",&cont.Address);
	fflush(stdin);
	cprintf("\nEnter phone number:");
	scanf("%d",&cont.Phone);
	fflush(stdin);
	cprintf("\nEnter Age:");
	scanf("%d",&cont.Age);
	fflush(stdin);
	cprintf("\nEnter email_id:");
	gets(cont.Email_id);
	fflush(stdin);

	fp=fopen("info.dat","ab");
	fwrite(&cont,sizeof(cont),1,fp);
	fclose(fp);
	textcolor(RED+BLINK);
	cprintf("\nSucessfully Saved, Press any key...");
	getch();
}
void list_contact()
{
		int i;
		FILE *fp;
		window(1,1,80,25);
		textbackground(WHITE);
		clrscr();
		textcolor(BLUE);
		gotoxy(35,1);
		cprintf("List of Contact");
		printf("\n");
		for(i=1;i<=80;i++)
		{
		 cprintf("-");
		 }
		gotoxy(1,3);
		cprintf("Serial_no.");
		gotoxy(13,3);
		cprintf("Name");
		gotoxy(20,3);
		cprintf("Category");
		gotoxy(30,3);
		cprintf("Gender");
		gotoxy(40,3);
		cprintf("Age");
		gotoxy(50,3);
		cprintf("Contact");
		gotoxy(60,3);
		cprintf("Email_id");
		printf("\n");
		for(i=1;i<80;i++)
		{
		cprintf("-");
		}
		fp=fopen("info.dat","rb");
		i=5;
		while(fread(&cont,sizeof(cont),1,fp)!=NULL)
		{
			gotoxy(1,i);
			cprintf("%d",cont.Serial_no);
			gotoxy(13,i);
			cprintf("%d",cont.Name);
			gotoxy(20,i);
			cprintf("%d",cont.Category);
			gotoxy(30,i);
			cprintf("%d",cont.Gender);
			gotoxy(40,i);
			cprintf("%d",cont.Age);
			gotoxy(50,i);
			cprintf("%d",cont.Phone);
			gotoxy(60,i);
			cprintf("%d",cont.Email_id);
			i++;
		}
		close(fp);
		textcolor(RED+BLINK);
		printf("\n");
		cprintf("Press any Key....");
		getch();
	}
void delete_contact()
{
		int i;
		FILE *fp;
		window(1,1,80,25);
		textbackground(GREEN);
		clrscr();
		gotoxy(30,2);
		textcolor(WHITE);
		cprintf("Delete Contact");
		printf("\n");
		for(i=0;i<=80;i++)
		{
		cprintf("-");
		}
		fp=fopen("info.dat","rb");
		while((fread(&cont,sizeof(cont),1,fp)!=NULL))
		{
		}
		close(fp);
		textcolor(RED+BLINK);
		printf("Press any key.......");
		getch();
}







