#include<iostream>
using namespace std;
namespace set_from{
	char from;
	namespace set_to{
		char to;
		class print_characters {
		public:
			
		};
	}
}
int main()
{
	cout << "Enter the range of characters to print:" << endl;
	cout << "From:";
	cin >> set_from::from;    //access 'from' using scope resolution   
	cout << endl << "To:";
	cin >> set_from::set_to::to;      //accessing member from nested namespace
	char initial;
	for (initial = set_from::from; initial <=set_from::set_to::to; initial++)
		cout << initial;
	cout << endl;
	system("pause");
	return 0;
}