#!/bin/python3

if __name__ == '__main__':
    n = int(input().strip())
    l = []
    for _ in range(n):
       args = input().strip().split() 
       
       command = args[0]
       if command == 'insert':
           l.insert(int(args[1]), int(args[2]))
       elif command == 'print':
           print (l)
       elif command == 'remove':
           l.remove(int(args[1]))
       elif command == 'append':
           l.append(int(args[1]))
       elif command == 'sort':
           l.sort()
       elif command == 'pop':
           l.pop()
       elif command == 'reverse':
           l.reverse()

