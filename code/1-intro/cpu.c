#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <assert.h>

double getTime()
{
    struct timeval t;
    int rc = gettimeofday(&t,NULL);
    //printf("the value of rc is : %d\n",rc);
    assert(rc==0);
    return (double)t.tv_sec+(double)t.tv_usec/1e6;
}

void Spin(int howlong)
{
    double t = getTime();
    while ((getTime()-t)<(double)howlong);

}

int main(int argc, char *argv[])
{
    printf("value of argc :%d\n",argc);
    if (argc != 3) {
	fprintf(stderr, "usage: cpu <string>\n");
	exit(1);
    }
    char *str = argv[1];

    while (1) {
	printf("%s\n", str);
    printf("%s\n", argv[2]);
	Spin(1);
    }
    return 0;
}

