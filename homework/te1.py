import random

# 10000개의 랜덤 숫자를 생성하여 test.txt 파일에 저장
with open('test.txt', 'w') as f:
    for _ in range(10000):
        f.write(f"{random.randint(1, 100000)}\n")
