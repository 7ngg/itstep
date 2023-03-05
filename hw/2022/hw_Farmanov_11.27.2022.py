print('Выберите задание: ')
task = int(input())

if task == 1:
	num1 = input('Введите первое число: ')
	num2 = input('Введите второе число: ')
	num3 = input('Введите третье число: ')

	print(num1 + num2 + num3)

elif task == 2:
	num0 = int(input('Введите число: '))

	num1 = num0 // 1000
	num2 = num0 // 100 % 10
	num3 = num0 % 100 // 10
	num4 = num0 % 10

	print(f"{num1} * {num2} * {num3} * {num4} = {num1 * num2 * num3 * num4}")

elif task == 3:
	m = float(input('Введите величину в метрах: '))

	mm = m * 1000
	cm = m * 100
	dm = m * 10
	km = m / 1000
	miles = m / 1604.34

	print('Величина в миллиметрах: ' + str(mm))
	print('Величина в сантиметрах: ' + str(cm))
	print('Величина в дециметрах: ' + str(dm))
	print('Величина в метрах: ' + str(m))
	print('Величина в километрах: ' + str(km))
	print('Величина в милях: ' + str(miles))

elif task == 4:
	side = float(input('Введите длину стороны: '))
	height = float(input('Введите длину высоты: '))

	print(f"Площадь треугольника равна {side * height / 2}")

elif task == 5:
	num0 = int(input('Введите число: '))

	num1 = num0 // 1000
	num2 = num0 // 100 % 10
	num3 = num0 % 100 // 10
	num4 = num0 % 10

	print(f"{num4}{num3}{num2}{num1}")

else: 
	print('Такого задания нет')

input()
