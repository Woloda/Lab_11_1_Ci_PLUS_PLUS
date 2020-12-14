#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_11.1(C++)/Lab_11.1(C++).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab111C
{
	TEST_CLASS(UnitTestLab111C)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			ofstream file("E:\\Моя папка. Навчання\\Student [IK-11] [Дорожовець]\\Lab_11.1(C++)\\Lab_11.1(C++)\\test.dat", ios::binary);

			double x = 0.28;
			for (int i = 0; i < 6; i++)
			{
				x = x + 0.28;
				cout << x << endl;
				file.write((char*)&x, sizeof(double));
			}
			file.close();

			operation("E:\\Моя папка. Навчання\\Student [IK-11] [Дорожовець]\\Lab_11.1(C++)\\Lab_11.1(C++)\\test.dat", "E:\\Моя папка. Навчання\\Student [IK-11] [Дорожовець]\\Lab_11.1(C++)\\Lab_11.1(C++)\\test1.dat", 6);
			ifstream file_l("E:\\Моя папка. Навчання\\Student [IK-11] [Дорожовець]\\Lab_11.1(C++)\\Lab_11.1(C++)\\test1.dat", ios::binary);
			file_l.read((char*)&x, sizeof(double));

			Assert::AreEqual(x, 1.12);
			file_l.close();
		}
	};
}
