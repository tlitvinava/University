#include "func_for_studenichnik.h"
#include "Studenichnik1.h"
#include <iostream>

void title(int var) {
	setlocale(LC_ALL, "Russian");
	std::cout << "���������: ��������� ������\n";
	if (var != -1) {
		std::cout << "�������: " << var << '\n';
	}
	std::cout << "������� 1\n";
}

bool check_string(const std::string& str) {
	for (char c : str) {
		if (std::isdigit(c)) {
			std::cout << '\n' << "������. ������� ��� ���: ";
			return false;
		}
	}
	return true;
}

short check_choose() {
	short c = 0;
	while (true) {
		if (std::cin >> c) {
			if (c >= 1 || c <= 6) {
				return c;
			}
			else {
				std::cout << "������.������� ��� ���: ";
			}
		}
		else {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "������.������� ��� ���: ";
		}

	}
}

bool is_double(std::string str)
{
	bool dot = false;
	for (int i = 0; i < str.size(); i++)
	{
		if (!isdigit(str[i]))
		{
			if (str[i] == '.' && !dot && i != 0)
			{
				dot = true;
			}
			else
			{
				return false;
			}
		}
	}
	return true;
}

void add(Studenichnik& sh, int i) {//
	sh.fname = "Taya"; // ��������������
	sh.sname = "Litvinava";
	sh.otchestvo = "Andreevna";
	sh.num = "353504";
	sh.doxod = 100;
	sh.ball = 10;

	std::cout << "\n������� #" << i << ":\n";

	std::string stop = "����";//�������� ����������
	std::string keep = "��";
	std::string keep1;
	std::string previous = "������";
	std::string input;

	std::cout << "\n������� ���: ";
	do {
		std::cin >> input;
	} while (!check_string(input));
	if (input == stop) {
		return;
	}
	sh.fname = input;

	std::cout << "\n������� �������: ";
	do {
		std::cin >> input;
	} while (!check_string(input));
	if (input == stop) {
		return;
	}
	sh.sname = input;

	std::cout << "\n������� ��������: ";
	do {
		std::cin >> input;
	} while (!check_string(input));
	if (input == stop) {
		return;
	}
	sh.otchestvo = input;

	std::cout << "\n������� ����� ������: ";
	std::cin >> input;
	if (input == stop) {
		return;
	}
	sh.num = input;
	std::cout << "\n������� ������� ����: ";
	std::cin >> input;
	if (input == stop) {
		return;
	}
	sh.ball = stod(input);
	std::cout << "\n������� ����� �� ����� �����: ";
	std::cin >> input;
	if (input == stop) {
		return;
	}
	sh.doxod = stod(input);

}

void show(const Studenichnik& arr, int i) {//
	std::cout << "\n\n�����: " << i;
	std::cout << "���: " << arr.fname << '\n';
	std::cout << "�������: " << arr.sname << '\n';
	std::cout << "��������: " << arr.otchestvo << '\n';
	std::cout << "����� ������: " << arr.num << '\n';
	std::cout << "������� ����: " << arr.ball << '\n';
	std::cout << "�����: " << arr.doxod << '\n';
}

void previous_enter(Studenichnik* array, int n) {//�� ����������
	if (n > 0) {
		bool b;
		std::cout << "������ ������� �� ���������� ���������? (0 ��� 1)";
		std::cin >> b;
		if (b) {
			int choose;
			std::cout << "\n�������� �����: ";
			for (int k = 0; k < n; ++k) {
				show(array[k], k);
			}

			std::cin >> choose;
			array[n] = array[choose];
		}
		else {
			add(array[n], n);
		}
	}
	else {
		add(array[0], 0);
	}
}

bool check(Studenichnik stud, std::string param, int choice) {
	switch (choice)
	{
	case 1:
		return stud.fname == param;
	case 2:
		return stud.sname == param;
	case 3:
		return stud.otchestvo == param;
	case 4:
		return stud.num == param;
	case 5:
		if (is_double(param))
		{
			return stud.ball == stod(param);
		}
		return false;
	case 6:
		if (is_double(param))
		{
			return stud.doxod == stod(param);
		}
		return false;
	default:
		return false;
	}
}


void sort(Studenichnik*& arr, int n) {//���������� �������
	for (int i = 0; i < n; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j].doxod < arr[min].doxod) {
				min = j;
			}
			std::swap(arr[min], arr[i]);
		}
	}
}


void add_more(Studenichnik* array, int& n) {//?
	int index;
	std::cout << "������� ��������� �� ������ ��������? ";
	std::cin >> index;

	for (int i = n; i < n + index; ++i) {
		add(array[i], i);
	}
	n += index;
}

void find_element(Studenichnik* array, int n, const std::string& param) {
	for (int i = 0; i < n; i++) {
		if (array[i].fname == param || array[i].sname == param || array[i].otchestvo == param ||
			array[i].num == param) {
			show(array[i], i);
		}
		if (is_double(param))
		{
			if (array[i].ball == stod(param) || array[i].doxod == stod(param))
			{
				show(array[i], i);
			}
		}
	}
}

void delete_or_change(Studenichnik* array, int& n, int index) {
	bool b;
	std::cout << "��� �� ������ �������?"
		"\n\t0) �������"
		"\n\t1) ��������";
	std::cout << std::endl;
	std::cin >> b;

	if (b == 0) {
		for (int i = index; i < n; ++i) {
			array[i] = array[i + 1];
		}
		--n;
	}
	else {
		add(array[index], index);
	}
}