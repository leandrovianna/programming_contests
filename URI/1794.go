package main

import "fmt"

func main() {
	var n, la, lb, sa, sb int

	fmt.Scan(&n, &la, &lb, &sa, &sb)

	if la <= n && n <= lb && sa <= n && n <= sb {
		fmt.Println("possivel")
	} else {
		fmt.Println("impossivel")
	}
}
