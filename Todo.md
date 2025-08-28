- [x] check other cases 
- [x] skip first line of the input.txt 
- [x] leakss from split
- [x] throw error when space between numbers btc
- [x] rpn crash when 2 3 ++
- [x] pmergeme segv in one number and it doesnt sort 3 numbers that is sorted in descending order
- [x] parsing error when you give all numbers in one arg
- [x] Your output: Error: invalid delimiter syntax Expected: Error: bad input => 2001-42-42
- [ ] print running time PmergeME

  
# Ford-Johnson Algorithm

## What is Ford-Johnson Algorithm
Ford-Johnson or merge-insertion sort Algorithm is a Comparison algorithm that is uses fewer comparisons in the worst case

## How Ford-Johnson Does its work
**Step I: Pair & Sort**

- Make Pairs From Your Numbers
- Sort each pair (big number to the right)
- if odd number left remains alone
- This Step Should Be recursive (pair, pair of pairs, etc..)

**Step II: Make 2 Lists**

- **Main Chain**: smallest from first pair + all the big numbers
- **Pend**: all the small numbers left + odd number
  
**Step III: Insert Back**

- Take numbers From pend
- Insert them into main using binary search
- Use Jacobsthal Sequence

