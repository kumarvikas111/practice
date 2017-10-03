#!/usr/bin/python


def quicksort(mylist,start,end):
	if start < end:
		pivitol = partition(mylist,start,end)
		
		quicksort(mylist,start,pivitol-1)
		quicksort(mylist,pivitol+1,end)

	return mylist

"""
algorithm partition(A, lo, hi) is
    pivot := A[hi]
    i := lo - 1    
    for j := lo to hi - 1 do
        if A[j] < pivot then
            i := i + 1
            swap A[i] with A[j]
    if A[hi] < A[i + 1] then
        swap A[i + 1] with A[hi]
    return i + 1
"""

def partition(mylist,start,end):
	i = (start -1)
	pivitol = mylist[end]
	for j in range(start,end):
#		if mylist[j] <= pivitol:
		"""Asecding order """
		if mylist[j] >= pivitol:
			"""Decending order """
			i = i+1
#			swap(mylist[i],mylist[j])
			mylist[i],mylist[j] = mylist[j],mylist[i]
#	if mylist[end] < mylist[i+1]:
		"""Asending order"""
	if mylist[end] > mylist[i+1]:
		"""Desending order"""
#		swap(mylist[i+1],mylist[end]
		mylist[i+1],mylist[end] = mylist[end],mylist[i+1]
	return (i+1)
	

if __name__ == "__main__":
	print("Welcome to python world !!!")
	mylist = [1,2,7,3,-1,-3,6,8,45,-42]
	print mylist
	print	quicksort(mylist,0,len(mylist) -1)
