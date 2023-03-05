import random


def negative_sum(input_list: list):          #Сумма отрицательных чисел
    result = 0

    for i in range(len(input_list)):
        if input_list[i] < 0:
            result = result + input_list[i]

    return result


def even_sum(input_list: list):          #Сумма четных чисел
    result = 0

    for i in range(len(input_list)):
        if input_list[i] % 2 == 0:
            result = result + input_list[i]

    return result


def odd_sum(input_list: list):           #Сумма нечетных чисел
    result = 0

    for i in range(len(input_list)):
        if input_list[i] % 2 == 1:
            result = result + input_list[i]

    return result


def three(input_list: list):             #Произведение чисел с индексом, кратным 3
    result = 1

    for i in range(len(input_list)):
        if i % 3 == 0:
            result = result * input_list[i]

    return result


def minmax_mlt(input_list: list):            #Произведение чисел между наименьшим и наибольшим значением списка
    minimum = input_list[0]
    maximum = input_list[0]
    result = 1

    for i in range(len(input_list)):
        if input_list[i] < minimum:
            minimum = input_list[i]
        elif maximum < input_list[i]:
            maximum = input_list[i]

    while minimum <= maximum:
        result = result * minimum
        minimum = minimum + 1

    return result


def only_even(input_list: list):             #Список, содержащий только четные элементы исходного списка
    result = []

    for i in range(len(input_list)):
        if input_list[i] % 2 == 0:
            result.append(input_list[i])

    return result


def only_odd(input_list: list):            #Список, содержащий только нечетные элементы исходного списка
    result = []

    for i in range(len(input_list)):
        if input_list[i] % 2 == 1:
            result.append(input_list[i])

    return result


def only_negative(input_list: list):            #Список, содержащий только отрицательные элементы исходного списка
    result = []

    for i in range(len(input_list)):
        if input_list[i] < 0:
            result.append(input_list[i])

    return result


def only_positive(input_list: list):            #Список, содержащий только положительные элементы исходного списка
    result = []

    for i in range(len(input_list)):
        if input_list[i] > 0:
            result.append(input_list[i])

    return result


nums = [random.randint(-10, 10) for i in range(5)]
print(f"Исходный массив: {nums}\n")

print(f"Сумма отрицательных чисел в списке: {negative_sum(nums)}")
print(f"Сумма четных чисел в списке: {even_sum(nums)}")
print(f"Сумма нечетных чисел в списке: {odd_sum(nums)}")
print(f"Произведение элементов списка с индексом, кратным 3: {three(nums)}")
print(f"Произведение чисел между наименьшим и наибольшим элементами списка: {minmax_mlt(nums)}")
print(f"Список, содержащий только четные элементы исходного списка: {only_even(nums)}")
print(f"Список, содержащий только нечетные элементы исходного списка: {only_odd(nums)}")
print(f"Список, содержащий только отрицательные элементы исходного списка: {only_negative(nums)}")
print(f"Список, содержащий только положительные элементы исходного списка: {only_positive(nums)}")


