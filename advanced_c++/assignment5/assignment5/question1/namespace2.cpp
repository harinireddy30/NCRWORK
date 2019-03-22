namespace namespace2 {
	class method2 {
		int result;
	public:
		int addition_after_mod(int operand1, int operand2)
		{
			if (operand1 < 0)
				operand1 = -operand1;
			if (operand2 < 0)
				operand2 = -operand2;
			return (operand1 + operand2);
		}
		int subtraction_after_mod(int operand1, int operand2)
		{
			if (operand1 < 0)
				operand1 = -operand1;
			if (operand2 < 0)
				operand2 = -operand2;
			return (operand1 - operand2);
		}
	};
}