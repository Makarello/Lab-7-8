// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdio.h>
#include < string.h >
#include <math.h>;


const int N = 20;

void Plus_Vector(int* a, int* b, int* c, int N)
{
	int d, e, h;
	for (int i = 0; i < N; i++)
	{
		d = *(a + i);
		e = *(b + i);
		h = d + e;
		*(c + i) = h;
	}
}

void Minus_Vector(int* a, int* b, int* c, int N)
{
	int d, e, h;
	for (int i = 0; i < N; i++)
	{
		d = *(a + i);
		e = *(b + i);
		h = d - e;
		*(c + i) = h;
	}
}

void Dlinna_Vector(int* a, int N)
{
	int d, e, h;
	float c;

		d = *(a);
		e = *(a + 1);
		h = *(a + 2);
		c = (float)d * (float)d + (float)e * (float)e + (float)h * (float)h;
		c = sqrt(c);
		printf("%f", c);

}

void Input_Vector(int* a)
{
	int d;
	for (int i = 0; i < 3; i++)
	{
		printf("\nVvedite koord %d: ", i+1);
		scanf_s("%d", &d);
		*(a + i) = d;

	}
}

void Print_Vector(int* a)
{
	int d;
	printf("\n");
	for (int i = 0; i < 3; i++)
	{
		d = *(a + i);
		printf("%d: ", d);


	}
	printf("\n");
}

int main()
{
	int a, b;
	int l = 0;
	int* c;
	int* d;
	int* e;

	c = (int*)malloc(3 * sizeof(int));
	d = (int*)malloc(3 * sizeof(int));
	e = (int*)malloc(3 * sizeof(int));

	FILE* fp;

	char name[N];
	char* p;
	char help[5]{ "help" };
	char plus[2] = "+";
	char minus[2] = "-";
	char exit[5] = "exit";
	char dlinna[3] = "--";
	char save[5] = "save";
	char filename[9] = "data.txt";
	char cc[3];

	printf("vvedite chislo a:");
		scanf_s("\n%d\n", &a);
	printf("\nvvedite chislo b:");
		scanf_s("\n%d\n", &b);


		bool vihod = false;
		system("pause");
	while (vihod == false)
	{
		printf("\nVvedite deystvie:");
		scanf_s("%s", name, N);

		if (strcmp(plus, name) == 0)
		{
			l = a + b;
			printf("\n%d\n", l);
		}


		else if (strcmp(minus, name) == 0)
		{
			l = a - b;
			printf("\n%d\n", l);
		}

		else 	if (strcmp(help, name) == 0)
			printf("\n+ = a+b\n- = a-b\n exit = exit");

		else if (strcmp(save, name) == 0)
		{
			if ((fopen_s(&fp, filename, "w")) != NULL)
			{
				perror("Error occured while opening file");
				return 1;
			}
			fprintf(fp, "%d", l);
			fclose(fp);

			if (fopen_s(&fp, filename, "r") != NULL)
			{
				perror("Error occured while opening file");
				return 1;
			}
			fclose(fp);
		}

		else if (strcmp(exit, name) == 0)
			vihod = true;

		else 
			printf("\nNeponyal poprobuy eshe\n");
	}
	vihod = false;
	printf("\nvvedite vektor 1:");
	Input_Vector(c);
	printf("\nvvedite vektor 2:");
	Input_Vector(d);
	while (vihod == false)
	{
		printf("\nVvedite deystvie:");
		scanf_s("%s", name, N);

		if (strcmp(plus, name) == 0)
		{
			Plus_Vector(c, d, e, 3);
			Print_Vector(e);
		}

		else if (strcmp(minus, name) == 0)
		{
			Minus_Vector(c, d, e, 3);
			Print_Vector(e);
		}

		else if (strcmp(dlinna, name) == 0)
		{
			Dlinna_Vector(c, 3);
			Dlinna_Vector(d, 3);
		}


		else 	if (strcmp(help, name) == 0)
			printf("\n + = a + b\n - = a - b\n-- = dlinna vektora a\n exit = exit\n");

		else if (strcmp(exit, name) == 0)
			vihod = true;

		else
			printf("\nNeponyal poprobuy eshe\n");
	}

	 free(e);
	 free(d);
	 free(c);
		return 0;







}

