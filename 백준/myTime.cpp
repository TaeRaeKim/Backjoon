#include <iostream>
#include <ctime>
using namespace std;

int main() {
	clock_t start, finish;
	double duration;

	start = clock();

	/*���� �ð��� �����ϰ� ���� �ڵ�*/
	/*���� �ð��� �����ϰ� ���� �ڵ�*/

	finish = clock();

	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << duration << "��" << endl;
}