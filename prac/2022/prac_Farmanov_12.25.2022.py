# Задание 1.1
# start = int(input('Введите начало диапазона: '))
# end = int(input('Введите конец диапазона: '))
#
# for i in range(start, end + 1):
#     print(i)


# Задание 1.2
# start = int(input('Введите начало диапазона: '))
# end = int(input('Введите конец диапазона: '))
#
# for i in range(start, end + 1):
#     if i % 2 == 1:
#         print(i)


# Задание 1.3
# start = int(input('Введите начало диапазона: '))
# end = int(input('Введите конец диапазона: '))
#
# for i in range(start, end + 1):
#     if i % 2 == 0:
#         print(i)


# Задание 1.4
# start = int(input('Введите начало диапазона: '))
# end = int(input('Введите конец диапазона: '))
#
# for i in range((-end), (-start + 1)):
#     print(abs(i))


# Задание 1.5
# start = int(input('Введите начало диапазона: '))
# end = int(input('Введите конец диапазона: '))
#
# if end < start:
#     start, end = end, start
#
# for i in range(start, end + 1):
#     if i % 2 == 1:
#         print(i)


# Задание 2.1
# start = int(input('Введите начало диапазона: '))
# end = int(input('Введите конец диапазона: '))
# sum = 0
# count = 0
#
# for i in range(start, end + 1):
#     sum = sum + i
#     count += 1
#
# print(f"Сумма чисел диапазона равна  {sum}")
# print(f"Среднеарифметическое чисел диапазона равна  {sum / count}")


# Задание 2.2
# num0 = int(input('Введите число: '))
# num0_factorial = 1
#
# for i in range(1, num0 + 1):
#     num0_factorial = num0_factorial * i
# print(num0_factorial)


# Задание 2.3
# len = int(input('Введите длину линии: '))
#
# for i in range(len):
#     print('*', end = '')


# Задание 2.4
# len = int(input('Введите длину линии: '))
# symbol = input('Введите символ для заполнения: ')
#
# for i in range(len):
#     print(symbol, end = '')