package main

import (
	"fmt"
)

func matrixReshape(nums [][]int, r int, c int) [][]int {
	if (len(nums)<=0 || len(nums[0])<=0) {
		return nums
	}
	rr := len(nums)
	cc := len(nums[0])
	if (rr*cc != r*c) {
		return nums
	}
	ret := make([][]int, r)
	count := 0
	for i := range ret {
		ret[i] = make([]int, c)
		for j := range ret[i] {
			ret[i][j] = nums[count/cc][count%cc]
			count++
		}
	}
	return ret
}

func test1() {
	v := [][]int{{1,2}, {3,4}, {5,6}}
	fmt.Println(v)
	ret := matrixReshape(v, 2, 3)
	fmt.Println(ret)
}


func main() {
	test1()
}
