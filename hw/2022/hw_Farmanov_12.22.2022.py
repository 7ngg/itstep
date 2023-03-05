task = int(input('Выберите задание: '))

match task:
    case 1:
        num0 = int(input('Введите число: '))
        sum = 0
        count = 0

        while num0 - 0.1 > 0:
            sum = sum + (num0 % 10)
            num0 = (num0 - (num0 % 10)) / 10
            count += 1

        print(f"Среднеарифметическое всех цифр числа равно {sum / count}")


    case 2:
        num0 = int(input('Введите число: '))

        while num0 - 0.1 > 0:
            num0_last_digit = num0 % 10
            num0_last_digit_backup = num0 % 10
            last_digit_factorial = 1

            while num0_last_digit != 0:
                last_digit_factorial = num0_last_digit * last_digit_factorial
                num0_last_digit -= 1

            print(f"{num0_last_digit_backup}! = {last_digit_factorial}")

            num0_last_digit = num0_last_digit_backup
            num0 = int((num0 - num0_last_digit) / 10)


    case 3:
        num0 = int(input('Введите число: '))
        multiplier = 10

        result = num0 % 100 // 10
        result_last_digit = num0 % 10
        num0 = int((num0 - (num0 % 100)) / 100)

        while num0 // 10 != 0:
            last_digit = num0 % 10
            result = result * multiplier + last_digit
            num0 = int((num0 - last_digit) / 10)


        print(str(num0) + str(result) + str(result_last_digit))