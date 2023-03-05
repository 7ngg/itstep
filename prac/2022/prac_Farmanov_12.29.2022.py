# Задание 1
# line = input('Введите строку: ')
#
# for i in range(1, len(line) + 1):
#     print(line[-i], end = '')

# Задание 2
# line = input('Введите строку: ')
# letter_count = 0
# num_count = 0
#
# for i in range(len(line)):
#     if line[i].isalpha():
#         letter_count += 1
#     elif line[i].isnumeric():
#         num_count += 1
#
# print(f"Количество букв в строке - {letter_count}")
# print(f"Количество цифр в строке - {num_count}")


# Задание 3
# line = input('Введите строку: ')
# sym = input('Введите символ для поиска: ')
#
# print(line.count(sym))


# Задание 4
# line = input('Введите строку: ')
# word = input('Введите слово для поиска: ')
#
# print(line.count(word))


# Задание 5
# line = input('Введите строку: ')
# search_word = input('Введите слово для поиска: ')
# replace_word = input('Введите слово для замены: ')
#
# replaced_line = line.replace(search_word, replace_word)
# print(replaced_line)


# Поменять все четные и нечетные индексы местами, ноль оставить на месте
# line = input('Введите строку: ')
# word = list()

# start = 1
# end = int(len(line) / 2)

# for i in range(len(line)):
# 	word.append(line[i])

# for i in range(start, end + 1):
# 	word[i], word[-i] = word[-i], word[i]
# print(''.join(word))
