// help.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <cstring> 
#include <Windows.h> 
using namespace std;
int DSuche(char *st, char *str) 
{
	int sl, ssl;
	int p = -1;
	sl = strlen(st);
	ssl = strlen(str);
	for (int i = 0; i < sl - ssl + 1 && p<0; i++)  
		for (int j = 0; j < ssl && p<0; j++) 
			if (str[j] == st[i + j]) 
				if (j == ssl - 1)
				{
					p = i;
				}
	return p;
}  
int KMPSuche(char *st, char *str) 
{
	int  sl, ssl;
	int res = -1;
	sl = strlen(st);
	ssl = strlen(str);
		int  i, j = 0, k = -1;
		int  *d;
		d = new int[1000];
		d[0] = -1;
		while (j < ssl - 1) {
			while (k >= 0 && str[j] != str[k])
				k = d[k];
			j++;
			k++;
			if (str[j] == str[k])
				d[j] = d[k];
			else
				d[j] = k;
		}
		i = 0;
		j = 0;
		while (j < ssl && i < sl) {
			while (j >= 0 && st[i] != str[j]) 
				j = d[j];
			i++;
			j++;
		}
		delete[] d;
		res = j == ssl ? i - ssl : -1;
	
	return res;
} 
int BMSuche(char *st, char *str)
{  
	int  sl, ssl;
	int res = -1;
	sl = strlen(st);
	ssl = strlen(str);

		int  i, Pos;
		int  BMT[256];
		for (i = 0; i < 256; i++)
			BMT[i] = ssl;
		for (i = ssl - 1; i >= 0; i--)
			if (BMT[(short)(str[i])] == ssl)
				BMT[(short)(str[i])] = ssl - i - 1; 
		Pos = ssl - 1;
		while (Pos < sl)
			if (str[ssl - 1] != st[Pos])
				Pos = Pos + BMT[(short)(st[Pos])];
			else
				for (i = ssl - 2; i >= 0; i--) {
					if (str[i] != st[Pos - ssl + i + 1]) {
						Pos += BMT[(short)(st[Pos - ssl + i + 1])] - 1; 
						break;
					}
					else
						if (i == 0)
							return Pos - ssl + 1;
			
				}
		return res;
	}   



