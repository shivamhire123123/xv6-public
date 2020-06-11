#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

void matrixmul() {
	int a[3][3] = {
		{ 1, 2, 3 },
		{ 4, 5, 6 },
		{ 7, 8, 9 }
	},
	b[3][3] = {
		{ 9, 8, 7 },
		{ 6, 5, 4 },
		{ 3, 2, 1 }
	}, c[3][3] __attribute__((unused));;

	int sum = 0;

	for(;;) {
		for ( int i = 0 ; i < 3 ; i++ ) {
            for ( int j = 0 ; j < 3 ; j++ ) {
                for ( int k = 0 ; k < 3 ; k++ ) {
                    sum = sum + a[i][k]*b[k][j];
                }
                c[i][j] = sum;
                sum = 0;
            }
        }
	}
}

int
main(int argc, char *argv[]) {
	int pid;
	pid = fork();
	if(pid != 0) {
		matrixmul();
	}
	else {
		settickets(5);
		matrixmul();
	}
	exit();
}
