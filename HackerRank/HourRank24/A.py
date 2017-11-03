def main():
    numbers = "0123456789"
    lower_case = "abcdefghijklmnopqrstuvwxyz"
    upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    special_characters = "!@#$%^&*()-+"

    n = int(input())
    pw = input()

    cont = [1, 1, 1, 1]
    for c in pw:
        if numbers.find(c) != -1:
            cont[0] = 0
        elif lower_case.find(c) != -1:
            cont[1] = 0
        elif upper_case.find(c) != -1:
            cont[2] = 0
        elif special_characters.find(c) != -1:
            cont[3] = 0

    qtd = 0
    for varx in cont:
        if varx == 1:
            qtd += 1

    print(max(6 - n, qtd))

if __name__ == "__main__":
    main()
