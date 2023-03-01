task = int(input('Выберите задание: '))

match task:
	case 1:
		string = input('Введите выражение: ')
		string = string.strip()

		operators = ['+', '-', '*', '/']

		for i in range(len(operators)):
			for j in range(len(string)):
				if string[j] == operators[i]:
					string = string.split(operators[i])
					final_operator = operators[i]
					break

		if final_operator == '+':
			print(f"{string[0]} + {string[1]} = {int(string[0]) + int(string[1])}")
		elif final_operator == '-':
			print(f"{string[0]} - {string[1]} = {int(string[0]) - int(string[1])}")
		elif final_operator == '*':
			print(f"{string[0]} * {string[1]} = {int(string[0]) * int(string[1])}")
		elif final_operator == '/':
			print(f"{string[0]} / {string[1]} = {int(string[0]) / int(string[1])}")


	case 2:
		num_list = input('Введите числа через пробел: ').split(' ')

		minimum = int(num_list[0])
		maximum = int(num_list[0])

		positive_count = 0
		zero_count = 0
		negative_count = 0

		for i in range(len(num_list)):
			if int(num_list[i]) > 0:
				positive_count += 1
			elif int(num_list[i]) == 0:
				zero_count += 1
			else:
				negative_count += 1

			if int(num_list[i]) < minimum:
				minimum = int(num_list[i])
			if int(num_list[i]) > maximum:
				maximum = int(num_list[i])

		print(f"Количество положительных элементов - {positive_count}")
		print(f"Количество нулей - {zero_count}")
		print(f"Количество отрицательных элементов - {negative_count}\n")

		print(f"Максимум введенных чисел: {maximum}")
		print(f"Минимум введенных чисел: {minimum}")