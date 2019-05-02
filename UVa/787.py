"""
UVA Online Judge - Maximum Sub-sequence Product - 787
"""


def main(nums):
    ans = nums[0]
    for i in range(len(nums)):
        x = 1
        for j in range(i, len(nums)):
            x *= nums[j]
            ans = max(ans, x)

    print(ans)


if __name__ == "__main__":
    nums = []
    while True:
        try:
            nums.extend(map(int, input().split()))

            if nums[len(nums)-1] == -999999:
                nums.pop()
                main(nums)
                nums = []

        except EOFError:
            break
