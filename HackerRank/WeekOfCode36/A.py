# HackerRank - Acid Naming - acid-naming

def acidNaming(acid_name):
    if acid_name.endswith('ic'):
        if acid_name.startswith('hydro'):
            return 'non-metal acid'
        else:
            return 'polyatomic acid'
    else:
        return 'not an acid'

if __name__ == "__main__":
    n = int(input().strip())
    for a0 in range(n):
        acid_name = input().strip()
        result = acidNaming(acid_name)
        print(result)
