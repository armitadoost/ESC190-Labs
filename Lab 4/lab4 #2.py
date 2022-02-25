# Lab 4 -- Question 2

def find_lowest_index(L, e):
    first = 0
    last = len(L)-1
    index = -1
    count = -1
    while (first <= last) and (count != 0):
        mid = (first+last)//2

        if L[mid] == e:
            index = mid
            count += 2
            last -= 1
        else:
            if count != -1:
                count = 0
            if e < L[mid]:
                last = mid -1
            else:
                first = mid +1
    return index
# Complexity is O(log n) as it uses Binary Search method



def find_highest_index(L, e):
    first = 0
    last = len(L)-1
    index = -1
    count = -1
    while (first <= last) and (count != 0):
        mid = (first+last)//2

        if L[mid] == e:
            index = mid
            count += 2
            first += 1
        else:
            if count != -1:
                count = 0
            if e < L[mid]:
                last = mid -1
            else:
                first = mid +1
    return index



print(find_lowest_index([1,2,3,4,5,5,5,5,5,5,5,5,6,6,6], 5))
print(find_highest_index([1,2,3,4,5,5,5,5,5,5,5,6,6,6], 5))