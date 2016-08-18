package main

import "fmt"
import "math/rand"
import "time"
import "os"
import "strconv"

const days = 365

//TestYear is class for mandom test year for birthdays
type TestYear struct {
	friends           int
	birthdaysInOneDay int

	r *rand.Rand
}

func (testYear *TestYear) test() int {
	var boxes [days]int
	for i := 0; i < testYear.friends; i++ {
		randomday := testYear.r.Intn(days)
		boxes[randomday]++
		if boxes[randomday] == testYear.birthdaysInOneDay {
			return 1
		}
	}
	return 0
}

//NewTestYear is constructor for TestYear
func NewTestYear() *TestYear {
	testYear := new(TestYear)
	testYear.friends = 400
	testYear.birthdaysInOneDay = 5

	randSource := rand.NewSource(time.Now().UnixNano())
	testYear.r = rand.New(randSource)
	return testYear
}

func main() {
	ty := NewTestYear()
	interations, error := strconv.Atoi(os.Args[1])
	if error != nil {
		fmt.Print(error)
		return
	}
	var successCount int
	for i := 0; i < interations; i++ {
		successCount += ty.test()
	}
	probability := float64(successCount) / float64(interations)
	fmt.Printf("probability [%f]\n", probability)
}
