import random

task = int(input('Выберите задание: '))

match task:
	case 1:
		def text():
			print("\t“Don't compare yourself with anyone in this world…\n\tif you do so, you are insulting yourself.“\n\t\t\t\t\t\t\t\t\t\t\t\tBill Gates")

		text()

	case 2:
		def even_in_range(start, end):
			for i in range(start, end + 1):
				if i % 2 == 0:
					print(i)
					continue

		start = int(input('Введите начала диапазона: '))
		end = int(input('Введите конец диапазона: '))

		even_in_range(start, end)

	case 3:
		def print_square(len, sym, fill):
			i = 1

			if fill:
				for i in range(1, len + 1):
					print(len * sym)
			elif not fill:
				while i <= len:
					if i == 1 or i == len:
						print(sym * len)
						i += 1
					else:
						print(sym + ((len - 2) * ' ') + sym)
						i += 1

		len = int(input('Введите длину стороны квадрата: '))
		sym = input('Введите символ для заполнения квадрата: ')
		fill = input('Заполнить ли внутреннюю часть квадрата? (True/False): ')

		if fill.lower() == 'true':
			fill = True
		elif fill.lower() == 'false':
			fill = False

		print_square(len, sym, fill)

	case 4:
		def minimum(arg1, arg2, arg3, arg4, arg5):
			num_list = []
			tmp_min = arg1

			num_list.append(arg1)
			num_list.append(arg2)
			num_list.append(arg3)
			num_list.append(arg4)
			num_list.append(arg5)

			for i in range(5):
				if num_list[i] < tmp_min:
					tmp_min = num_list[i]

			return tmp_min

		num0 = int(input('Введите число 1: '))
		num1 = int(input('Введите число 2: '))
		num2 = int(input('Введите число 3: '))
		num3 = int(input('Введите число 4: '))
		num4 = int(input('Введите число 5: '))

		print(f"Минимальное из введенных чисел: {minimum(num0, num1, num2, num3, num4)}")


	case 5:
		def nefactorial(arg1, arg2):
			if arg2 < arg1:
				arg1, arg2 = arg2, arg1

			result = 1

			for i in range(arg1, arg2 + 1):
				result = result * i

			return result

		start = int(input('Введите нижнюю границу: '))
		end = int(input('Введите верхнюю границу: '))

		print(nefactorial(start, end))

	case 6:
		def digit_count(num0):
			result = 0

			while num0 - 0.1 > 0:
				num0 = (num0 // 10)
				result += 1

			return result

		num = int(input('Введите число: '))

		print(f"Количество цифр в введенном числе - {digit_count(num)}")

	case 7:
		def palindrome_check(num0):
			num = num0
			num_digits = []

			if num < 0:
				num = abs(num)

			while num - 0.1 > 0:
				last_digit = num % 10
				num_digits.append(last_digit)

				num = int((num - last_digit) / 10)

			if len(num_digits) % 2 == 1:
				return (f"Число '{num0}' - не палиндром.")
			else:
				first_half, second_half = [], []

				for i in range(int(len(num_digits) / 2)):
					first_half.append(num_digits[i])

				for j in range(int(len(num_digits) / 2), int(len(num_digits))):
					second_half.append(num_digits[j])

				if first_half == second_half[::-1]:
					return f"Число '{num0}' - палиндром."
				else:
					return (f"Число '{num0}' - не палиндром.")


		input_num = int(input('Введите число для проверки: '))

		print(palindrome_check(input_num))


