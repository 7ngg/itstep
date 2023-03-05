#Задание 1
# num0 = int(input('Введите число: '))

# if num0 // 1000000 == 0:
# 	num1 = (num0 // 100000) + (num0 // 10000 % 10) + (num0 // 1000 % 10)
# 	num2 = (num0 % 1000 // 100) + (num0 % 100 // 10) + (num0 % 10)
	
# 	if num1 == num2:
# 		print('Число - счастливое')
# 	else:
# 		print('Число - несчастливое')

# else:
#     print('Ошибка')



# Задание 2
# num0 = int(input('Введите число: '))

# char1 = num0 // 100000
# char6 = num0 % 10

# char2 = num0 // 10000 % 10
# char5 = num0 % 100 // 10

# step1 = num0 % 10000
# step2 = step1 //100

# print(f"{(step2 * 100) + (char2 * 10) + char1 + (char5 * 10000) + (char6 * 100000)}")



# Задание 3
# mth = int(input('Введите номер месяца: '))

# if (mth <= 2 or mth ==12):
#     print('Winter')
# elif mth <= 5:
#     print('Spring')
# elif mth <= 8:
#     print('Summer')
# elif mth <= 11:
#     print('Autumn')
# else:
#     print('Error')

