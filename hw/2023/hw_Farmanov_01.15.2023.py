import random

def insertion_sort(lst):
    for i in range(1, len(lst)):
        value = lst[i]
        j = i-1

        while j >= 0 and value < lst[j]:
            lst[j + 1] = lst[j]
            j -= 1
        lst[j + 1] = value

    return lst


def selection(lst):
    for i in range(len(lst)):
        min_value = i

        for j in range(i, len(lst)):
            if lst[min_value] > lst[i]:
                min_value = i

        lst[i], lst[min_value] = lst[min_value], lst[i]

    return lst

nums = [random.randint(-10, 10) for i in range(10)]

print(f"Исходный массив - {nums}")
print(f"Insertion sort - {insertion_sort(nums)}")
print(f"Selection sort - {selection(nums)}")
