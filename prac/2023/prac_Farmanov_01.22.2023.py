def task1(lst):
    str_len = len(lst[0])
    result = str()

    for i in range(len(lst)):
        if len(lst[i]) > str_len:
            str_len = len(lst[i])
            result = lst[i]

    return f"Самая длинная строка в списке - {result}"


def task2(lst):
    len_lst = list()
    factorial_lst = list()
    factorial_lst_sum = 0

    for i in range(len(lst)):
        len_lst.append(len(lst[i]))

    for i in range(len(len_lst)):
        result = 1

        for j in range(1, len_lst[i] + 1):
            result = result * j

        factorial_lst.append(result)

    for i in range(len(factorial_lst)):
        factorial_lst_sum = factorial_lst_sum + factorial_lst[i]

    return f"Среднеарифметическое факториалов длин каждого из элементов исходного списка - {factorial_lst_sum / len(factorial_lst)}"


input_list = ['Kto', 'Ti', 'Voin']
print(f"Исходный список - {input_list}\n")

print(task1(input_list))
print(task2(input_list))


