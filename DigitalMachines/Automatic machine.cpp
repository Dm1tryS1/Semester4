#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
using namespace std;

bool CheckCardNumber(char* string) 
{
	for (int i = 0; i < 4; i++)
	{		
		for (int j = 0; j < 4; j++)
		{
			if ((*string < '0') || (*string > '9'))
				return false;

			string++;			
		}

		if ((*string != ' ') && (i != 3))
			return false;

		string++;	
	}
	string--;
	if (*string == '\0')
		return true;
	else
		return false;
}

bool CheckName(char* string)
{
	int len = 0;
	int l = strlen(string);
	while ((*string != '\0') && (*string >= 'A' && *string <= 'Z' || *string >= 'a' && *string <= 'z'))
	{
		string++;
		len++;
	}

	if (l == len)
		return true;
	else
		return false;
}

bool CheckCVV(char* string)
{
	int len = 0;
	while ((*string != '\0') && !(*string >= 'A' && *string <= 'Z' || *string >= 'a' && *string <= 'z'))
	{
		string++;
		len++;
	}
	if (len == 3)
		return true;
	else
		return false;
}



int main() {

	char name[50], test[50], check[50], message[50], cvv[50], card_num[50], anothercard[50], deposit[50];
	int  rand_value;
	srand(time(0));

	cout << "Please, enter your card number (format: 0000 0000 0000 0000) or 'exit' to cancel transfer: ";

	do 
	{
		cin.getline(message, 255);
		if (strcmp(message, "exit")) 
		{
			strcpy(card_num, message);
			if ((CheckCardNumber(card_num))) 
			{
				cout << "Please, enter your name or 'exit' to cancel transfer: ";
				do 
				{
					cin >> message;
					if (strcmp(message, "exit")) 
					{
						strcpy(name, message);
						if (CheckName(name)) 
						{
							cout << "Please, enter the CVV code or 'exit' to cancel transfer: ";
							do 
							{
								cin >> message;
								if (strcmp(message, "exit"))
								{
									strcpy(cvv, message);
									if (CheckCVV(cvv)) 
									{
										cout << "\nPlease, check:\n";
										cout << "Card number: " << card_num << endl;
										cout << "Name: " << name;
										cout << "\n--------------------------------------------\n";
										cout << "Enter 'OK' to continue\n";
										cin >> test;
										if (!strcmp(test, "OK")) 
										{
											cout << "\n--------------------------------------------\n";
											cout << "Please, enter card number for transfer or 'exit' to cancel transfer: ";
											cin.get();
											do 
											{												
												cin.getline(message, 255);
												if (strcmp(message, "exit")) 
												{
													strcpy(anothercard, message);
													if (CheckCardNumber(anothercard) && strcmp(anothercard, card_num)) 
													{
														cout << "Please, enter deposit (rub) or 'exit' to cancel transfer: ";
														do 
														{
															cin >> message;
															if (strcmp(message, "exit")) 
															{
																strcpy(deposit, message);
																if ((atoi(message) <= 10000) and (atoi(message) >= 100)) 
																{

																	cout << "\nPlease, check:\n";
																	cout << "Card to: " << anothercard << endl;
																	cout << "Deposit: " << deposit;
																	cout << "\n--------------------------------------------\n";
																	cout << "Enter 'OK' to continue\n";
																	cin >> check;
																	if (!strcmp(check, "OK")) 
																	{
																		cout << "\n--------------------------------------------\n";
																		rand_value = rand() % 9000 + 1000;
																		cout << "Please, enter the code: " << rand_value << " for transfer or 'exit' to cancel transfer\n";
																		do 
																		{
																			cout << "Input: ";
																			cin >> message;
																		} while ((atoi(message) != rand_value) && (strcmp(message, "exit")));

																		if (!strcmp(message, "exit"))
																			cout << "\nCancel transfer, goodbuy!\n";
																		else
																			cout << "\nTransfer was successful!!!\n";
																	}
																}
																else
																	cout << "Chose another deposit (more then 99 rub and less then 10001 rub): ";
															}
															else 
																cout << "\nCancel transfer, goodbuy!\n";

														} while (((atoi(message) < 100) or (atoi(message) > 10000)) && (strcmp(message, "exit")));

													}
													else
														cout << "Please, enter another card number: ";
												}
												else
												{
													cout << "\nCancel transfer, goodbuy!\n";
													//strcpy(message, message2);
												}

											} while (strcmp(message, "exit") && !(CheckCardNumber(anothercard) and strcmp(anothercard, card_num)));
										}
									}
									else
										cout << "Wrong! Enter again: ";
								}
								else
									cout << "\nCancel transfer, goodbuy!\n";

							} while ((strcmp(message, "exit")) && (!CheckCVV(cvv)));

						}
						else
							cout << "Wrong! Name should have only symbols: ";
					}
					else
						cout << "\nCancel transfer, goodbuy!\n";

				} while (strcmp(message, "exit") && !CheckName(name));

			}
			else
				cout << "Wrong! Please, enter card number like: 0000 0000 0000 0000: ";
		}
		else
			cout << "\nCancel transfer, goodbuy!\n";

	} while ((strcmp(message, "exit")) && ((!CheckCardNumber(card_num))));

}