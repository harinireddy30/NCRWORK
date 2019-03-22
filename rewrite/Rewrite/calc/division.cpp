extern int result;                    //declare result as extern var to use in the function
float division(int x, int y)
{
	if (y != 0)
	{
		result = (float)x / y;
		return result;
	}
	return -1;                     //return -1 in case of divide with zero
}