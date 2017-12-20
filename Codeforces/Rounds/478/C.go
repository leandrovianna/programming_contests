//Codeforces - Table Decorations - 478C Div2
package main

import (
	"fmt"
)

func main() {
	var r, g, b int64

	fmt.Scan(&r, &g, &b)

	if b < r {
		b, r = b, r
	}

	if g < r {
		r, g = g, r
	}

	if b < g {
		g, b = b, g
	}

	var answer = int64(0)

	if r+g < b/2 {
		answer = r + g
	} else {
		answer = (r + g + b) / 3
	}

	fmt.Println(answer)
}
