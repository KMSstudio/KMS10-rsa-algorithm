/*
2019입학 10619 20119 30918강명석
이 프로그램은 강명석(본인, 16)이 만들었음을 증명합니다.
오류와 비정상적인 가동은 tomskang@naver.com으로 보내주시면 감사하겠습니다.

settings
  Project - Properties - C/C++ - General - SDL checks | No(sdl-)
	// if you don't use scanf() in source, you should use SDL checks
  +other visual studio 2019 basics setting

precautions
  This valueable use stack for substitution operator. 

KMS10_RSA_algorithm_11_2_WaterBottle_progect
made by 2020 KMS studio(Myung Seok Kang)
20year 07m 27d 19h 00m 23s ~ 20year m d h m s
Copyright 2020 KMS studio all rights reserved.
thanks for	Kyung Taek Park
			Si Hyun Kim
*/

//36.90 micro second per run (lowest value)
//17.75 milli second per run (mean value in Arduino)

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#include "KMS10.h"

#define PRIME_DIGIT	13 // <= difine POINT;

int main(void) {
	char prime1[] = "1001100000111010110110001100011001";
	char prime2[] = "1001100011000001110000100111101111";

	struct KMS_RSA_VLABL Public, Private;
	struct KMS_RSA_VLABL n;
	__int64 e;

	struct KMS_RSA_VLABL p;
	struct KMS_RSA_VLABL q;
	long long K;

	clock_t st;

	printf("start test case : ");
	scanf("%lld", &K);
	st = clock(NULL);
	for (; 1; K++) {
		srand((unsigned int)K);
		if (!(K % 100)) {
			printf("No ERROR FOUND ::: Test repeat time = %lld\n", K);
			printf("%dms used\n", (long)(clock(NULL) - st));
		}
		OP_SETUP(&Public, &Private);
		//set(prime1, &p);
		//set(prime2, &q);
		INF_RAND(&p, 8192);
		INF_RAND(&q, 8192);
		OP_1(&n, &Public, &p, &q);
		do {
			OP_2(&e, MIN(PRIME_DIGIT, POINT / 2));
		} while (!OP_3(&Private, &n, e));
		if (RSA_KEY_TESTER(&e, &Private, &n, !(K % 10000))) { return 0; }
	}
	return 0;
}