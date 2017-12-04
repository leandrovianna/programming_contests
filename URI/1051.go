package main

import "fmt"

func main() {
	var salary float64
	fmt.Scan(&salary)

	var value = float64(0.0)

	if salary > 2000.00 {
		if salary <= 3000.00 {
			salary -= 2000.00
			value = salary * 0.08
		} else if salary <= 4500.00 {
			salary -= 3000.00
			value = salary*0.18 + 80.0
		} else {
			salary -= 4500.00
			value = salary*0.28 + 270.0 + 80.0
		}

		fmt.Printf("R$ %.2f\n", value)
	} else {
		fmt.Println("Isento")
	}
}
