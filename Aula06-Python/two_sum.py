
def main(): 
    s = Solution()
    result = s.twoSum([2, 7, 11, 15], 9)
    print(result)

    result1 = s.twoSum([3, 2, 4], 6)
    print(result1)

class Solution:
    def twoSum(self, nums, target): 
        for i in range(len(nums)): 
            for j in range(len(nums)):
                if j != i: 
                    if nums[i] + nums[j] == target: 
                        return [i, j]
                    
            
if __name__ == '__main__': 
    main()

