task = int(input('Выберите задание: '))

match task:
	case 1:
		start = int(input('Введите начало диапазона: '))
		end = int(input('Введите конец диапазона: '))

		while start <= end:
			if start % 7 == 0:
				print(start, end = ' ')
				start += 1
			else:
				start += 1



	case 2:
		start = int(input('Введите начало диапазона: '))
		end = int(input('Введите конец диапазона: '))
		start_backup = start
		end_backup = end

		while start <= end:
			print(start, end = ' ')
			if start == end:
				print()
			start += 1

		start = start_backup

		while start <= end:
			print(end, end = ' ')
			if start == end:
				print()
			end -= 1

		end = end_backup

		while start <= end:
			if start % 7 == 0:
				print(start, end = ' ')
				if start == end:
					print()
				start += 1
			else:
				if start == end:
					print()
				start += 1

		start = start_backup
		n = 0

		while start <= end:
			if start % 5 == 0:
				n += 1
				start +=1
			else:
				start += 1
		print(n)



	case 3:
		start = int(input('Введите начало диапазона: '))
		end = int(input('Введите конец диапазона: '))

		while start <= end:
			if start == 0:
				print(f"{start} - Ноль же делится на все...")
				start += 1
			elif start % 3 == 0 and start % 5 != 0:
				print(f"{start} - Fizz")
				start += 1
			elif start % 5 == 0 and start % 3 != 0:
				print(f"{start} - Buzz")
				start += 1
			elif start % 15 == 0:
				print(f"{start} - Fizz Buzz")
				start += 1
			else:
				print(start)
				start += 1