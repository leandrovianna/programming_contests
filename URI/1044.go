//URI Online Judge - Multiplos - 1044
package main

import "fmt"

func main() {
	a, b := 0, 0
	fmt.Scan(&a, &b)

	if a > b {
		a, b = b, a
	}

	if b % a == 0 {
		fmt.Println("Sao Multiplos")
	} else {
		fmt.Println("Nao sao Multiplos")
	}
}
