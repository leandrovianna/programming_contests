def main():
    """
    Main
    """
    days = int(input())

    years = days // 365
    days = days % 365
    mouths = days // 30
    days = days % 30
    print('{} ano(s)'.format(years))
    print('{} mes(es)'.format(mouths))
    print('{} dia(s)'.format(days))


if __name__ == "__main__":
    main()
