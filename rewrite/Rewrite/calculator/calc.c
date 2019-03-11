/*IMPLEMENTATION OF CALCULATOR PROGRAM USING RUNTIME INPUT CONTAINING CONTINUOS STRING OF OPERANDS AND OPERATORS*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int operator=-1;
int main()
{
	int op1, op2, x, y;
	char operator;                        
	printf("Enter the expression:\n");      
	if (scanf("%d", &op1))            //enter the first operand.returns non-zero value if read value is an integer and 0 if not
	{
		x = op1;                         
		while (1)                     
		{
			scanf("%c", &operator);     //read the operator
			if (operator=='\n')         //read values until it encounters '\n' and the breaks
				break;
			
			if (scanf("%d", &op2))      //read the operand2 returns non-zero value if scanned value is a character and returns 0 if not
			{
				y = op2;                
				switch (operator)
				{
				case '+':
				{
					op1 = add(op1, op2);
					break;
				}
				case '-':
				{
					op1 = sub(op1, op2);
					break;
				}
				case '*':
				{
					op1 = mul(op1, op2);
					break;
				}
				case '/':
				{
					op1 = divis(op1, op2);
					break;
				}
				}
			}
			else
				printf("Operator shd be succeded by an operand\n");
		}
		printf("The result is %d", op1);                           //result is stored in operand op1
	}
	else
		printf("The first character should be an operand always\n");   //when the first character input is not an operand
	system("pause");                                                   //waits for user input to exit
	return 0;
}
