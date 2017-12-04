package main

import "fmt"

func main() {
	var mounth_map map[int]string = map[int]string{
		1:  "January",
		2:  "February",
		3:  "March",
		4:  "April",
		5:  "May",
		6:  "June",
		7:  "July",
		8:  "August",
		9:  "September",
		10: "October",
		11: "November",
		12: "December",
	}
	var m int
	fmt.Scan(&m)

	month, _ := mounth_map[m]

	// switch m {
	// case 1:
	// 	month = "January"
	// case 2:
	// 	month = "February"
	// case 3:
	// 	month = "March"
	// case 4:
	// 	month = "April"
	// case 5:
	// 	month = "May"
	// case 6:
	// 	month = "June"
	// case 7:
	// 	month = "July"
	// case 8:
	// 	month = "August"
	// case 9:
	// 	month = "September"
	// case 10:
	// 	month = "October"
	// case 11:
	// 	month = "November"
	// case 12:
	// 	month = "December"
	// default:
	// 	month = "URI is the best!"
	// }

	fmt.Println(month)

}
