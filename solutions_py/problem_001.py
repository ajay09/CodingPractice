def twoSums(nums, target):
    numHash = set()
    for n in nums:
        leftover = target - n
        if leftover in numHash:
            return True
        else:
            numHash.add(n)

    return False



assert not twoSums([], 17)
assert twoSums([10, 15, 3, 7], 17)
assert not twoSums([10, 15, 3, 4], 17)
assert not twoSums([10, 15, 3, 4], 6)