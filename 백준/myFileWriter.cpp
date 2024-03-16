#include <iostream>
using namespace std;

int main() {
	std::ofstream writeFile;
	writeFile.open("words.txt");
	char arr[11] = "BlockDMask";
	if (writeFile.is_open())
	{
		writeFile.write(arr, 10);
	}writeFile.close();
}
