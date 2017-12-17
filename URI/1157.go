package main

import "fmt"
import "sort"

func main() {
	var n int
	var divs []int

	fmt.Scan(&n)

	for i := 1; i*i <= n; i++ {
		if n%i == 0 {
			divs = append(divs, i)
			divs = append(divs, n/i)
		}
	}

	sort.Ints(divs)

	for _, v := range divs {
		fmt.Println(v)
	}
}
