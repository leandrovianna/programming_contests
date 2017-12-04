package main

import "fmt"

func main() {
	var salary, new_salary float64
	var percentage int

	fmt.Scan(&salary)

	if salary <= 400.00 {
		percentage = 15
	} else if salary <= 800.00 {
		percentage = 12
	} else if salary <= 1200.00 {
		percentage = 10
	} else if salary <= 2000.00 {
		percentage = 7
	} else {
		percentage = 4
	}

	factor := 1.0 + float64(percentage) / 100.00
	new_salary = salary * factor

	fmt.Printf("Novo salario: %.2f\n", new_salary)
	fmt.Printf("Reajuste ganho: %.2f\n", new_salary - salary)
	fmt.Printf("Em percentual: %d %%\n", percentage)
}
