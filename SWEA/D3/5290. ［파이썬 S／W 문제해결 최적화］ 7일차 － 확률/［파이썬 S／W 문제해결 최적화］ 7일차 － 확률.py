T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
    n = int(input())
    a = 1
    l = 10
    for i in range(n):
        a *= l
        l -= 1
    b = pow(10, n)
    
    print(f'#{test_case} {a / b:.5f}')