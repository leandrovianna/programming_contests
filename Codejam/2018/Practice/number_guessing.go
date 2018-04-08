//CodeJam 2018 Practice - Number Guessing
package main

import "fmt"
import "os"
import "bufio"

func main() {
	var t, a, b, n, q int
	var resp string

	wrt := bufio.NewWriter(os.Stdout)

	for fmt.Scan(&t); t > 0; t-- {
		fmt.Scan(&a, &b)
		a++

	outer:
		for fmt.Scan(&n); n > 0; n-- {
			q = (b-a)/2 + a
			fmt.Println(q)

			// flush stdout, see wrt declaration
			if err := wrt.Flush(); err != nil {
				panic(err)
			}

			fmt.Scan(&resp)

			switch resp {
			case "CORRECT":
				break outer
			case "TOO_SMALL":
				a = q + 1
			case "TOO_BIG":
				b = q - 1
			case "WRONG_ANSWER":
				return
			}
		}

		if n == 0 {
			fmt.Scan(&resp)
			if resp == "WRONG_ANSWER" {
				return
			}
		}
	}
}
