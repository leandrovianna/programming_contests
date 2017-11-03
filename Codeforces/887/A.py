# Codeforces - Div. 64 - 887A
def main():
    n = input()

    j = 0
    for i in range(len(n)):
        if n[i] == '1':
            j = i  
            break
    else:
        print('no')
        return

    cont = 0
    for i in range(j, len(n)):
        if n[i] == '0':
            cont = cont + 1

    if cont >= 6:
        print('yes')
    else:
        print('no')

if __name__ == "__main__":
    main()
