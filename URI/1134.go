package main

import "fmt"

func main() {
	var x, alcool, gasolina, diesel int

	alcool = 0
	gasolina = 0
	diesel = 0

	for {
		fmt.Scan(&x)

		switch x {
		case 1:
			alcool++
		case 2:
			gasolina++
		case 3:
			diesel++
		case 4:
			goto end
		}

	}
end:

	fmt.Println("MUITO OBRIGADO")
	fmt.Printf("Alcool: %d\nGasolina: %d\nDiesel: %d\n",
		alcool, gasolina, diesel)
}
