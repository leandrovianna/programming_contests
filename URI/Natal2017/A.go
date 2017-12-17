//URI - Tempo do Duende - A
package main

import "fmt"

func main() {
	var n int
	var x, y int
	fmt.Scan(&n, &x, &y)

	if x+y <= n {
		fmt.Println("Farei hoje!")
	} else {
		fmt.Println("Deixa para amanha!")
	}
}
