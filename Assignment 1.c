#include <stdio.h>
#include <time.h>
int main () {
	time_t start, end;
	start = clock();
	//这里有个问题其实，为什么我这里用int就最后会导致没有输出，用char就没问题
	char prime[1000001];
	//将全部数先假设为质数，随后进行剔除
	for (int i = 0; i <= 1000000; i++) {
		prime[i] = 1;
	}
	//从2开始筛选,把不大于根号i的所有素数的倍数剔除，剩下的就是质数
	for (int i = 2; i <= 1000; i++) {
		if (prime [i]) {
			for (int j = i *i ; j <= 1000000; j = j + i) {
				prime [j] = 0;
			}
		}

	}
	//输出全部的质数
	for (int i = 2; i <= 1000000; i++) {
		if (prime [i]) {
			printf ("%d\n", i);
		}
	}
	end = clock(); // 获取结束时间
	printf("用了 %d 毫秒\n", (int)(end - start));

	return 0;
}
