#include <iostream>
#include <string> 
using namespace std;

void back(std::string myStr, int index)
{

	if (index < 0)
	{
		std::cout << std::endl;
		return;
	}

	std::cout << myStr[index];

	back(myStr, index - 1);

}

int main()
{

	std::string myStr;
	//myStr = "BACKWARDS";
	myStr = "SDRAWKCAB"; //so, it will print normally if it works

	for (int i = myStr.length() - 1; i >= 0; i--)
	{

		std::cout << myStr[i];
	}

	std::cout << std::endl;


	std::cout << "RECURSIVELY" << std::endl;

	back(myStr, myStr.length() - 1);


}
