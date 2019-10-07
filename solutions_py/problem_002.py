def productExceptSelf(nums):
    numsLength = len(nums)
    leftProducts, rightProducts = [0]*numsLength, [0]*numsLength
    
    leftProducts[0] = 1
    for i in range(1, numsLength):
        leftProducts[i] = nums[i-1] * leftProducts[i-1]

    # print(leftProducts)
    rightProducts[numsLength - 1] = 1
    for i in reversed(range(numsLength - 1)):
        rightProducts[i] = nums[i+1] * rightProducts[i+1]
    # print(rightProducts)

    result = [0] * numsLength
    for i in range(numsLength):
        result[i] = leftProducts[i] * rightProducts[i]

    return result


print(productExceptSelf([3,4,5]))
print(productExceptSelf([1,2,3,4,5]))