int _tmain(int argc, _TCHAR* argv[])   
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "RUS");
	int menu = 0, vvod = 0, algoritm = 0, vivod = 0, z, q = 0, f = 0;
	char menu1[255], vvod1[255], algoritm1[255], vivod1[255];
	int point0 = 1, point1 = 1, point2 = 1, point3 = 1, point4 = 1;
	char st[255],str[255];
	int al1, al2,al3;
	while (point0 > 0)
	{
		point0 = 1; point1 = 1; point2 = 1; point3 = 1; point4 = 1;
		system("cls");
		printf("1.Ввод данных\n");
		printf("2.Выбор алгоритма\n");
		printf("3.Вывод Данных\n"); 
		printf("4.Выход\n"); 
		printf("Ожидание ввода ");
		gets_s(menu1);
		if (strlen(menu1) != 1)
		{
			system("cls");
			printf_s("Некорректный ввод\n"); 
			system("pause");
		}
		else
		{
			system("cls");
			switch (menu1[0] == '1' ? 1 :
				menu1[0]=='2'?2:   
				menu1[0] == '3' ? 3 :
				menu1[0] == '4' ? 4 : 0)
			{ 
			case 1: {menu = 1; break; }  
			case 2: {menu = 2; break; } 
			case 3: {menu = 3; break; }
			case 4: {menu = 4; break; } 
			default: menu = 0;
			}
			switch (menu)
			{
			case 0:
			{
				printf_s("Некорректный ввод\n");
				system("pause");
				system("cls");
				break;
			}
			case 1:
			{
				while (point1 > 0) 
				{
					//Ввод Данных
					printf("1.Ввести данные вручную\n");
					printf("2.Считать данные с файла\n");
					printf("3.Назад в главное меню\n");
					printf("4.Выход\n");
					printf("Ожидание ввода ");
					gets_s(vvod1);
					if (strlen(vvod1) != 1)
					{
						printf("Некорректный ввод\n");
						system("pause");
						system("cls");
					}
					else
					{
						switch (vvod1[0] == '1' ? 1 :
							vvod1[0] == '2' ? 2 :
							vvod1[0] == '3' ? 3 :
							vvod1[0] == '4' ? 4 : 0)
						{
						case 1: {vvod = 1; break; }
						case 2: {vvod = 2; break; }
						case 3: {vvod = 3; break; }
						case 4: {vvod = 4; break; }
						default: vvod = 0;
						}
						switch (vvod)
						{
						case 0:
						{
							printf("Некорректный ввод\n");
							system("pause");
							system("cls"); 
							break;
						}
						case 1:
						{
							point1 = 0;
							system("cls");
							printf("Введите строку "); 
							gets_s(st);
							printf("Введите слово для поиска ");
							gets_s(str);
							break; 
						}
						case 2: 
						{
							point1 = 0;
							system("cls");
							FILE *F;
							fopen_s(&F, "file.txt", "w");
							char fstr[255];
							printf("Введите строку для записи в файл ");
							gets_s(fstr);
							fputs(fstr, F); 
							printf("Введите строку для поиска в файле ");
							gets_s(str);
							f++;
							fclose(F);
							system("pause");
							break;
						}
						case 3:
						{
							point1 = 0;
							point0 = 1;
							break;
						}
						case 4:
						{
							point1 = 0;
							point0 = 0;
							break;
						}
						}
					}
				}
				break;
			}
			case 2:
			{
				while (point2 > 0)
				{
					//Выбор алгоритма
					printf("1)Алгоритм прямого поиска\n");
					printf("2)Алгоритма Кнута, Морриса и Пратта\n");
					printf("3)Алгоритм Бойера и Мура\n");
					printf("4)Назад в главное меню\n");
					printf("5)Выход\n");
					printf("Ожидание ввода ");
					gets_s(algoritm1);
					if (strlen(algoritm1) != 1)
					{
						printf("Некорректный ввод\n");
						system("pause");
						system("cls");
					}
					else
					{
						switch (algoritm1[0] == '1' ? 1 :
							algoritm1[0] == '2' ? 2 :
							algoritm1[0] == '3' ? 3 :
							algoritm1[0] == '4' ? 4 :
							algoritm1[0] == '5' ? 5 : 0)
						{
						case 1: {algoritm = 1; break; }
						case 2: {algoritm = 2; break; }
						case 3: {algoritm = 3; break; }
						case 4: {algoritm = 4; break; }
						case 5: {algoritm = 5; break; } 
						default: algoritm = 0;
						}
						switch (algoritm)
						{
						case 0:
						{
							printf_s("Некорректный ввод\n");
							system("pause");
							system("cls");
							break;
						}
						case 1:
						{ 
							point2 = 0;
							system("cls");
							printf("Релизация алгоритма прямого поиска\n");
							al1 = DSuche(st, str);
							z = al1;
							q++;
							system("pause");
							break; 
						}
						case 2:
						{
							point2 = 0;
							system("cls");
							printf("Реализация алгоритма Кнута, Морриса и Пратта\n");
							al2 = KMPSuche(st, str);
							z = al2;
							q++;
							system("pause");
							break;
						}
						case 3:
						{
							point2 = 0;
							system("cls"); 
							printf("Реализация алгоритма Бойера и Мура\n");
							al3 = BMSuche(st, str);
							z = al3;
							q++;
							system("pause");
							break;
						}
						case 4:
						{
							point2 = 0;
							point0 = 1;
							break;
						}
						case 5:
						{
							point2 = 0;
							point0 = 0;
							break;
						}
						}
					}
				}
				break;
			}
			case 3:
			{
				while (point3 > 0)
				{
					//Вывод Данных
					printf("1)Вывод Данных на Экран\n");
					printf("2)Чтение из файла \n"); 
					printf("3)Назад в главное меню\n");
					printf("4)Выход\n");
					printf("Ожидание ввода ");
					gets_s(vivod1);
					if (strlen(vivod1) != 1)
					{
						printf("Некорректный ввод!\n");
						system("pause");
						system("cls");
					}
					else
					{
						switch (vivod1[0] == '1' ? 1 :
							vivod1[0] == '2' ? 2 :
							vivod1[0] == '3' ? 3 :
							vivod1[0] == '4' ? 4 : 0)
						{
						case 1: {vivod = 1; break; }
						case 2: {vivod = 2; break; }
						case 3: {vivod = 3; break; }
						case 4: {vivod = 4; break; }
						default: vivod = 0;
						}
						switch (vivod)
						{
						case 0:
						{
							printf("Некорректный ввод\n"); 
							system("pause");
							system("cls"); 
							break;
						}
						case 1:
						{
							point3 = 0;
							system("cls");
							if (q == 0)
							{  
								printf("Неверно заданы критерии поиска или не выбран алгоритм\n");
								system("pause");
								break;
							}
							else
							{
								if (z == al1)

								{
									printf("Реализация алгоритма прямого поиска\n");

									if (al1 == -1)
										printf("Вхождения не найдены\n");
									else
										printf("Позиция первого вхождения равна %d\n", al1+1);
									system("pause");
								}
								if (z == al2)
								{

									printf("Демонстрация алгоритма Кнута, Морриса и Пратта\n");
									if (al2 == -1)
										printf("Вхождения не найдены\n");
									else
										printf("Позиция первого вхождения равна %d\n", al2+1);
									system("pause");
								}
								if (z == al3)
								{

									printf("Демонстрация алгоритма Бойера и Мура\n");
									if (al3 == -1)
										printf("Вхождения не найдены\n");
									else
										printf("Позиция первого вхождения равна %d\n", al3+1);
									system("pause");
								}
								system("pause");
							}
							break;
						}
						case 2:
						{
							point3 = 0;
							system("cls");  
							if (f==0)
							{
								printf("Неверно заданы критерии поиска или не выбран алгоритм\n");
								system("pause");break;
							}
							else
							{
								int a;  
								FILE*Fp; 
								fopen_s(&Fp, "file.txt", "r");
								printf("В файл были записаны компоненты\n");
								fgets(st, 255, Fp);
								puts(st);   
								if (f == 1)
								{
									a = DSuche(st, str);
									printf("Демонстрация алгоритма прямого поиска\n");
									if (a == -1)
										printf("Вхождения не найдены\n");
									else
										printf("%d\n", a+1);
								}
								if (f == 1)
								{
									a = KMPSuche(st, str);
									printf("Демонстрация алгоритма Кнута, Морриса и Пратта\n");
									if (a == -1)
										printf("Вхождения не найдены\n");
									else
										printf("%d\n", a+1);
								}
								if (f == 1)
								{
									a = BMSuche(st, str);
									printf("Демонстрация алгоритма Бойера и Мура\n");
									if (a == -1)
										printf("Вхождения не найдены\n");
									else
										printf("%d\n", a+1);
								}
								fclose(Fp);
								system("pause");
							}
							break;
						}
						case 3:
						{
							point3 = 0;
							point0 = 1;
							break;
						}
						case 4:
						{
							point3 = 0;
							point0 = 0; 
							break;
						}
						}
					}
				}
				break;
			} 
			case 4:
			{ 
				point0 = 0; 
				break;
			}  
			}
		} 
		menu = 0; vvod = 0; algoritm = 0; vivod = 0;
	}
	system("pause");
	return 0; 
}

