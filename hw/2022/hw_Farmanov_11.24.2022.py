task = int(input('Выберите задание: '))

if task == 1:

	num1 = int(input('Введите первое число: '))
	num2 = int(input('Введите второе число: '))
	num3 = int(input('Введите третье число: '))

	print(f"{num1} + {num2} + {num3} = {num1 + num2 + num3}")
	print(f"{num1} * {num2} * {num3} = {num1 * num2 * num3}")


elif task == 2:

	salary = int(input('Введите размер зарплаты: '))
	loan = int(input('Введите сумму платежа по кредиту: '))
	utilities = int(input('Введите задолженность за к/у: '))

	rem = salary - loan - utilities

	if rem > 0:
		print('Остаток после всех выплат: ' + str(rem))

	else:
		print('Вам не хватило денег')	

elif task == 3:

	diag1 = float(input('Длина первой диагонали: '))
	diag2 = float(input('Длина второй диагонали: '))


	print(f"Площадь ромба равна: {diag1 * diag2 / 2}") 

elif task == 4:

	print('\t\t\t\t\tTo be')
	print('\t\t\t\t\tor not')
	print('\t\t\t\t\tto be')

elif task == 5:

	print('Life is what happens')
	print('\twhen')
	print("\t\tyou're busy making other plans")
	print("\t\t\t\t\t\tJohn Lennon")

else:
	print("Такого задания нет")

input()