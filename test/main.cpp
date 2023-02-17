#include <iostream>
#include "../append_to_dynamic_array.h"
#include "lib/print_dynamic_array/print_dynamic_array.h"
#include "lib/userin/userin.h"

int main()
{
	const std::string out_actual_size = "Введите фактический размер массива: ";
	const std::string out_logical_size = "Введите логический размер массива: ";
	const std::string out_added_val = "Введите элемент для добавления: ";
	const std::string out_array = "Динамический массив: ";
	const std::string out_final_array = "Спасибо! Ваш массив: ";
	const std::string err_msg = 
		"Ошибка! Логический размер массива не может превышать фактический!";

	std::string out_arr_val = "";
	std::string out_arr_val1 = "Введите arr[";
	std::string out_arr_val2 = "]: ";

	int actual_size = 0;
	int logical_size = 0;
	int added_val = 0;

	userIn(actual_size, out_actual_size);
	userIn(logical_size, out_logical_size);

	if (actual_size < logical_size)
	{
		std::cout << err_msg << std::endl;

		return 1;
	}

	int* arr = new int[actual_size]();

	for (int i = 0; i < logical_size; ++i)
	{
		std::string i_str = std::to_string(i);
		out_arr_val = out_arr_val1 + i_str + out_arr_val2;

		userIn(arr[i], out_arr_val);
	}

	std::cout << out_array;
	print_dynamic_array(arr, logical_size, actual_size);

	do
	{
		userIn(added_val, out_added_val);

		arr = append_to_dynamic_array(arr, logical_size, actual_size, added_val);

		if (added_val == 0)
		{
			std::cout << out_final_array;
		}
		else
		{
			std::cout << out_array;
		}
		print_dynamic_array(arr, logical_size, actual_size);

	} while (added_val != 0);

//	print_dynamic_array(arr, logical_size, actual_size);

	delete[] arr;
	arr = nullptr;

	return 0;
}
