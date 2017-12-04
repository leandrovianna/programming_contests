//URI - Par ou Impar - 1074
package main

import "fmt"

func main() {
	var n int
	var x int64

	fmt.Scan(&n)

	for i := 0; i < n; i++ {
		fmt.Scan(&x)

		if x == 0 {
			fmt.Println("NULL")
		} else {

			if x%2 == 0 {
				fmt.Print("EVEN")
			} else {
				fmt.Print("ODD")
			}

			if x < 0 {
				fmt.Print(" NEGATIVE\n")
			} else {
				fmt.Print(" POSITIVE\n")
			}
		}
	}
}
