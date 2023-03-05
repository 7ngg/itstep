import random

#Задание 1
# num0 = int(input('Введите число: '))
# multiplier = 1

# while multiplier <= 10:
# 	print(f"{num0} * {multiplier} = {num0 * multiplier}")
# 	multiplier += 1



#Задание 2
# while True:
# 	amount = int(input('Введите количество конвертируемой валюты или 0 - для выхода.\n'))
# 	if amount == 0:
# 		break

# 	currency = int(input('Выберите Вашу валюту.\n1 - AZN\n2 - USD\n3 - RUB\n0 - Выход.\n'))
# 	if currency == 0:
# 		break

# 	convert_to = int(input('В какую валюту сконвертировать?\n1 - AZN\n2 - USD\n3 - RUB\n0 - Выход.\n'))
# 	if convert_to == 0:
# 		break


# 	if currency == 1:
# 		if convert_to == 1:
# 			print(f"Результат конвертации - {amount * 1} AZN")
# 		elif convert_to == 2:
# 			print(f"Результат конвертации - {amount / 1.7} USD")
# 		elif convert_to == 3:
# 			print(f"Результат конвертации - {amount * 35} RUB")

# 	if currency == 2:
# 		if convert_to == 1:
# 			print(f"Результат конвертации - {amount * 1.7} AZN")
# 		elif convert_to == 2:
# 			print(f"Результат конвертации - {amount * 1} USD")
# 		elif convert_to == 3:
# 			print(f"Результат конвертации - {amount * 60} RUB")

# 	if currency == 3:
# 		if convert_to == 1:
# 			print(f"Результат конвертации - {amount / 35} AZN")
# 		elif convert_to == 2:
# 			print(f"Результат конвертации - {amount / 60} USD")
# 		elif convert_to == 3:
# 			print(f"Результат конвертации - {amount * 1}")



#Задание 3
# start = int(input('Введите нижнюю границу диапазона: '))
# end = int(input('Введите верхнюю границу диапазона: '))
# num = int(input('Введите число: '))

# while start <= end:
# 	if start == num:
# 		print(f"!{num}!", end = ' ')
# 		start += 1
# 	else:
# 		print(start, end = ' ')
# 		start += 1



#Задание 4
# random = random.randint(1, 500)

# while True:
# 	num = int(input('Введите Ваше число или 0 - для выхода.\n'))

# 	if num == 0:
# 		break
# 	elif num < random:
# 		print('Загаданное число больше введенного.\n')
# 	elif random < num:
# 		print('Загаданное число меньше введенного.\n')
# 	else:
# 		print('Вы угадали число!')
# 		break