# Задание 1
# time = int(input('Введите прошедшее время в секундах: '))
#
# print('1. Часы')
# print('2. Минуты')
# print('3. Секунды')
# oper = int(input('Выберите операцию: '))
#
# if oper == 1:
#     print(f"Осталось {(86400 - time) / 3600} часов")
# elif oper == 2:
#     print(f"Осталось {(86400 - time) / 60} минут")
# elif oper == 3:
#     print(f"Осталось {86400 - time} секунд")
# else:
#     print('Такая операция не опеределена')


# Задание 2
# diam = int(input('Введите диаметр: '))
#
# print('1. Площадь')
# print('2. Периметр')
# oper = int(input('Выберите операцию: '))
#
# if oper == 1:
#     print(f"Площадь окружности равна {diam * diam / 4}π")
# elif oper == 2:
#     print(f"Периметр окружности равен {diam}π")
# else:
#     print('Такая операция не опеределена')



# Задание 3
# price = int(input('Введите стоимость приставки: '))
# amount = int(input('Введите количество приставок: '))
# off = int(input('Введите размер скидки: '))
#
# print('1. Общая стоимость заказа')
# print('2. Стоимость одной приставки со скидкой')
# oper = int(input('Выберите операцию: '))
#
# if oper == 1:
#     print(f"{(price -(price * (off/100))) * amount}")
# elif oper == 2:
#     print(f"{price -(price * (off/100))}")
# else:
#     print('Такая операция не опеределена')


# Задание 4
# size = int(input('Введите размер файла в гигабайтах: '))
# speed = int(input('Введите скорость интернет соединение в битах: '))
#
# print('1. Часы')
# print('2. Минуты')
# print('3. Секунды')
# oper = int(input('Выберите операцию: '))
#
# if oper == 1:
#     print(f"Файл скачается за {size * 8589934592 / speed * 3600} часов")
# elif oper == 2:
#     print(f"Файл скачается за {size * 8589934592 / speed * 60} минут")
# elif oper == 3:
#     print(f"Файл скачается за {size * 8589934592 / speed} секунд")
# else:
#      print('Такая операция не опеределена')


# Задание 5
# time  = int(input('Введите время суток: '))
#
# if 0 <= time < 6:
#     print('Good Night')
# elif 6 <= time < 13:
#     print('Good Morning')
# elif 13 <= time < 17:
#     print('Good Day')
# elif 17 <= time < 24:
#     print('Good Evening')
# else:
#     print('???')



