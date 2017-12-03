
def main():
    """TODO: Docstring for main.
    :returns: TODO

    """
    n = int(input()) 
    notas_qtd = {100:0, 50:0, 20:0, 10:0, 5:0, 2:0, 1:0};

    m = n
    notas = notas_qtd.keys() 
    notas = sorted(list(notas))
    notas.reverse()
    for k in notas:
        while m-k >= 0:
            notas_qtd[k] += 1
            m = m - k

    print(n)
    for k in notas:
        v = notas_qtd[k]
        lh = '{:.2f}'.format(k).replace('.',',')
        print('{} nota(s) de R$ {}'.format(v, lh))


if __name__ == "__main__":
    main()
