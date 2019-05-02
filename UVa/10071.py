"""
UVA - Back to High School Physics
"""


def main(v, t):
    print(v * t * 2)

if __name__ == "__main__":
    cont = True
    while cont:
        try:
            v, t = map(int, input().split())
            main(v, t)
        except EOFError:
            cont = False
