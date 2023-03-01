task = int(input('Выберите задание: '))

match task:
	case 1:
		num0 = int(input('Введите число: '))

		if 1 < num0 < 100:
			if num0 % 3 == 0 and num0 % 5 != 0:
				print('Fizz')
			elif num0 % 5 == 0 and num0 % 3 != 0:
				print('Buzz')
			elif num0 % 15 == 0:
				print('Fizz Buzz')
			elif num0 % 15 != 0:
				print(num0)
		else:
			print('Ошибка')

	

	case 2:
		num0 = int(input('Введите число: '))
		deg = int(input('В какую степень возвести число?\n'))

		if  0 <= deg <= 7:
			print(f"Ответ - {num0 ** deg}")
		else:
			raise ValueError()

	

	case 3:
		price0 = float(input('Введите стоимость разговора: '))

		print('1. Оператор 1 - Оператор 1\n2. Оператор 1 - Оператор 2\n')
		print('3. Оператор 2 - Оператор 2\n4. Оператор 2 - Оператор 1\n')

		choise = int(input('Выберите пару операторов:\n'))

		if choise == 1:
			print(f"Вы заплатите {price0 * 1}₼ за минуту разговора.")
		elif choise == 2:
			print(f"Вы заплатите {price0 * 1.2}₼ за минуту разговора.")
		elif choise == 3:
			print(f"Вы заплатите {price0 * 1}₼ за минуту разговора.")
		elif choise == 4:
			print(f"Вы заплатите {price0 * 1.1}₼ за минуту разговора.")
		else:
			raise ValueError()

	

	case 4:
		mgr1 = int(input('Уровень продаж первого менеджера: '))
		mgr2 = int(input('Уровень продаж второго менеджера: '))
		mgr3 = int(input('Уровень продаж третьего менеджера: '))
		min_salary = 200

		if mgr1 < 500:
			salary_mgr1 = 200 + (mgr1 * 0.03)
		elif 500 <= mgr1 <= 1000:
			salary_mgr1 = 200 + (mgr1 * 0.05)
		elif 1000 < mgr1:
			salary_mgr1 = 200 + (mgr1 * 0.08)
		print(f"\nЗарпалата первого менеджера - {salary_mgr1}")

		if mgr2 < 500:
			salary_mgr2 = 200 + (mgr2 * 0.03)
		elif 500 <= mgr2 <= 1000:
			salary_mgr2 = 200 + (mgr2 * 0.05)
		elif 1000 < mgr2:
			salary_mgr2 = 200 + (mgr2 * 0.08)
		print(f"Зарпалата второго менеджера - {salary_mgr2}")

		if mgr3 < 500:
			salary_mgr3 = 200 + (mgr3 * 0.03)
		elif 500 <= mgr3 <= 1000:
			salary_mgr3 = 200 + (mgr3 * 0.05)
		elif 1000 < mgr3:
			salary_mgr3 = 200 + (mgr3 * 0.08)
		print(f"Зарпалата третьего менеджера - {salary_mgr3}")


		if salary_mgr1 > salary_mgr2 and salary_mgr1 > salary_mgr3:
			print(f"\nЛучший менеджер - первый.\nЕго зарплата вместе с премией - {salary_mgr1 + 200}$")
		if salary_mgr2 > salary_mgr1 and salary_mgr2 > salary_mgr3:
			print(f"\nЛучший менеджер - второй.\nЕго зарпалата вместе с премией - {salary_mgr2 + 200}$")
		if salary_mgr3 > salary_mgr1 and salary_mgr3 > salary_mgr2:
			print(f"\nЛучший менеджер - третий.\nЕго зарпалата вместе с премией - {salary_mgr3 + 200}$")

	case _:
		print('???')

input()