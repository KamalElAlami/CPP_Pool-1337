- [x] check other cases 
- [x] skip first line of the input.txt 
- [x] leakss from split
- [x] throw error when space between numbers btc
- [x] rpn crash when 2 3 ++
- [x] pmergeme segv in one number and it doesnt sort 3 numbers that is sorted in descending order
- [ ] parsing error when you give all numbers in one arg
  
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


AddressSanitizer:DEADLYSIGNAL
=================================================================
==54654==ERROR: AddressSanitizer: SEGV on unknown address 0x000000000000 (pc 0x000109cee308 bp 0x7ffee5f2eb30 sp 0x7ffee5f2eb00 T0)
==54654==The signal is caused by a READ memory access.
==54654==Hint: address points to the zero page.
    #0 0x109cee308 in std::__1::deque<int, std::__1::allocator<int> >::operator[](unsigned long)+0xa8 (PmergeMe:x86_64+0x10001e308)
    #1 0x109cee8b1 in createMainAndPendDeque(std::__1::deque<std::__1::pair<int, int>, std::__1::allocator<std::__1::pair<int, int> > >&, std::__1::deque<int, std::__1::allocator<int> >&, std::__1::deque<int, std::__1::allocator<int> >&, int)+0x4f1 (PmergeMe:x86_64+0x10001e8b1)
    #2 0x109cf1f8b in sortWithDeque(std::__1::deque<int, std::__1::allocator<int> >&)+0x88b (PmergeMe:x86_64+0x100021f8b)
    #3 0x109cd24d2 in main+0x1b2 (PmergeMe:x86_64+0x1000024d2)
    #4 0x7fff6b84acc8 in start+0x0 (libdyld.dylib:x86_64+0x1acc8)

==54654==Register values:
rax = 0x0000000000000000  rbx = 0x00007ffee5f2ed60  rcx = 0x0000100000000000  rdx = 0x0000100000000000  
rdi = 0x00007ffee5f2f120  rsi = 0x0000100000000000  rbp = 0x00007ffee5f2eb30  rsp = 0x00007ffee5f2eb00  
 r8 = 0x0000621000005108   r9 = 0x4443637ec1de0089  r10 = 0x000000010aa51db8  r11 = 0xfffffffffffffff0  
r12 = 0x00007ffee5f2ecf0  r13 = 0x00007ffee5f2ed40  r14 = 0x00007ffee5f2ecb0  r15 = 0x00007ffee5f2ecd0  
AddressSanitizer can not provide additional info.
SUMMARY: AddressSanitizer: SEGV (PmergeMe:x86_64+0x10001e308) in std::__1::deque<int, std::__1::allocator<int> >::operator[](unsigned long)+0xa8
==54654==ABORTING
[1]    54654 abort      ./PmergeMe 1 2 3

